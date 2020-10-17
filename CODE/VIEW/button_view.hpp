// -- PRAGMAS

#pragma once

// -- IMPORTS

#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/std.hpp"

// -- TYPES

struct BUTTON_VIEW : GTK_BOX
{
    // -- ATTRIBUTES

    GTK_BUTTON
        SplitButton;
    GTK_ENTRY
        SizeEntry;
    GTK_LABEL
        SpacerLabel;
    GTK_BUTTON
        JoinButton;

    // -- CONSTRUCTORS

    BUTTON_VIEW(
        );
};

