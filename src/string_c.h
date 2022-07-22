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

/**
 * @brief Array of STRING_SIZE chars
 */
typedef char string_t[STRING_SIZE];

/**
 * @brief Pointer to chars
 */
typedef char* string_d;

// TODO
// /**
//  * @brief Struct with a string_d and its current size
//  */
// typedef struct
// {
//     string_d content;
//     size_t size;
//     size_t mem;
// } string_s;

enum tkt_e
{
    STRING,
    GROUP,
    RANGE,
};

typedef struct regex_token_s
{
    char token;
    enum tkt_e type;
    int nrpt;
    struct regex_ext_s next_token;
    struct regex_ext_s prev_token;
} regex_token;

// Array strings functions
void lshift_string_t(string_t str, const size_t init_pos);
int trim_string_t(string_t str);
int rmchar_string_t(string_t str, const char ch);
int rmgroup_string_t(string_t str, const string_d group);
int rmsubstr_string_t(string_t str, const string_d sub);
int rmregex_string_t(string_t str, const string_d regex);

// Dynamic strings functions
// string_d new_string_d(const string_d content);
// void del_string_d(string_d del);
// void edit_string_d(string_d src, const string_d new_content);
// string_d trim_string_d(string_d str);
// string_d slice_string_d(const string_d src, const size_t start, const size_t end);
// string_d concat_string_ds(string_d s1, string_d s2);
// string_d combine_string_ds(unsigned int n_string_ds, ...);
// string_d* split_string_d(string_d split, char limiter);

// // Universal strings functions
// int mc_findin(const string_d src, const string_d lookfor);
// int ic_findin(const string_d src, const string_d lookfor);
// int regex_findin(const string_d src, const string_d restrict regex);
// int mc_replace(string_d src, const string_d lookfor, const string_d replacefor);
// int ic_replace(string_d src, const string_d lookfor, const string_d replacefor);
// int regex_replace(string_d src, const string_d regex, const string_d replacefor);

#endif
