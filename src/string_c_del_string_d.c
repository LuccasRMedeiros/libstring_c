#include "string_c.h"

/**
 * @brief Free and clean memory of del.
 * Warning: Don't pass a already freed string_d, otherwise it will cause a 
 * double free
 *
 * @param string_d del: The string to be deleted
 */
void del_string_d(string_d del)
{
    size_t len = strlen(del);

    free(del);
    memset(del, 0, len);
}
