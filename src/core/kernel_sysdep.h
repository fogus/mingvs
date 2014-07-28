#ifndef __SYSDEP_H__
#define __SYSDEP_H__

#ifndef __TYPE_SCALAR_H__
#include "type_scalar.h"
#endif

#ifndef _STDIO_INCLUDED_
#define _STDIO_INCLUDED_
#include <stdio.h>
#endif

#include <setjmp.h>

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __SYSDEP_C__
#define LOCALE
#else
#define LOCALE extern
#endif

LOCALE void* sysdep_init_env(env_ref, struct symbol_table_node_t**);

#endif
