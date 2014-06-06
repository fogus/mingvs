#ifndef __TYPE_LEXEMES_H__
#define __TYPE_LEXEMES_H__

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __TYPE_LEXEMES_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "setup.h"
#include "constants.h"
#include "gc.h"

#include <stdlib.h>

#ifndef SYMBOL_HASH_SZ
#define SYMBOL_HASH_SZ          63559L
#endif

/**
 *  \struct symbol_hash_node_t
 *
 *  Holds the runtime information for individual symbols.
 *
 **/
struct symbol_table_node_t
{
    struct symbol_table_node_t* next;
    char *                      contents;
    type_decl                   t;
    struct gc_descriptor_t      gc_descr;
};

typedef struct symbol_table_node_t SYMBOL_T;

/* Lexeme function signatures */

LOCALE void init_symbol_table(env_ref, struct symbol_table_node_t **);
LOCALE void* intern_symbol(env_ref, char *);

#endif
