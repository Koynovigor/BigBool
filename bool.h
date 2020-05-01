#include <inttypes.h>
#ifndef BOOL_H
#define BOOL_H


struct bigbool 
    {
        uint8_t* parts;
        int last_bit;
        int last_byte;
    };

char* scan_vector();



#endif