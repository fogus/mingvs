#ifndef __TYPE_SCALARS_H__
#define __TYPE_SCALARS_H__

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __TYPE_SCALARS_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include <stdlib.h>

#include "kernel.h"
#include "type_lexeme.h"

struct rt_scalar_data_t
{
    void *              true_symbol;
    void *              false_symbol;
    void *              nil_symbol;
    void *              nothing_symbol;
    void *              notset_symbol;
    void *              plus_inf;                 // Plus infinity
    void *              neg_inf;                  // Negative infinity
    void *              zero;
    SYMBOL_T **         symbol_table;
};

#define SCALAR_DATA_INDEX 49

#define get_scalar_data(env) ((struct symbol_data_t *)get_env_data(env, SCALAR_DATA_INDEX))

#endif
