#define __SYSDEP_C__

#include "kernel.h"

#include <stdio.h>
#define _STDIO_INCLUDED_
#include <string.h>

#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

#include "core_environment.h"
#include "kernel_sysdep.h"

globle void* sysdep_init_env(env_ref, struct symbol_table_node_t**);
