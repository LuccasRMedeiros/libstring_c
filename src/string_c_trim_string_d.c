#include "string_c.h"

/**
 * @brief Remove the whitespaces around str and return the resultant string.
 * Warning: It deletes str after finish the trim, the resultant string _d points
 * to a new address.
 *
 * @param string_d str: The string to be trimmed
 * @return A new string_d with the result of trim, or NULL case malloc fails to
 * allocate sufficient memory for the resultant string.
 */
string_d trim_string_d(string_d str)
{
    size_t start;
    while (ispace(str[start]))
        ++start;

    size_t end = strlen(str);
    while (isspace(str[end]))
        --end;

    size_t final_size = (end - start) + 1; // Consider the terminating null byte
    string_d result = malloc(sizeof (string_d) * final_size);
    if (!result)
        return NULL;

    for (size_t c = 0; c < final_size; ++c)
    {
        result[c] = str[start];
        ++start;
    }
    result[c] = '\0';

    del_string_d(str);

    return result;
}
