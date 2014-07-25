#define __TYPE_LEXEMES_C__

#include <stdio.h>
#define _STDIO_INCLUDED_
#include <stdlib.h>
#include <string.h>

#include "kernel.h"
#include "kernel_gc.h"
#include "core_env.h"
#include "type_lexeme.h"


globle void init_symbol_table(env_ref env, struct symbol_table_node_t** symtable)
{
    env_alloc(env, SYMBOL_DATA_INDEX, sizeof(struct rt_scalar_data_t));  // TODO: Cleanup function?

    get_scalar_data(env)->symbol_table = (SYMBOL_T **) ix_alloc_big(env, sizeof(SYMBOL_T *) * SYMBOL_HASH_SZ);

}


