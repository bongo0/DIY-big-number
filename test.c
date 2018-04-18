#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define BIGN_WORD_SIZE 4
#include "DIY_BigNum.h"


int main(){

    char c[200];

    Bign n1, n2, n3;
    
    Bign_init(&n1,16);
    Bign_init(&n2,16);
    Bign_init(&n3,16);

    Bign_from_hexstr(&n1, "0x123123123123123123123123123123123123123123");
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

    Bign_free_data(&n1);
    Bign_free_data(&n2);
    Bign_free_data(&n3);

}