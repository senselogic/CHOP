// -- PRAGMAS

#pragma once

// -- IMPORTS

#include "../SYSTEM/glib.hpp"
#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/std.hpp"
#include "../MODEL/file_table.hpp"

// -- TYPES

struct FILE_VIEW : GTK_SCROLLED_WINDOW
{
    // -- ATTRIBUTES

    FILE_TABLE
        FileTable;
    GTK_FRAME
        Frame;
    GTK_BOX
        VerticalBox;

    // -- CONSTRUCTORS

    FILE_VIEW(
        );

    // -- OPERATIONS

    void UpdateView(
        );

    // ~~

    void Clear(
        );

    // ~~

    void SetFiles(
        STD_VECTOR<GLIB_USTRING> file_uri_vector
        );

    // ~~

    void SplitFile(
        const FILE_TABLE & input_file_table,
        const long maximum_output_byte_count
        );

    // ~~

    void JoinFiles(
        const FILE_TABLE & input_file_table
        );
};
