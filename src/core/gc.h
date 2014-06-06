#ifndef __TYPE_GC_H__
#define __TYPE_GC_H__

#ifdef LOCALE
#undef LOCALE
#endif

#include "setup.h"


struct gc_descriptor_t
{
    boolean                     permanent       : 1;
    boolean                     ephemeral       : 1;
    boolean                     needed          : 1;
    unsigned int                bucket          : 29;
};

#endif

