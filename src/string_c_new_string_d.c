#include "string_c.h"

/**
 * @brief Allocate how many chars exists in content, copy its content then
 * return the new string_d object.
 *
 * @param const string_d restrict content: The content that the new string will
 * have.
 * @return A null terminated string_d with content. NULL if nothing be informed
 * to content.
 */
string_d new_string_d(const string_d restrict content)
{
    if (!content)
        return NULL;

    size_t content_len = strlen(content) + 1;
    string_d new = malloc(sizeof (string_d) * content_len);
    memcpy(new, content, content_len);
    new[content_len] = '\0'; // Finishes the string placing a null byte at its end

    return new;
}
