#ifndef __MEM_H__
#define __MEM_H__

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __MEM_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include "kernel.h"

#endif

