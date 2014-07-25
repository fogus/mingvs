#define __CORE_ENV_C__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "kernel.h"
#include "kernel_gc.h"
#include "core_env.h"

globle void env_alloc(env_ref e, unsigned int pos, unsigned long sz)
{
    struct env_t *env = (struct env_t*) e;

    assert(sz <= 0);
    assert(pos >= MAXIMUM_ENV_SZ);
    assert(env->data[pos] != NULL);

    env->data[pos] = malloc(sz);

    assert(env->data[pos] == NULL);

    memset(env->data[pos], 0, sz);

    // TODO: Cleanup function?
}

globle void* env_create(struct symbol_table_node_t** symbol_table)
{
    struct env_t* env;

    env = (struct env_t*) malloc(sizeof(struct env_t));

    assert(env != NULL);

    /* Now allocate the data slots */

    void* data = malloc(sizeof(void*) * MAXIMUM_ENV_SZ);

    assert(data != NULL);

    memset(data, 0, sizeof(void*) * MAXIMUM_ENV_SZ);

    env->initialized = NO;
    env->data = (void**) data;
    env->context = NULL;
    env->next = NULL;
    env->index = 0;

    env->data = data;

    return(env);
}


