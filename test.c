#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BASE_TYPE uint16_t
#include "DIY_BigNum.h"


int main(){

    char c[200];

    Bign n1;
    Bign_init(&n1,16);

    Bign n2;
    Bign_init(&n2,16);

    Bign res;
    Bign_init(&res,16);

    //Bign_from_int(&n1, 123);
    /* Bign_from_hexstr(&n1, "100000000");
    Bign_print_hex(&n1);
    Bign_to_hexstr(&n1, c,200);

    printf("str: %s \n",c);

    Bign_from_hexstr(&n2, "1");

    Bign_print_hex(&n2);
    int rem;

    rem = Bign_sub(&n2, &n1, &res);
    Bign_print_hex(&res);
    printf("resm: %d",rem); */
    Bign_from_hexstr(&n1, "0x123123123123123123123123123123123123123123");
    Bign_print_hex(&n1);
    Bign_to_hexstr(&n1, c,200);

    printf("str: %s \n",c);

    Bign_from_hexstr(&n2, "0x123123123123123123123123123123");

    Bign_print_hex(&n2);
    
    Bign_sub(&n2, &n1, &res);
    Bign_print_hex(&res);
    //12 3123 1231 2324 6246 2462 4624 6246 2462 4624 6246
    

    printf("\n");
    printf("\n");
    printf("\n");
    
    uint32_t a = UINT32_MAX, b=1, res2;          
    if(__builtin_sub_overflow(b, a, &res2)){      
        printf("returned TRUE,  res: %u\n",res2); 
    } else {
        printf("returned FALSE,  res: %u\n",res2);
    }

    
    
    Bign_free_data(&n1);
    Bign_free_data(&n2);
}