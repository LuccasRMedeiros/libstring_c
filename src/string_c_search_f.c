#include "string_c.h"

// Regex =======================================================================

enum atom_type_e
{
    AT_NONE,
    AT_STRING,
    AT_WILDCARD,
    AT_GROUP,
    AT_RANGE,
    AT_IGNORE,
    AT_CONDITION,
};

enum atom_pos_e
{
    POS_ANY,
    POS_BEGIN,
    POS_END,
};

typedef struct regex_atoms_s
{
    unsigned char atom;
    enum atom_type_e atom_type;
    unsigned int n_rpt;
    enum atom_pos_e atom_pos;
    struct regex_atoms_s* next_atom;
    struct regex_atoms_s* prev_atom;
} regex_atoms_t;

static regex_atoms_t* new_regex_atoms_node(enum atom_pos_e atom_pos)
{
    regex_atoms_t *ret = malloc(sizeof (*ret));

    if (ret != NULL)
    {
        ret->atom = 0;
        ret->atom_type = AT_NONE;
        ret->n_rpt = 0;
        ret->atom_pos = atom_pos;
        ret->next_atom = NULL;
    }
    else
    {
        return NULL;
    }

    return ret;
}

static void delete_regex_atoms_list(regex_atoms_t *del)
{
    regex_atoms_t *aux = NULL;
    
    do
    {
        aux = del->next_atom;

        free(del);
        del = NULL;

        del = aux;
    }
    while (aux != NULL);
}

static size_t set_string_atom (

        const string_d regex,
        size_t at,
        enum atom_pos_e atom_pos,
        regex_atoms_t **head

        )
{
    while (regex[at] != '\0' && regex[at] != '.')
    {
        (*head)->atom = regex[at];
        (*head)->atom_type = AT_STRING;
        (*head)->n_rpt = 1;
        (*head)->atom_pos = atom_pos;

        ++at;
    
        (*head)->next_atom = new_regex_atoms_node(atom_pos);

        if ((*head)->next_atom == NULL)
        {
            return 0;
        }
        
        *head = (*head)->next_atom;
    }

    return at;
}

static regex_atoms_t *classify(const string_d regex)
{
    enum atom_pos_e atom_pos = POS_ANY;
    regex_atoms_t *top = new_regex_atoms_node(atom_pos);
    regex_atoms_t *head = top;

    if (!head)
        return NULL;

    for (size_t at = 0; regex[at] != '\0'; ++at)
    {
        if (regex[at] != '.')
        {
            at = set_string_atom(regex, at, atom_pos, &head);

            if (at == 0)
            {
                delete_regex_atoms_list(top);

                return NULL;
            }

            --at; // Decrease to not jump the next caracter
        }
        else
        {
            head->atom = regex[at];
            head->atom_type = AT_WILDCARD;
            head->atom_pos = atom_pos;

            if ((head->next_atom = malloc(sizeof (regex_atoms_t))) == NULL)
            {
                delete_regex_atoms_list(top);

                return NULL;
            }

            head = head->next_atom;
        }
    }
    
    return top;
}

search_restable_t *regex_findin(const string_d src, const string_d regex)
{
    search_restable_t *results = NULL;
    regex_atoms_t *top = classify(regex), *head = top;
    size_t cnt_finds = 0;
    size_t *positions = NULL, *lengths = NULL;

    if (!head)
        return NULL;
    
    for (size_t c = 0; src[c] != '\0'; ++c)
    {
        if (src[c] == head->atom || head->atom_type == AT_WILDCARD)
        {
            size_t position = c, length = 0;

            while (
                    (src[c] == head->atom && head->atom_type == AT_STRING) ||
                    head->atom_type == AT_WILDCARD
                    )
            {
                ++length;
                ++c;
                head = head->next_atom;
            }

            if (head->atom_type == AT_NONE) // Means it corresponded
            {
                ++cnt_finds;

                positions = realloc(positions, sizeof (size_t) * cnt_finds);
                lengths = realloc(lengths, sizeof (size_t) * cnt_finds);

                positions[cnt_finds - 1] = position;
                lengths[cnt_finds - 1] = length;
            }

            head = top;
        }
    }

    delete_regex_atoms_list(top);

    results = malloc(sizeof (search_restable_t));
    
    if (!results)
    {
        return NULL;
    }

    results->n_finds = cnt_finds;
    results->positions = positions;
    results->lengths = lengths;

    return results;
} 
// =============================================================================

void del_search_restable(search_restable_t *del)
{
    if (del == NULL)
    {
        return;
    }

    free(del->positions);
    free(del->lengths);
    free(del);
    del = NULL;
}
