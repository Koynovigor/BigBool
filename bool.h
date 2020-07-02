#include <inttypes.h>
#ifndef BOOL_H
#define BOOL_H

#define ERROR_BAD_POINTER 1
#define ERROR_TOO_BIG 2
struct bigbool 
{
    uint8_t* parts;
    int last_bit;
    int last_byte;
};

char* scan_vector();
struct bigbool *char_from_bool(char *vector);
char *bool_from_char(struct bigbool *war);
uint64_t bool_from_uint64(struct bigbool *war);
struct bigbool* shift_left(struct bigbool *war, int n);
struct bigbool* shift_right(struct bigbool *war, int n);
struct bigbool* cyclic_shift_left(struct bigbool *war, int n);
struct bigbool* cyclic_shift_right(struct bigbool *war, int n);
void free_bigbool(struct bigbool *war);
struct bigbool* and_bb(struct bigbool* a, struct bigbool* b);

#endif