#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BIGN_WORD_SIZE 8
#include "DIY_BigNum.h"

#include <math.h>

int main(){

    char c[200];

    Bign n1, n2, n3;
    
    Bign_init(&n1,4);
    Bign_init(&n2,4);
    Bign_init(&n3,4);

    Bign_from_hexstr(&n1, "0xffffffffffff");//"0x1234567890abcdeffedcba908765421");
    Bign_from_hexstr(&n2, "0x123123123123123123123123123123");
    Bign_from_hexstr(&n3, "0xfffffffffffffffff000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

    printf("n1: \n");
    Bign_print_hex(&n1);
    printf("n2: \n");
    Bign_print_hex(&n2);
    printf("n3: \n");
    Bign_print_hex(&n3);

    Bign_add(&n1, &n2, &n3);

    printf("n1 + n2: \n");
    Bign_print_hex(&n3);

    Bign_print_decimal(&n1);

    char *dec; 
    dec = Bign_to_decimal_str(&n1);

    printf("%s \n",dec);

    Bign_free_data(&n1);
    Bign_free_data(&n2);
    Bign_free_data(&n3);

}