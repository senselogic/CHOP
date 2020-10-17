// -- IMPORTS

#include "../SYSTEM/glib.hpp"
#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/std.hpp"
#include "../MODEL/file_table.hpp"
#include "file_view.hpp"

// -- CONSTRUCTORS

FILE_VIEW::FILE_VIEW(
    ) :
    GTK_SCROLLED_WINDOW(),
    FileTable(),
    Frame(),
    VerticalBox( GTK_ORIENTATION_Vertical, 5 )
{
    Frame.add( VerticalBox );
    add( Frame );
}

// -- OPERATIONS

void FILE_VIEW::UpdateView(
    )
{
    int
        file_count,
        file_index;
    long
        input_file_byte_count;
    STD_STRING
        file_path;
    STD_VECTOR<GTK_WIDGET *>
        label_widget_vector;

    label_widget_vector = VerticalBox.get_children();

    for ( GTK_WIDGET * label_widget : label_widget_vector )
    {
        VerticalBox.remove( *label_widget );
    }

    file_count = FileTable.GetFileCount();

    for ( file_index = 0;
          file_index < file_count;
          ++file_index )
    {
        file_path = FileTable.FilePathVector[ file_index ];
        input_file_byte_count = FileTable.FileByteCountVector[ file_index ];

        VerticalBox.pack_start(
            *new GTK_LABEL( file_path + " : " + STD_GetString( input_file_byte_count ), GTK_ALIGN_Start ),
            false,
            false
            );
    }

    show_all();
}

// ~~

void FILE_VIEW::Clear(
    )
{
    FileTable.Clear();

    UpdateView();
}

// ~~

void FILE_VIEW::SetFiles(
    STD_VECTOR<GLIB_USTRING> file_uri_vector
    )
{
    FileTable.Clear();

    STD_Sort( file_uri_vector.begin(), file_uri_vector.end() );

    for ( const GLIB_USTRING & file_uri : file_uri_vector )
    {
        FileTable.AddFile( GLIB_GetFilePathFromUri( file_uri ) );
    }

    UpdateView();
}

// ~~

void FILE_VIEW::SplitFile(
    const FILE_TABLE & input_file_table,
    const long maximum_output_byte_count
    )
{
    FileTable.SplitFile( input_file_table, maximum_output_byte_count );
    UpdateView();
}

// ~~

void FILE_VIEW::JoinFiles(
    const FILE_TABLE & input_file_table
    )
{
    FileTable.JoinFiles( input_file_table );
    UpdateView();
}
