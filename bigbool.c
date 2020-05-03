#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* vector = scan_vector();
    if (vector == NULL)
    {
        puts("Ну сорри, слишком большой вектор! Мне не хватает рессурсов памяти, чтобы его запомнить!");
        return 1;
    }

    struct bigbool* war = conversion_bool(vector);
    if (war == NULL)
    {
        puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
        return 1;
    }

    // int len =(war->last_byte - 1) * 8 + war->last_bit;
    // printf("%d\n", len);
    // int res = 0;
    // for (int i = 0; i < war->last_byte; i++)
    // {
    //     res += (int)war->parts[i];
    // }
    // printf("%d\n", res);

    int s = (int)war->last_bit;
    int d = (int)war->last_byte;
    printf("%d, %d\n", s, d);
    shift_left(war, 1);
    int s1 = (int)war->last_bit;
    int d1 = (int)war->last_byte;
    printf("%d, %d\n", s1, d1);

    char* vector1 = conversion_char(war);
    printf("%s\n", vector1);

return 0;
}
 