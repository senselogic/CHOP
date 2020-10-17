// -- PRAGMAS

#pragma once

// -- IMPORTS

#include <fstream>
#include <gtkmm.h>
#include <iostream>

// -- CONSTANTS

#define STD_FSTREAM_Trunc STD_FSTREAM::trunc
#define STD_FSTREAM_Binary STD_FSTREAM::binary

// -- TYPES

#define STD_STRING std::string
#define STD_VECTOR std::vector
#define STD_FSTREAM std::fstream
#define STD_IFSTREAM std::ifstream
#define STD_OFSTREAM std::ofstream

// -- FUNCTIONS

#define STD_Sort std::sort
#define STD_GetString std::to_string
#define STD_GetLong std::stol

// ~~

inline bool STD_HasPrefix(
    const std::string & text,
    const std::string & prefix
    )
{
    return
        text.size() >= prefix.size()
        && text.compare( 0, prefix.size(), prefix ) == 0;
}

// ~~

inline bool STD_HasSuffix(
    const std::string & text,
    const std::string & suffix
    )
{
    return
        text.size() >= suffix.size()
        && text.compare( text.size() - suffix.size(), suffix.size(), suffix ) == 0;
}
