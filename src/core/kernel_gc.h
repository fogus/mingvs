#ifndef __GC_H__
#define __GC_H__

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __GC_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "kernel.h"


struct gc_descriptor_t
{
    long                        count;                   /* reference count */
    int                         depth;                   /* call-depth */
    boolean                     permanent       : 1;
    boolean                     ephemeral       : 1;
    boolean                     needed          : 1;
    unsigned int                bucket          : 29;
};

#endif

