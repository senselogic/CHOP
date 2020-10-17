// -- PRAGMAS

#pragma once

// -- IMPORTS

#include "../SYSTEM/glib.hpp"
#include "../SYSTEM/gtk.hpp"
#include "../SYSTEM/std.hpp"

// -- TYPES

struct FILE_TABLE
{
    // -- ATTRIBUTES

    STD_VECTOR<STD_STRING>
        FilePathVector;
    STD_VECTOR<long>
        FileByteCountVector;

    // -- CONSTRUCTORS

    FILE_TABLE(
        );

    // -- INQUIRIES

    int GetFileCount(
        ) const;

    // -- OPERATIONS

    void Clear(
        );

    // ~~

    void AddFile(
        const STD_STRING & file_path,
        const long input_file_byte_count
        );

    // ~~

    void AddFile(
        const STD_STRING & file_path
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
