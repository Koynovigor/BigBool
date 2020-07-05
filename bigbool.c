#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    // printf("Введите Ваш вектор 1: ");
    // char* vector1 = scan_vector();
    // if (vector1 == NULL)
    // {
    //     return 1;
    // }
    // printf("Введите Ваш вектор 2: ");
    // char* vector2 = scan_vector();
    // if (vector2 == NULL)
    // {
    //     return 1;
    // }

    // struct bigbool* war1 = char_from_bool(vector1);
    // if (war1 == NULL)
    // {
    //     puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
    //     return 1;
    // }
    // struct bigbool* war2 = char_from_bool(vector2);
    // if (war2 == NULL)
    // {
    //     puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
    //     return 1;
    // }

    // struct bigbool* war3 = operation_bb(war1,OR ,war2);
    // printf("%s\n", bool_from_char(war3));
    // printf("%s\n", bool_from_char(operation_bb(war1,AND ,war2)));
    // printf("%s\n", bool_from_char(operation_bb(war1,XOR ,war2)));
    // printf("%s\n", bool_from_char(invertbb(war1)));

    // free_bigbool(war1);
    // free_bigbool(war2);
    // free_bigbool(war3);

    // printf("Введите число: ");
    // uint64_t vector = 0;
    // scanf("%ld", &vector);
    // printf("%s\n", bool_from_char(uint64_from_bool(vector)));
    // printf("%ld\n", sizeof(uint64_t));

    struct bigbool* war = uint64_from_bool(0);
    char* str = bool_from_char(war);
    printf("%s\n", str);
    struct bigbool* war2 = char_from_bool(str);

    printf("%ld  %d\n", bool_from_uint64(war2), 0);

return 0;
}