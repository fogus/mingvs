#define __CORE_ENVIRONMENT_C__

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



