#include "string_c.h"

enum tk_type_e
{
    STRING,
    WILDCARD,
    GROUP,
    RANGE_FIRST,
    RANGE_LAST,
    POS_BEGIN,
    POS_FINAL,
    IGNORE,
    CONDITION,
};

static regex_tokens* tokenize(const string_d regex)
{
    regex_tokens* head = calloc(1, sizeof (*head));
    regex_tokens* next = NULL;
    bool is_literal = false;

    for (size_t c = 0; regex[c] != '\0'; ++c)
    {
        next = calloc(1, sizeof (*next));
        
        if (regex[c] == '^' && is_literal == false)
        {
            head->token = regex[c];
            head->tk_type = POS_BEGIN;
        }
        else if (regex[c] == '$' && is_literal == false)
        {
            head->token = regex[c];
            head->tk_type = POS_FINAL;
        }
        head->n_rpt = 0;
        next->prev_token = head;
        head->next_token = next;
        
        head = next;
    }

    while (head->prev_token != NULL)
        head = head->prev_token;

    return head;
}

int* regex_findin(const string_d src, const string_d regex)
{
    (void)src;

    regex_tokens* tokens = tokenize(regex);
    int table[2] = { 0, 0 };
    int* ret = table;

    while (tokens->next_token != NULL)
    {
        tokens = tokens->next_token;
        free(tokens->prev_token);
    }
    
    free(tokens);
    tokens = NULL;

    return ret;
}
