#pragma once

#include <exception>

struct InputMismatch : public std::exception
{
    const char* what() const throw ()
    {
        return "invalid input";
    }
};