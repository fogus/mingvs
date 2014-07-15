#ifndef __CORE_ENVIRONMENT_H__
#define __CORE_ENVIRONMENT_H__

#ifndef __TYPE_SCALARS_H__
#include "type_scalar.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __CORE_ENVIRONMENT_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "kernel.h"

#define USER_ENVIRONMENT_DATA_INDEX   70
#define MAXIMUM_ENV_SZ 100

struct env_t
{
    unsigned int   initialized : 1;
    unsigned long  index;
    void*          context;
    void**         data;
    struct env_t*  next;
    // TODO: Cleanup function?
};

typedef struct env_t  ENV_T;
typedef struct env_t* ENV_PTR;

#define get_env_data(env, position)        (((struct env_t *)env)->data[position])
#define set_env_data(env, position, value) (((struct env_t *)env)->data[position] = value)

LOCALE void env_alloc(env_ref, unsigned int, unsigned long);

#endif

