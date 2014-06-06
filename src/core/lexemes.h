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
    long                        count;                   /* The reference count */
    int                         depth;                   /* The symbol's call-depth */
    struct gc_descriptor_t      gc_descr;
    char *                      contents;
    type_decl                   t;
};

#endif
