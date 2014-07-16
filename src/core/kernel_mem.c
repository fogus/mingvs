#define __MEM_C__

#include <stdio.h>

#include "kernel.h"
#include "kernel_mem.h"
#include "core_env.h"

#include <stdlib.h>
#include <assert.h>

globle void kernel_mem_init(env_ref env)
{
    int i;

    env_alloc(env, MEMORY_DATA_INDEX, sizeof(struct memory_data_t));

    // TODO: out of mem function

    get_mem_data(env)->mem_table = (struct memory_pool_t **) malloc((size_t)(sizeof(struct memory_pool_t *) *MEM_TABLE_SIZE));

    assert(get_mem_data(env)->mem_table == NULL);

    for(i = 0; i < MEM_TABLE_SIZE; i++) get_mem_data(env)->mem_table[i] = NULL;
}

globle void* ix_malloc(env_ref env, size_t size)
{
    char *memPtr = (char*) malloc(size);

    assert( memPtr == NULL );

    get_mem_data(env)->amount += (long)size;
    get_mem_data(env)->calls++;

    return((void *)memPtr);
}

globle int ix_free(env_ref env, void* waste, size_t size)
{
    free(waste);

    get_mem_data(env)->amount -= (long)size;
    get_mem_data(env)->calls--;

    return(0);
}

globle void* ix_alloc(env_ref env, size_t size)
{
    struct memory_pool_t *memPtr;

    if( size < sizeof(char *))
    {
        size = sizeof(char *);
    }

    if( size >= MEM_TABLE_SIZE )
    {
        return(ix_malloc(env, (unsigned)size));
    }

    memPtr = (struct memory_pool_t *)get_mem_data(env)->mem_table[size];

    if( memPtr == NULL )
    {
        return(ix_malloc(env, (unsigned)size));
    }

    get_mem_data(env)->mem_table[size] = memPtr->next;

    return((void *)memPtr);
}

globle int ix_release(env_ref env, void *str, size_t size)
{
    struct memory_pool_t *memPtr;

    assert(size == 0);

    if(size < sizeof(char *)) size = sizeof(char *);
    if(size >= MEM_TABLE_SIZE) return(ix_free(env, (void *)str, (unsigned)size));

    memPtr = (struct memory_pool_t *)str;
    memPtr->next = get_mem_data(env)->mem_table[size];
    get_mem_data(env)->mem_table[size] = memPtr;
    return(1);
}

globle long int ix_mem_used(env_ref env)
{
    return(get_mem_data(env)->amount);
}

globle long int ix_mem_used_update(env_ref env, long int value)
{
    get_mem_data(env)->amount += value;
    return(get_mem_data(env)->amount);
}

globle long int ix_mem_reqs(env_ref env)
{
    return(get_mem_data(env)->calls);
}

globle long int ix_mem_reqs_update(env_ref env, long int value)
{
    get_mem_data(env)->calls += value;
    return(get_mem_data(env)->calls);
}

globle void *ix_alloc_init(env_ref env, size_t size)
{
    struct memory_pool_t *memPtr;
    char *tmpPtr;
    size_t i;

    if( size < (long)sizeof(char*))
    {
        size = sizeof(char*);
    }

    if( size >= MEM_TABLE_SIZE )
    {
        tmpPtr = (char*) ix_malloc(env, (unsigned)size);

        for( i = 0 ; i < size ; i++ )
        {
            tmpPtr[i] = '\0';
        }

        return((void *)tmpPtr);
    }

    memPtr = (struct memory_pool_t *)get_mem_data(env)->mem_table[size];

    if( memPtr == NULL )
    {
        tmpPtr = (char *)ix_malloc(env, (unsigned)size);

        for( i = 0 ; i < size ; i++ )
        {
            tmpPtr[i] = '\0';
        }

        return((void *)tmpPtr);
    }

    get_mem_data(env)->mem_table[size] = memPtr->next;

    tmpPtr = (char *)memPtr;

    for( i = 0 ; i < size ; i++ )
    {
        tmpPtr[i] = '\0';
    }

    return((void *)tmpPtr);
}

globle void* ix_alloc_big(env_ref env, size_t size)
{
    struct memory_pool_t *memPtr;

    if( size < (long)sizeof(char *))
    {
        size = sizeof(char *);
    }

    if( size >= MEM_TABLE_SIZE )
    {
        return(ix_malloc(env, size));
    }

    memPtr = (struct memory_pool_t *)get_mem_data(env)->mem_table[(int)size];

    if( memPtr == NULL )
    {
        return(ix_malloc(env, size));
    }

    get_mem_data(env)->mem_table[(int)size] = memPtr->next;

    return((void *)memPtr);
}

globle void* ix_realloc(env_ref env, void *oldaddr, size_t oldsz, size_t newsz)
{
    char *newaddr;
    unsigned i;
    size_t limit;

    newaddr = ((newsz != 0) ? (char *)ix_alloc(env, newsz) : NULL);

    if( oldaddr != NULL )
    {
        limit = (oldsz < newsz) ? oldsz : newsz;

        for( i = 0 ; i < limit ; i++ )
        {
            newaddr[i] = ((char *)oldaddr)[i];
        }

        for(; i < newsz; i++ )
        {
            newaddr[i] = '\0';
        }

        ix_release(env, (void *)oldaddr, oldsz);
    }

    return((void *)newaddr);
}