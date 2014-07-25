#include<stdio.h>

#include "kernel_constants.h"
#include "core_env.h"
#include "type_lexeme.h"

int main(int argc, char *argv[])
{
    struct env_t* env = (struct env_t*) env_create(NULL);

    printf("Initialized global env at %p\n", env);

    printf("Initialized symbol table at %p\n", NULL);
    return(1);
}

