#pragma once

#include <exception>

struct NotConnectedException : public std::exception
{
    const char* what() const throw ()
    {
        return "No MST";
    }
};