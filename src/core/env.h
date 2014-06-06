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


#endif

