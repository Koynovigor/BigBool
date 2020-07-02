#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Введите Ваш вектор 1: ");
    char* vector1 = scan_vector();
    if (vector1 == NULL)
    {
        return 1;
    }
    printf("Введите Ваш вектор 2: ");
    char* vector2 = scan_vector();
    if (vector2 == NULL)
    {
        return 1;
    }

    struct bigbool* war1 = char_from_bool(vector1);
    if (war1 == NULL)
    {
        puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
        return 1;
    }
    struct bigbool* war2 = char_from_bool(vector2);
    if (war2 == NULL)
    {
        puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
        return 1;
    }

    printf("%s\n", bool_from_char(and_bb(war1, war2)));


return 0;
}
 