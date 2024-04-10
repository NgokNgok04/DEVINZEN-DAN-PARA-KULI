#ifndef CUSTOM_EXCEPTION_HPP
#define CUSTOM_EXCEPTION_HPP

#include <exception>
using namespace std;

struct MakananTidakSesuai : public exception
{
    const char *what() const throw()
    {
        return "Makanan tidak sesuai";
    }
};

#endif