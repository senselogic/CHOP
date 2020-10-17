// -- PRAGMAS

#pragma once

// -- TYPES

template <typename _OBJECT_>
struct HANDLE
{
    // -- ATTRIBUTES

    _OBJECT_
        * Object;

    // -- CONSTRUCTORS

    HANDLE(
        ) :
        Object( nullptr )
    {
    }

    // ~~

    HANDLE(
        _OBJECT_ * object
        ) :
        Object( object )
    {
    }

    // -- DESTRUCTOR

    ~HANDLE(
        )
    {
        if ( Object != nullptr )
        {
            delete Object;
        }
    }

    // -- OPERATORS

    void operator=(
        HANDLE & reference
        )
    {
        if ( Object != nullptr )
        {
            delete Object;
        }

        Object = reference.Object;
        reference.Object = nullptr;
    }

    // ~~

    void operator=(
        _OBJECT_ * object
        )
    {
        if ( Object != nullptr )
        {
            delete Object;
        }

        Object = object;
    }

    // ~~

    _OBJECT_ & operator*(
        )
    {
        return *Object;
    }

    // ~~

    _OBJECT_ * operator->(
        )
    {
        return Object;
    }
};
