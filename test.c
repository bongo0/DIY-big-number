#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define BASE_TYPE uint16_t
#include "DIY_BigNum.h"


int main(){

    char s[200];

    Bign n1;
    Bign_init(&n1,8);

    Bign n2;
    Bign_init(&n2,8);

    Bign_from_int(&n1, 123456789);
    Bign_print_hex(&n1);
    Bign_to_hexstr(&n1,s,200);
    printf("%s\n",s);

    int sb = 9;

    Bign_shift_left(&n1,&n2,sb);
    Bign_print_hex(&n2);
    Bign_to_hexstr(&n2,s,200);
    printf("%s\n",s);

    printf("int: %lx\n",123456789l);
    printf("int>>: %lx\n",123456789l<<sb);

    Bign_free_data(&n1);
    Bign_free_data(&n2);

}