#include <inttypes.h>
#ifndef BOOL_H
#define BOOL_H

#define ERROR_BAD_POINTER 1
#define ERROR_TOO_BIG 2

enum mode_of_operation {AND, OR, XOR};

struct bigbool 
{
    uint8_t* parts;
    int last_bit;
    int last_byte;
};

//Читает с клавы только ноль или один
//Динамически выделает память для строки
//Не заносит в строку первые незначащие нули
//Возвращает указатель на строку
char* scan_vector();

//Возвращает -1 в случае, если war == NULL
int len_bb(struct bigbool *war);

//Динамически выделяет память под BigBool
struct bigbool *char_from_bool(char *vector);

char *bool_from_char(struct bigbool *war);

uint64_t bool_from_uint64(struct bigbool *war);

struct bigbool* shift_left(struct bigbool *war, int n);

struct bigbool* shift_right(struct bigbool *war, int n);

struct bigbool* cyclic_shift_left(struct bigbool *war, int n);

struct bigbool* cyclic_shift_right(struct bigbool *war, int n);

void free_bigbool(struct bigbool *war);

struct bigbool* expansion_bb(struct bigbool* war, int n);

// if | - mode = OR; if & - mode = AND; if ^ - mode = XOR;
struct bigbool* operation_bb(struct bigbool* a, int mode, struct bigbool* b);

struct bigbool* invertbb(struct bigbool* a);



#endif
