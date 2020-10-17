// -- PRAGMAS

#pragma once

// -- IMPORTS

#include "../SYSTEM/glib.hpp"
#include "../SYSTEM/gdk.hpp"
#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/std.hpp"
#include "button_view.hpp"
#include "file_view.hpp"

// -- TYPES

struct APPLICATION_VIEW : GTK_WINDOW
{
    // -- ATTRIBUTES

    STD_VECTOR<GTK_TARGET_ENTRY>
        TargetEntryVector;
    GTK_BOX
        VerticalBox;
    FILE_VIEW
        InputFileView;
    BUTTON_VIEW
        ButtonView;
    FILE_VIEW
        OutputFileView;

    // -- CONSTRUCTORS

    APPLICATION_VIEW(
        );

    // -- INQUIRIES

    long GetMaximumFileByteCount(
        ) const;

    // -- OPERATIONS

    void HandleDragDataReceivedEvent(
        const GLIB_REFERENCE<GDK_DRAG_CONTEXT> & drag_context,
        int x,
        int y,
        const GTK_SELECTION_DATA & selection_data,
        guint target_type,
        guint time
        );

    // ~~

    void HandleSplitButtonClickedEvent(
        );

    // ~~

    void HandleJoinButtonClickedEvent(
        );
};
