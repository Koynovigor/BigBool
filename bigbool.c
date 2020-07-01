#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Введите Ваш вектор: ");
    char* vector = scan_vector();
    if (vector == NULL)
    {
        return 1;
    }

    struct bigbool* war = char_from_bool(vector);
    if (war == NULL)
    {
        puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
        return 1;
    }

    printf("%ld\n", bool_from_uint64(war));


return 0;
}
 