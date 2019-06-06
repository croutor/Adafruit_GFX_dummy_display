#ifndef Print_h
#define Print_h

#include "Arduino.h"

class Print
{
public:
    Print();
    virtual ~Print();
    void print(char* str);
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
        if(str == NULL)
            return 0;
        return write((const uint8_t *) str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
        return write((const uint8_t *) buffer, size);
    }

    // These handle ambiguity for write(0) case, because (0) can be a pointer or an integer
    inline size_t write(short t) { return write((uint8_t)t); }
    inline size_t write(unsigned short t) { return write((uint8_t)t); }
    inline size_t write(int t) { return write((uint8_t)t); }
    inline size_t write(unsigned int t) { return write((uint8_t)t); }
    inline size_t write(long t) { return write((uint8_t)t); }
    inline size_t write(unsigned long t) { return write((uint8_t)t); }
    // Enable write(char) to fall through to write(uint8_t)
    inline size_t write(char c) { return write((uint8_t) c); }
    inline size_t write(int8_t c) { return write((uint8_t) c); }
};

#endif

