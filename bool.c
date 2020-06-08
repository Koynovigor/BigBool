#include "bool.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scan_vector()
{
    int count = 0;
    int count_max = 128;
    int symbol;
    char *str = calloc(count_max, sizeof(char));
    if (str == NULL)
    {
        return NULL;
    }
    while ((symbol = fgetc(stdin)) != '\n')
    {
        str[count] = symbol;
        count++;
        if (count == count_max)
        {
            str = (char *)realloc(str, count_max + 128);
            if (str == NULL)
            {
                return NULL;
            }
            count_max += 128;
        }
    }
    return str;
}

struct bigbool *conversion_bool(char *vector)
{
    int len = strlen(vector);
    if (len == 0)
    {
        return NULL;
    }

    struct bigbool *war = (struct bigbool *)calloc(1, sizeof(struct bigbool));
    if (war == NULL)
    {
        return NULL;
    }

    war->last_bit = (uint8_t)len % 8;
    war->last_byte = (uint8_t)len / 8;
    if (war->last_bit == 0)
    {
        war->last_bit = 8;
    }
    else
    {
        war->last_byte++;
    }
    war->parts = (uint8_t *)calloc(war->last_byte, sizeof(uint8_t));
    if (war->parts == NULL)
    {
        return NULL;
    }

    int j = -1;
    for (int i = 0; i < len; i++)
    {
        if (i % 8 == 0)
        {
            j++;
        }
        char a = vector[i];
        if (((uint8_t)(a - '0') | 0x1) != 0x1)
        {
            return NULL;
        }

        war->parts[j] = war->parts[j] | (uint8_t)((uint8_t)(a - '0') << (i % 8));
    }
    return war;
};

char *conversion_char(struct bigbool *war)
{
    int len =(war->last_byte - 1) * 8 + war->last_bit;
    char *vector = (char *)calloc(len + 1, sizeof(char));
    if (vector == NULL)
    {
        return NULL;
    }

    int k = -1;
    for (int i = 0; i < len; i++)
    {
        if (i % 8 == 0)
        {
            k++;
        }
        uint8_t a = war->parts[k];
        vector[i] = ((int)((a & (uint8_t)(1 << i % 8)) >> i % 8) + '0');
    }
    vector[len] = 0x0;
    return vector;
}

struct bigbool *shift_left(struct bigbool *war, int n)
{
    if (n == 0)
    {
        return war;
    }
    if (n < 0)
    {
        n *= -1;
        return shift_right(war, n);
    }
    if (n > (8 - (int)war->last_bit))
    {
        int k = n/8 + (n%8 != 0);
        war->parts = (uint8_t *)realloc(war->parts, (int)war->last_byte + k);
        if (war->parts == NULL)
        {
            return NULL;
        }
        for (int i = war->last_byte; i < (int)war->last_byte + k; i++)
        {
            war->parts[i] = 0;
        }
        war->last_byte += k;
        war->last_bit = (war->last_bit + n) % 8;
        return war;
    }
    war->last_bit += n;
return war;
}


struct bigbool *shift_right(struct bigbool *war, int n) // n = 17; last_bit = 5; last_byte = 3;
{
    if (n == 0)
    {
        return war;
    }

    if (n < 0)
    {
        n *= -1;
        return shift_left(war, n);
    }

    if (n >= war->last_bit)
    {
        int k = (n - war->last_bit)/8 + 1; // k = 2;
        
        if (k > 1)
        {
            for (int i = war->last_byte - 1; i > war->last_byte - k; i--) // i = 2, 1;
            {
                war->parts[i] = 0;
            }
            
        }
        war->last_byte -= k; // last_byte = 0;

        war->last_bit = (war->last_bit + (8 - n%8))%8; // last_bit = (5 + (8 - 1))%8 = 4;
        for (int i = war->last_bit; i <= 8 ; i++) // i = 4, 5, 6, 7, 8;
        {
            war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] & ~((uint8_t)(1<<i));
        }
        return war; 
    }
    
    for (int i = war->last_bit - n; i < war->last_bit; i++)
    {
        war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] & ~((uint8_t)(1<<i));
    }
    war->last_bit -= n;
return war;
}