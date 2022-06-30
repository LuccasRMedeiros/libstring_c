#include "string_c.h"

/**
 * @brief Combine n strings into dst. The expected variadic arguments are
 * suposed to be string_t types, in other words arrays of chars. When using this
 * function the user does not need to necessarily pass a initialized string_t,
 * it can be a array of chars declared as char[], a pointer to char, it can be 
 * a implicit string and even a "String".
 * Warning: this function will write on dst and will overwrite anything that is
 * present on it.
 *
 * @param string_t dst: Where the strings will be combinated
 * @param unsigned int n_strings: The number of strings that will be combined
 * @param ... The string_t's that are to be combined
 * @return If the combination was a success or not.
 */
int combine_string_ts(string_t dst, unsigned int n_string_ts, ...)
{
    va_list string_tsList;
    va_list listCopy;

    va_start(string_tsList, n_string_ts);
    va_copy(listCopy, string_tsList);

    size_t finalSize = 0;
    for (unsigned int count = 0; count < n_string_ts; ++count)
    {
        finalSize += strlen(va_arg(listCopy, string_t));

        if (finalSize >= STRING_SIZE)
        {
            va_end(string_tsList);
            va_end(listCopy);

            return -1;
        }
    }
    va_end(listCopy); // Ends the listCopy here because we won't need it anymore
    memset(dst, 0, sizeof (string_t));

    for (unsigned int copying = 0; copying < n_string_ts; ++copying)
    {
        string_t src;
        memcpy(src, va_arg(string_tsList, string_t), sizeof (string_t));
        strcat(dst, src);
    }

    return 1; // If the program hits this line the function will signal a success
}
