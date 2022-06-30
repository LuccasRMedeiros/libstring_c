#include "string_c.h"

/**
 * @brief Edit the contents of src, realloc memory of it if needed, also rewrite
 * all the content inside it, be wary of potential data loss.
 * Does nothing if NULL be informed in any of the parameters.
 *
 * @param string_d src: The string to be edited.
 * @param const string_d restrict new_content: The content that will SUBSTITUTE
 * what is in src
 */
void edit_string_d(string_d src, const string_d restrict new_content)
{
    if (!src || !new_content)
        return ;

    // Consider the terminating null byte
    size_t old_len = strlen(src) + 1;
    size_t new_len = strlen(new_content) + 1;

    if (old_len != new_len)
        src = realloc(src, new_len);

    memcpy(src, new_content, new_len);
    src[new_len] = '\0'; // Finishes the string placing a null byte at its end
}
