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

struct bigbool* conversion_bool (char* vector);
char *conversion_char(struct bigbool *war);

struct bigbool *shift_left(struct bigbool *war, int n);
struct bigbool *shift_right(struct bigbool *war, int n);

#endif