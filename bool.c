#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct bigbool* conversion (char* vector, int len, struct bigbool war)
{
    int j = -1;            
    for (int i = 0; i < len; i++)
    {
        if(i%8 == 0)
        {
            j++;
            war->parts[j] = 0;
        }
        char a = vector[i];
        if (((uint8_t)(a - '0') | 0x1) != 0x1)
        {
            printf("Вы ввели не верный вектор, попробуйте снова!\n");
            return 1;
        }
        
        war->parts[j] = war->parts[j] | (uint8_t)((uint8_t)(a  - '0') << (i%8));
    }
};