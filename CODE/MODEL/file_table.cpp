// -- IMPORTS

#include "../SYSTEM/std.hpp"
#include "file_table.hpp"

// -- FUNCTIONS


long GetFileByteCount(
    STD_STRING file_path
    )
{
    struct stat
        file_status;

    stat( file_path.c_str(), &file_status );

    return file_status.st_size;
}

// ~~

int GetSuffixCharacterCount(
    int output_file_count
    )
{
    int
        suffix_character_count;

    if ( output_file_count <= 26 )
    {
        return 1;
    }
    else
    {
        suffix_character_count = 0;
        --output_file_count;

        while ( output_file_count > 0 )
        {
            output_file_count /= 26;

            ++suffix_character_count;
        }

        return suffix_character_count;
    }
}

// ~~

STD_STRING GetFilePathSuffix(
    int output_file_index,
    int suffix_character_count
    )
{
    char
        digit_character;
    STD_STRING
        file_path_suffix;

    file_path_suffix = "";

    while ( suffix_character_count > 0 )
    {
        digit_character = "abcdefghijklmnopqrstuvwxyz"[ output_file_index % 26 ];
        file_path_suffix.insert( 0, 1, digit_character );
        output_file_index /= 26;
        --suffix_character_count;
    }

    return file_path_suffix;
}

// -- CONSTRUCTORS

FILE_TABLE::FILE_TABLE(
    ) :
    FilePathVector(),
    FileByteCountVector()
{
}

// -- INQUIRIES

int FILE_TABLE::GetFileCount(
    ) const
{
    return FilePathVector.size();
}

// -- OPERATIONS

void FILE_TABLE::Clear(
    )
{
    FilePathVector.clear();
    FileByteCountVector.clear();
}

// ~~

void FILE_TABLE::AddFile(
    const STD_STRING & file_path,
    const long input_file_byte_count
    )
{
    FilePathVector.push_back( file_path );
    FileByteCountVector.push_back( input_file_byte_count );
}

// ~~

void FILE_TABLE::AddFile(
    const STD_STRING & file_path
    )
{
    FilePathVector.push_back( file_path );
    FileByteCountVector.push_back( GetFileByteCount( file_path ) );
}

// ~~

void FILE_TABLE::SplitFile(
    const FILE_TABLE & input_file_table,
    const long maximum_output_byte_count
    )
{
    char
        * output_file_byte_array;
    long
        output_file_count,
        output_file_index,
        output_file_byte_count,
        output_file_byte_count_offset,
        input_file_byte_count,
        input_file_byte_count_offset,
        suffix_character_count;
    STD_IFSTREAM
        input_file_stream;
    STD_OFSTREAM
        output_file_stream;
    STD_STRING
        input_file_path,
        output_file_path;

    input_file_path = input_file_table.FilePathVector[ 0 ];
    input_file_byte_count = input_file_table.FileByteCountVector[ 0 ];

    Clear();

    output_file_count = ( input_file_byte_count + maximum_output_byte_count - 1 ) / maximum_output_byte_count;

    if ( output_file_count > 1 )
    {
        suffix_character_count = GetSuffixCharacterCount( output_file_count );

        input_file_byte_count_offset = output_file_count * maximum_output_byte_count - input_file_byte_count;
        input_file_stream.open( input_file_path, STD_FSTREAM_Binary );

        if ( input_file_stream.is_open() )
        {
            output_file_byte_array = new char[ maximum_output_byte_count ];

            for ( output_file_index = 0;
                  output_file_index < output_file_count;
                  ++output_file_index )
            {
                if ( output_file_index < output_file_count - 1 )
                {
                    output_file_byte_count_offset = rand() % ( input_file_byte_count_offset + 1 );
                    output_file_byte_count = maximum_output_byte_count - output_file_byte_count_offset;

                    input_file_byte_count_offset -= output_file_byte_count_offset;
                    input_file_byte_count -= output_file_byte_count;
                }
                else
                {
                    output_file_byte_count = input_file_byte_count;
                }

                output_file_path = input_file_path + GetFilePathSuffix( output_file_index, suffix_character_count );
                output_file_stream.open( output_file_path, STD_FSTREAM_Trunc | STD_FSTREAM_Binary );

                if ( output_file_stream.is_open() )
                {
                    input_file_stream.read( output_file_byte_array, output_file_byte_count );
                    output_file_stream.write( output_file_byte_array, output_file_byte_count );
                    output_file_stream.close();

                    FilePathVector.push_back( output_file_path );
                    FileByteCountVector.push_back( output_file_byte_count );
                }
            }

            delete[] output_file_byte_array;
            input_file_stream.close();
        }
    }
    else
    {
        FilePathVector.push_back( input_file_path );
        FileByteCountVector.push_back( input_file_byte_count );
    }
}

// ~~

void FILE_TABLE::JoinFiles(
    const FILE_TABLE & input_file_table
    )
{
    char
        * input_file_byte_array;
    int
        input_file_count,
        input_file_index,
        suffix_character_count;
    long
        input_file_byte_count,
        output_file_byte_count;
    STD_IFSTREAM
        input_file_stream;
    STD_OFSTREAM
        output_file_stream;
    STD_STRING
        input_file_path,
        output_file_path;

    Clear();

    input_file_count = input_file_table.FilePathVector.size();

    if ( input_file_count > 1 )
    {
        suffix_character_count = GetSuffixCharacterCount( input_file_count );

        output_file_path = input_file_table.FilePathVector[ 0 ];
        output_file_path = output_file_path.substr( 0, output_file_path.size() - suffix_character_count );
        output_file_byte_count = 0;
        output_file_stream.open( output_file_path, STD_FSTREAM_Trunc | STD_FSTREAM_Binary );

        if ( output_file_stream.is_open() )
        {
            for ( input_file_index = 0;
                  input_file_index < input_file_count;
                  ++input_file_index )
            {
                input_file_path = input_file_table.FilePathVector[ input_file_index ];
                input_file_byte_count = input_file_table.FileByteCountVector[ input_file_index ];
                input_file_stream.open( input_file_path, STD_FSTREAM_Binary );

                if ( input_file_stream.is_open() )
                {
                    input_file_byte_array = new char[ input_file_byte_count ];
                    input_file_stream.read( input_file_byte_array, input_file_byte_count );
                    output_file_stream.write( input_file_byte_array, input_file_byte_count );
                    output_file_byte_count += input_file_byte_count;
                    input_file_stream.close();

                    delete[] input_file_byte_array;
                }
            }

            output_file_stream.close();

            FilePathVector.push_back( output_file_path );
            FileByteCountVector.push_back( output_file_byte_count );
        }
    }
    else
    {
        FilePathVector = input_file_table.FilePathVector;
        FileByteCountVector = input_file_table.FileByteCountVector;
    }
}


























