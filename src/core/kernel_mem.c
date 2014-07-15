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

