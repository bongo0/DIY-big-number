#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BIGN_WORD_SIZE 8
#include "DIY_BigNum.h"

int main(){

    Bign n1, n2, n3;
    
    Bign_init(&n1,5192); // number n needs ceil(log2(n))+1 bits
    Bign_init(&n2,5192);

    int E = 100000 + 2;
    char *_2 = malloc(E*sizeof(char));memset(_2,'0',E);_2[0] = '2';_2[E-1] = '\0';

    Bign_from_decimal_str(&n1,_2);

    //printf("2e40__hex:\n");
    //Bign_print_hex(&n1);

    Bign_isqrt(&n1,&n2);

    //printf("sqrt2e40__hex:\n");
    //Bign_print_hex(&n2);

    printf("sqrt2e_50k_decimal:\n");
    Bign_print_decimal(&n2);

    Bign_free_data(&n1);
    Bign_free_data(&n2);

}