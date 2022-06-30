/**
 * @file string_c.h
 * @author Luccas Rocigno de Medeiros
 * @date 06/21/2022
 * @brief Header for use of string type
 *
 * string_c, differently of the well known string library of C, create a type
 * string_t which is defined as array of STRING_SIZE and the type string_d, 
 * a pointer to char that can have memory allocated to it allowing the 
 * possibility to create more dynamic strings.
 */
#ifndef STRING_C_H
#define STRING_C_H

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

// If STRING_SIZE is not defined before compiling, it defaults to 64
#ifndef STRING_SIZE
#define STRING_SIZE 64
#endif

#define SHORT_STRING_SIZE STRING_SIZE / 2
#define BIG_STRING_SIZE STRING_SIZE * 2

/**
 * @brief Array of STRING_SIZE chars
 */
typedef char string_t[STRING_SIZE];

/**
 * @brief Array of half STRING_SIZE chars
 */
typedef char s_string_t[SHORT_STRING_SIZE];

/**
 * @brief Array of double STRING_SIZE chars
 */
typedef char b_string_t[BIG_STRING_SIZE];

/**
 * @brief Pointer to char
 */
typedef char* string_d;

/**
 * @brief Struct with a string_d and its current size
 */
typedef struct
{
    string_d content;
    size_t size;
} string_s;

// Array strings functions
void trim_string_t(string_t src);
int combine_string_ts(string_t dst, unsigned int n_string_ts, ...);

// // Dynamic strings functions
// string_d new_string_d(const char *content);
// void edit_string_d(string_d *src, const string_d new_content);
// void addto_string_d(string_d *src, const string_d add_content);
// void trim_string_d(string_d *src);
// string_d concat_string_ds(string_d s1, string_d s2);
// string_d combine_string_ds(unsigned int n_string_ds, ...);
// string_d* split_string_d(string_d split, char limiter);
// void del_string_d(string_d del);

// // Universal strings functions
// int mc_findin(const string_d src, const string_d restrict lookfor);
// int ic_findin(const string_d src, const string_d restrict lookfor);
// int regex_findin(const string_d src, const string_d restrict regex);
// void clean_string(string_d src, const string_d restrict clean_group);

#endif
