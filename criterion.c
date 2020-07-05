#include "bool.h"
#include <stdio.h>
#include <limits.h>
#include <criterion/criterion.h>
#include <inttypes.h>

Test(BB, creat_bb) {

    for (uint64_t i = 0; i < SHRT_MAX; i++)
    {
        struct bigbool* war = uint64_from_bool(i);
        cr_assert_neq(war, NULL);
        char* str = bool_from_char(war);
        cr_assert_neq(str, NULL);
        struct bigbool* war2 = char_from_bool(str);
        cr_assert_neq(war2, NULL);

        cr_assert_eq(bool_from_uint64(war2), i);

        free_bigbool(war2);
        free(str);
        free_bigbool(war);
    }


}
