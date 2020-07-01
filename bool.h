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
struct bigbool *char_from_BB(char *vector);
char *BB_from_char(struct bigbool *war);
uint64_t BB_from_uint64(struct bigbool *war);
struct bigbool* shift_left(struct bigbool *war, int n);
struct bigbool* shift_right(struct bigbool *war, int n);
struct bigbool* cyclic_shift_left(struct bigbool *war, int n);
struct bigbool* cyclic_shift_right(struct bigbool *war, int n);

#endif