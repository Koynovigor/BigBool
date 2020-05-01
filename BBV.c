#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bool.h"


#define bigbool \
    struct bigbool \
    {\
        uint8_t parts[n];\
        int last_bit;\
        int last_byte;\
    }\

int main()
{
    char* vector = calloc(513, sizeof(char));
    if (vector == NULL)
    {
        perror("Ошибочка вышла");
        return 1;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    if (fgets(vector, 512, stdin) == NULL)
    {
        perror("Ошибочка вышла");
        return 1;
    }
    int len = strlen(vector);
    vector = realloc(len+1, vector);
    if (vector[len-1] == 0xa)   // linefeed
    {
       len--;
    }
    int n = len/8 + 1;
    bigbool war;

    // int j = -1;            
    // for (int i = 0; i < len; i++)
    // {
    //     if(i%8 == 0)
    //     {
    //         j++;
    //         war->parts[j] = 0;
    //     }
    //     char a = vector[i];
    //     if (((uint8_t)(a - '0') | 0x1) != 0x1)
    //     {
    //         printf("Вы ввели не верный вектор, попробуйте снова!\n");
    //         return 1;
    //     }
        
    //     war.parts[j] = war.parts[j] | (uint8_t)((uint8_t)(a  - '0') << (i%8));
    // }

    // free(vector);




    char* vector1 = calloc(513, sizeof(char));
    int k = -1;
    for (int i = 0; i < len; i++)
    {
        if(i%8 == 0)
        {
            k++;
        }
        uint8_t a = war.parts[k];
        vector1[i] = ((int)((a & (uint8_t)(1 << i%8)) >> i%8) + '0');
    }
    printf("%d\n", war.parts[0]);
    printf("%s\n", vector1);
return 0;
}
 