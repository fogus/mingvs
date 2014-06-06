#ifndef __TYPE_LEXEMES_H__
#define __TYPE_LEXEMES_H__

#ifdef LOCALE
#undef LOCALE
#endif

#ifdef __TYPE_LEXEMES_C__
#define LOCALE
#else
#define LOCALE extern
#endif

#include <stdlib.h>

#ifndef SYMBOL_HASH_SZ
#define SYMBOL_HASH_SZ          63559L
#endif

#endif
