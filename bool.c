#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* scan_vector()
{
    int count = 0;
    int count_max = 128;
    int symbol;
    char* str = calloc(count_max, sizeof(char));
    if (str == NULL)
        {
            return NULL;
        }
    while ((symbol = fgetc(stdin)) != '\n')
    {
        str[count] = symbol;
        count ++;
        if (count == count_max)
        {
            str = (char*)realloc(str, count_max + 128);
            if (str == NULL)
            {
                return NULL;
            }
            count_max += 128;
        }
    }
return str;
}


struct bigbool* conversion (char* vector)
{
    int len = strlen(vector);
    struct bigbool* war = calloc(1, sizeof(struct bigbool));
    
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