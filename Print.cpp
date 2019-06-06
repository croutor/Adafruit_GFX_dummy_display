#include "Print.h"
#include <cstdio>



Print::Print()
{

}

Print::~Print()
{

}

void Print::print(char* str)
{
    while(*str != 0)
    {
        write(*str);
        str++;
    }
}

size_t Print::write(const uint8_t *buffer, size_t size) {

    size_t n = 0;
    while (size--) {
        size_t ret = write(*buffer++);
        if (ret == 0) {
            // Write of last byte didn't complete, abort additional processing
            break;
        }
        n += ret;
    }
    return n;
}

