#ifndef __MEM_H__
#define __MEM_H__

#include <string.h>

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __MEM_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "kernel.h"

struct memory_pool_t
{
    struct memory_pool_t *next;
};

struct memory_data_t
{
    long int               amount;
    long int               calls;
    BOOL                   is_conserving;
    struct memory_pool_t*  temp_ptr;
    struct memory_pool_t** mem_table;
    size_t                 temp_sz;
    //  TODO: out of mem func 
};

LOCALE void init_memory(void *);

#endif

