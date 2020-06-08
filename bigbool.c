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

    // int status = 0;
    // do
    // {
    //     printf("Выбирите действие:\nСдвиг вправо - 1\nСдвиг влево - 2\nВыход - 0\n");
    //     scanf("%d", &status);

    //     if (status == 1);
    //     {
    //         printf("На сколько позиций хотите выполнить сдвиг? ");
    //         int right = 0;
    //         scanf("%d", &right);
    //         shift_right(war, right);

    //     }
    // } while (status != 0);
   
    printf("%d, %d\n", war->last_bit, war->last_byte);
    shift_right(war, 17);
    printf("%s\n", conversion_char(war));
    printf("%d, %d\n", war->last_bit, war->last_byte);
return 0;
}
 