// -- IMPORTS

#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/sigc.hpp"
#include "../SYSTEM/std.hpp"
#include "application_view.hpp"

// -- CONSTRUCTORS

APPLICATION_VIEW::APPLICATION_VIEW(
    ) :
    GTK_WINDOW(),
    TargetEntryVector(),
    VerticalBox( GTK_ORIENTATION_Vertical, 5 ),
    InputFileView(),
    ButtonView(),
    OutputFileView()
{
    srand( time( nullptr ) );

    set_resizable( true );

    TargetEntryVector.push_back(
        GTK_TARGET_ENTRY( "text/uri-list", GTK_TARGET_OtherApplication, 0 )
        );

    set_title( "Chop" );
    set_default_size ( 800, 600 );
    set_border_width( 5 );

    add( VerticalBox );

    VerticalBox.pack_start( InputFileView, true, true );
    VerticalBox.pack_start( ButtonView, false, false );
    VerticalBox.pack_start( OutputFileView, true, true );

    InputFileView.drag_dest_set( TargetEntryVector, GTK_DESTINATION_DefaultAll, GDK_ActionCopy );
    InputFileView.signal_drag_data_received().connect(
        SIGC_FUNCTOR( *this, &APPLICATION_VIEW::HandleDragDataReceivedEvent )
        );

    ButtonView.SplitButton.signal_clicked().connect(
        SIGC_FUNCTOR( *this, &APPLICATION_VIEW::HandleSplitButtonClickedEvent )
        );

    ButtonView.JoinButton.signal_clicked().connect(
        SIGC_FUNCTOR( *this, &APPLICATION_VIEW::HandleJoinButtonClickedEvent )
        );

    show_all();
}

// -- INQUIRIES

long APPLICATION_VIEW::GetMaximumFileByteCount(
    ) const
{
    long
        maximum_file_byte_count;
    STD_STRING
        size_text;

    size_text = STD_STRING( ButtonView.SizeEntry.get_text() );

    maximum_file_byte_count = STD_GetLong( size_text );

    if ( STD_HasSuffix( size_text, "k" )
         || STD_HasSuffix( size_text, "k" ) )
    {
        maximum_file_byte_count *= 1024;
    }
    else if ( STD_HasSuffix( size_text, "m" )
              || STD_HasSuffix( size_text, "M" ) )
    {
        maximum_file_byte_count *= 1024 * 1024;
    }
    else if ( STD_HasSuffix( size_text, "g" )
              || STD_HasSuffix( size_text, "G" ) )
    {
        maximum_file_byte_count *= 1024 * 1024 * 1024;
    }

    return maximum_file_byte_count;
}

// -- OPERATIONS

void APPLICATION_VIEW::HandleDragDataReceivedEvent(
    const GLIB_REFERENCE<GDK_DRAG_CONTEXT> & drag_context,
    int x,
    int y,
    const GTK_SELECTION_DATA & selection_data,
    guint target_type,
    guint time
    )
{
    if ( target_type == 0 )
    {
        InputFileView.SetFiles( selection_data.get_uris() );
        OutputFileView.Clear();

        if ( InputFileView.FileTable.GetFileCount() == 1 )
        {
            ButtonView.SplitButton.set_sensitive( true );
            ButtonView.SizeEntry.set_sensitive( true );
            ButtonView.JoinButton.set_sensitive( false );
        }
        else if ( InputFileView.FileTable.GetFileCount() > 1 )
        {
            ButtonView.SplitButton.set_sensitive( false );
            ButtonView.SizeEntry.set_sensitive( false );
            ButtonView.JoinButton.set_sensitive( true );
        }
        else
        {
            ButtonView.SplitButton.set_sensitive( false );
            ButtonView.SizeEntry.set_sensitive( false );
            ButtonView.JoinButton.set_sensitive( false );
        }
    }
}

// ~~

void APPLICATION_VIEW::HandleSplitButtonClickedEvent(
    )
{
    long
        maximum_file_byte_count;

    maximum_file_byte_count = GetMaximumFileByteCount();

    if ( maximum_file_byte_count > 1024 )
    {
        OutputFileView.SplitFile(
            InputFileView.FileTable,
            maximum_file_byte_count
            );
    }
}

// ~~

void APPLICATION_VIEW::HandleJoinButtonClickedEvent(
    )
{
    OutputFileView.JoinFiles(
        InputFileView.FileTable
        );
}

