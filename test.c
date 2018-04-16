#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BASE_TYPE uint64_t
#include "DIY_BigNum.h"


int main(){

    char c[200];

    Bign n1;
    Bign_init(&n1,4);

    Bign n2;
    Bign_init(&n2,4);

    Bign res;
    Bign_init(&res,4);

    //Bign_from_int(&n1, 123);
    Bign_from_hexstr(&n1, "0x123123123123123123123123123123123123123123");
    Bign_print_hex(&n1);
    Bign_to_hexstr(&n1, c,200);

    printf("str: %s \n",c);

    Bign_from_hexstr(&n2, "0x123123123123123123123123123123");

    Bign_print_hex(&n2);
    
    Bign_add(&n1, &n2, &res);
    Bign_print_hex(&res);


    printf("\n");
    printf("\n");
    printf("\n");
    
    uint32_t a = UINT32_MAX, b=11, res2;          
    if(__builtin_add_overflow(a, b, &res2)){      
        printf("returned TRUE,  res: %d\n",res2); 
    } else {
        printf("returned FALSE,  res: %d\n",res2);
    }

    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246
    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246
    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246
    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246
    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246

    printf("n    %.016lx \n", INT64_MAX);

    Bign_free_data(&n1);
    Bign_free_data(&n2);
}