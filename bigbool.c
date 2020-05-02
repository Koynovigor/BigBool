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
    
    char* vector1 = conversion_char(war);
    
    printf("%s\n", vector1);
    
return 0;
}
 