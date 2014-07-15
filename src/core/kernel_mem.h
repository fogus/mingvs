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

#endif

