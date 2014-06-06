#ifndef __CORE_ENVIRONMENT_H__
#define __CORE_ENVIRONMENT_H__

#ifndef __TYPE_SCALARS_H__
#include "scalars.h"
#endif

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __CORE_ENVIRONMENT_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "setup.h"
#include "constants.h"

#define USER_ENVIRONMENT_DATA_INDEX   70
#define MAXIMUM_ENVIRONMENT_POSITIONS 100

struct env_t
{
    unsigned int   initialized : 1;
    unsigned long  index;
    void*          context;
    void**         data;
    struct env_t*  next;
};

#endif

