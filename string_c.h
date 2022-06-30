/**
 * @file string_c.h
 * @author Luccas Rocigno de Medeiros
 * @date 06/21/2022
 * @brief Header for use of string type
 *
 * string_c, differently of the well known string library of C, create a type
 * string_t which is defined as array of STRING_SIZE and the type string_d which
 * is a pointer to char that can have memory allocated to it allowing the 
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

/**
 * @brief Array of STRING_SIZE chars
 */
typedef char string_t[STRING_SIZE];

/**
 * @brief Pointer to char
 */
typedef char* string_d;

// Array strings functions
void trim_string_t(string_t src);
int combine_string_ts(string_t dst, unsigned int n_string_ts, ...);
string_t* split_string_t(string_t split, char limiter);

// Dynamic strings functions
string_d new_string_d(const char *content);
void edit_string_d(string_d *src, const string_d new_content);
void addto_string_d(string_d *src, const string_d add_content);
void trim_string_d(string_d *src);
string_d concat_string_ds(string_d s1, string_d s2);
string_d combine_string_ds(unsigned int n_string_ds, ...);
string_d* split_string_d(string_d split, char limiter);
void del_string_d(string_d del);

// Universal strings functions
int mc_findin(const string_d src, const string_d restrict lookfor);
int ic_findin(const string_d src, const string_d restrict lookfor);
int regex_findin(const string_d src, const string_d restrict regex);

#endif
