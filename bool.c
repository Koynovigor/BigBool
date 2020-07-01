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
        perror("Не хватает места");
        return NULL;
    }

    int beginning = 1;
    while ((symbol = fgetc(stdin)) != '\n')
    {
        if (((symbol - '0') | 0x1) != 0x1)
        {
            perror("Не правильно введён вектор");
            return NULL;
        }

        if (((symbol - '0') == 0x0) && (beginning))
        {
            continue;
        }
        if (((symbol - '0') == 0x1) && (beginning))
        {
            beginning--;
        }
        
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

struct bigbool *char_from_bool(char *vector)
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

        war->parts[j] = war->parts[j] | (uint8_t)((uint8_t)(a - '0') << (i % 8));
    }
    return war;
};


char *bool_from_char(struct bigbool *war)
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


uint64_t bool_from_uint64(struct bigbool *war)
{
    if (war == NULL)
    {
        return ERROR_BAD_POINTER;
    }

    if (((war->last_byte - 1) * 8 + war->last_bit) > 64)
    {
        return ERROR_TOO_BIG;
    }

    uint64_t vector = 0;
    int k = 0;
    for (int i = 0; i < war->last_byte - 1; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            vector = vector | ((uint64_t)(((uint8_t)(1 << j) & war->parts[i]) >> j) << k);
            k++;
        }
    }

    for (int i = war->last_bit -1 ; i >= 0; i--)
    {
        vector = vector | ((uint64_t)(((uint8_t)(1 << i) & war->parts[war->last_byte - 1]) >> i) << k);
        k++;
    }
    
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

    if (war == NULL)
    {
        return NULL;
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

    if (war == NULL)
    {
        return NULL;
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

struct bigbool* cyclic_shift_left(struct bigbool *war, int n)
{
    if (n == 0)
    {
        return war;
    }

    if (n < 0)
    {
        n *= -1;
        return cyclic_shift_right(war, n);
    }

    if (war == NULL)
    {
        return NULL;
    }

    n = n%((war->last_byte - 1) * 8 + war->last_bit);
    for (int i = 0; i < n; i++)
    {
        int k = war->last_bit - 1;
        for (int j = k - 1; j >= 0; j--)
        {
            uint8_t x = (war->parts[war->last_byte - 1] >> k) & 1;
            uint8_t y = (war->parts[war->last_byte - 1] >> j) & 1;
            x = x ^ y;
            x = (x << k) | (x << j);
            war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] ^ x;
        }

        for (int i = war->last_byte - 2; i >= 0; i--)
        {
            for (int j = 7; j >= 0; j--)
            {
                uint8_t x = (war->parts[war->last_byte - 1] >> k) & 1;
                uint8_t y = (war->parts[i] >> j) & 1;
                x = x ^ y; 
                war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] ^ (x << k);
                war->parts[i] = war->parts[i] ^ (x << j);
            } 
        }
        
    }
return war;
}

struct bigbool* cyclic_shift_right(struct bigbool *war, int n)
{
    if (n == 0)
    {
        return war;
    }

    if (n < 0)
    {
        n *= -1;
        return cyclic_shift_left(war, n);
    }

    if (war == NULL)
    {
        return NULL;
    }

    n = n%((war->last_byte - 1) * 8 + war->last_bit);
    
    for (int i = 0; i < n; i++)
    {
        int k = war->last_bit - 1;
            
        for (int i = 0; i < war->last_byte - 1; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                uint8_t x = (war->parts[war->last_byte - 1] >> k) & 1;
                uint8_t y = (war->parts[i] >> j) & 1;
                x = x ^ y; 
                war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] ^ (x << k);
                war->parts[i] = war->parts[i] ^ (x << j);
            } 
        }

        for (int j = 0; j < k; j++)
        {
            uint8_t x = (war->parts[war->last_byte - 1] >> k) & 1;
            uint8_t y = (war->parts[war->last_byte - 1] >> j) & 1;
            x = x ^ y;
            x = (x << k) | (x << j);
            war->parts[war->last_byte - 1] = war->parts[war->last_byte - 1] ^ x;
        }
        
    }
return war;
}