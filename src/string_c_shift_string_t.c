#include "string_c.h"

/**
 * @brief Shift all the chars inside string to the left.
 *
 * Pay attention that this is not a bitwise operation. The purpose of this
 * function is to shift the characters inside the string from index "init_pos"
 * to the left, purposely causing data loss.
 * For example, a string containing "Helllo World!!" that is left shifted by
 * this function from the index 2 (that is the first 'l' char) will then contain
 * "Hello World!!" in the end.
 * The operation is done in string str, so if is intended to keep the previous
 * data, is recommended to firstly copy its content to another buffer.
 *
 * @param str: The string_t to be shifted
 * @param init_pos: The initial index it should start shifting
 */
void lshift_string_t(string_t str, const size_t init_pos)
{
    if (!str)
        return;

    for (size_t c = init_pos; str[c]; ++c)
        str[c] = str[c + 1];
}

