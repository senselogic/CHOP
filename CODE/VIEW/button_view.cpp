// -- IMPORTS

#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/sigc.hpp"
#include "button_view.hpp"

// -- CONSTRUCTORS

BUTTON_VIEW::BUTTON_VIEW(
    ) :
    GTK_BOX( GTK_ORIENTATION_Horizontal ),
    SplitButton( "Split" ),
    SizeEntry(),
    SpacerLabel(),
    JoinButton( "Join" )
{
    SplitButton.set_sensitive( false );
    SizeEntry.set_placeholder_text( "Size" );
    SizeEntry.set_text( "5000000" );
    SizeEntry.set_sensitive( true );
    JoinButton.set_sensitive( false );

    pack_start( SplitButton, false, false );
    pack_start( SizeEntry, false, false );
    pack_start( SpacerLabel, true, true, 0 );
    pack_start( JoinButton, false, false );
}
