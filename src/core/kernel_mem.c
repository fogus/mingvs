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
    char *memPtr = (char *)malloc(size);

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