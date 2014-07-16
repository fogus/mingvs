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

#define MEMORY_DATA_INDEX 59
#define MEM_TABLE_SIZE 500

#define get_mem_data(env) ((struct memory_data_t *)get_env_data(env, MEMORY_DATA_INDEX))

struct memory_data_t
{
    long int               amount;
    long int               calls;
    boolean                is_conserving;
    struct memory_pool_t*  temp_ptr;
    struct memory_pool_t** mem_table;
    size_t                 temp_sz;
    //  TODO: out of mem func 
};

LOCALE void  kernel_mem_init(env_ref);
LOCALE void* ix_malloc(env_ref, size_t);
LOCALE int   ix_free(env_ref, void*, size_t);
LOCALE void* ix_alloc(env_ref, size_t);
LOCALE long ix_mem_used(env_ref);
LOCALE long ix_mem_reqs(env_ref);
LOCALE long	ix_mem_used_update(env_ref, long int);
LOCALE long	ix_mem_reqs_update(env_ref, long int);
LOCALE int ix_release(env_ref, void*, size_t);
LOCALE void* ix_alloc_init(env_ref, size_t);
LOCALE void* ix_realloc(env_ref, void*, size_t, size_t);

#endif

