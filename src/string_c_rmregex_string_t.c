#include "string_c.h"

static char is_metachar(char ch)
{
    return (ch == '.' || ch == '^' || ch == '$' || ch == '*');
}

static regex_token tokenize_expr(const string_d expr)
{
    regex_token = NULL;
    size_t expr_size = strlen(expr);
    char flag = '\0';

    for (size_t c = 0; c < expr_size; ++c)
    {
        if (is_metachar(expr[c]))
        {
            if (expr[c] == '*')
            {
                if (c == 0) // When '*' is the first char it is considered a normal char
                {
                    regex_token.token = expr[c];
                    regex_token.type = STRING;
                }
                else
                    regex_token.nrpt = -1;
            }
        }
    }
}

static char sequence_match(string_t str, const regex_s expr, size_t* n_mtch)
{
    size_t c;
    for (c = 0; str[c] == expr.pattern[c]; ++c);
    if (expr.pattern[c] == '\0')
    {
        *n_mtch = c;

        return 1;
    }
    return 0;
}

// regggggex
int rmregex_string_t(string_t str, const string_d expr)
{
    int ret = 0;
    regex_s expr = { regex };

    for (size_t c = 0; str[c]; ++c)
    {
        size_t n_mtch = 0;
        if (sequence_match(str + c, expr, &n_mtch))
        {
            while (n_mtch)
            {
                lshift_string_t(str, c);
                --n_mtch;
            }

            ++ret;
        }
    }

    return ret;
}
