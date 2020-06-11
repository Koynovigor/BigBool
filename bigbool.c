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
        puts("Ну сорри, слишком большой вектор! Мне не хватает рессурсов памяти, чтобы его запомнить!");
        return 1;
    }

    struct bigbool* war = conversion_bool(vector);
    if (war == NULL)
    {
        puts("Кажется, вы ввели не правильный вектор!(но это  не точно)");
        return 1;
    }

    printf("%s\n", conversion_char(cyclic_shift_left(war, 1)));

return 0;
}
 