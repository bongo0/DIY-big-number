#ifndef __DIY_BIGNUM_H__
#define __DIY_BIGNUM_H__

#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifndef BASE_TYPE
#define BASE_TYPE uint32_t
#endif

#define TYPE_SIZE sizeof(BASE_TYPE)
#define TYPE_SIZE_BITS (8*sizeof(BASE_TYPE))

#define PUSH_IGNORE_WARNING_WFORMAT _Pragma("GCC diagnostic push")\
                            _Pragma("GCC diagnostic ignored \"-Wformat=\"")

#define POP_IGNORE_WARNING _Pragma("GCC diagnostic pop")

typedef enum {LESS_THAN,EQUAL,BIGGER_THAN} comparison;

typedef struct _Bign
{
    BASE_TYPE* data;
    size_t size;
} Bign;

/*--------------------------------------------------
                SETUP
--------------------------------------------------*/

Bign* Bign_new(size_t sizeof_data){
    Bign* bn = malloc(sizeof(Bign));
    bn->data = (BASE_TYPE*)calloc(sizeof_data,TYPE_SIZE);
        if(bn->data == NULL)
            perror("alloc fail\n");
    bn->size = sizeof_data;
    return bn;
}

void Bign_free_data(Bign* bn){
    free(bn->data);
}

void Bign_init(Bign* bn, size_t sizeof_data){
    bn->data = (BASE_TYPE*)calloc(sizeof_data,TYPE_SIZE);
        if(bn->data == NULL)
            perror("alloc fail\n");
    bn->size = sizeof_data;
}

void Bign_realloc(Bign* bn, size_t sizeof_data){
    bn->data = realloc(bn->data, sizeof_data*TYPE_SIZE);
    bn->size = sizeof_data;
}

void Bign_cpy(Bign* src, Bign* dest){
    Bign_realloc(dest,src->size);
    for(int i = 0; i < src->size; i++)
        dest->data[i] = src->data[i];
}

/*--------------------------------------------------
                    UTILITY
--------------------------------------------------*/

/* Substract one from the input number*/
void Bign_Substract_one(Bign* bn){
    BASE_TYPE tmp,res;

    for(int i = 0; i < bn->size; i++){
        tmp = bn->data[i];
        res = tmp - 1;
        bn->data[i] = res;
        if(res < tmp)
            return;
    }
}

/* Add one to the input number*/
void Bign_Add_one(Bign* bn){
    BASE_TYPE tmp,res;

    for(int i = 0; i < bn->size; i++){
        tmp = bn->data[i];
        res = tmp + 1;
        bn->data[i] = res;
        if(res > tmp)
            return;
    }
}

int Bign_equals_zero(Bign* bn){
    for(int i = 0; i < bn->size; i++){
        if(bn->data[i])
            return 0;
    }
    return 1;
}

/*helper compare for lessthan greaterthan etc. 
    n1 > n2 return BIGGER_THAN
    n1 < n2 return LESS_THAN
    n1 == n2 return EQUAL
*/
int Bign_Compare(Bign* n1, Bign* n2){
    int cap = n1->size;
    if(n1->size < n2->size){
        for(int i = n2->size-1; i > n1->size-1; i--){
            if(n2->data[i] > 0)
                return LESS_THAN;
        }
        cap = n1->size;
    } else if (n1->size > n2->size){
        for(int i = n1->size-1; i > n2->size-1; i--){
            if(n1->data[i] > 0)
                return BIGGER_THAN;
        }
        cap = n2->size;
    }

    for(int i = cap-1; i>=0;i--){
        if(n1->data[i] > n2->data[i])
            return BIGGER_THAN;
        if(n1->data[i] < n2->data[i])
            return LESS_THAN;
    }
    return EQUAL;
}

void Bign_shift_left_one(Bign* n1, Bign* result){
    for(int i = result->size-1; i>0; i--)
        result->data[i] = (n1->data[i] << 1) | (n1->data[i-1] >> (TYPE_SIZE_BITS-1));
    result->data[0] = n1->data[0] << 1;
}

void Bign_shift_right_one(Bign* n1, Bign* result){
    for(int i = 0; i < result->size-1; i++)
        result->data[i] = (n1->data[i] >> 1) | (n1->data[i+1] << (TYPE_SIZE_BITS-1));
    result->data[result->size-1] = n1->data[result->size-1] >> 1;
}

/* Bit shift left n words (TYPE_SIZE_BITS)*/
void Bign_shift_left_words(Bign* n1, Bign* result, int nwords){
    for(int i = result->size-1; i >= nwords; i--)
        result->data[i] = n1->data[i-nwords];
    for(int i = 0; i<nwords; i++)
        result->data[0]=0;
}

/* Bit shift right n words (TYPE_SIZE_BITS) */
void Bign_shift_right_words(Bign* n1, Bign* result, int nwords){
    for(int i = 0; i <= result->size-1-nwords; i++)
        result->data[i] = n1->data[i+nwords];
    for(int i = result->size-nwords; i < result->size; i++)
        result->data[i]=0;
}

/*--------------------------------------------------
                READ WRITE
--------------------------------------------------*/

/* Sets the number to zero */
void Bign_zero(Bign* bn){
    memset(bn->data,0,bn->size*TYPE_SIZE);
}

/* Makes a number from int */
void Bign_from_int(Bign* bn, unsigned int n){
    Bign_zero(bn);
    switch(sizeof(int)/TYPE_SIZE){
        case 4:
            bn->data[0] = (n & 0xff);
            bn->data[1] = (n & 0xff00)>>8;
            bn->data[2] = (n & 0xff0000)>>16;
            bn->data[3] = (n & 0xff000000)>>24;
            break;
        case 2:
            bn->data[0] = (n & 0xffff);
            bn->data[1] = (n & 0xffff0000)>>16;
            break;
        case 1:
            bn->data[0] = n;
            break;
    }
}

/* Returns the number as int */
int Bign_to_int(Bign* bn){
    int n = 0;
    for(int i = 0; i < sizeof(int)/TYPE_SIZE; i++){
        n += bn->data[i] << i*TYPE_SIZE_BITS;
    }
    return n;
}

/* Read hexadecimal number from string */
void Bign_from_hexstr(Bign* bn, char* str){
    BASE_TYPE tmp;
    int len = strlen(str)-1;

    for(int i = len; i >= 0;i--){
        tmp=0;
        PUSH_IGNORE_WARNING_WFORMAT;
        sscanf(&str[i],"%1hhx",&tmp);
        POP_IGNORE_WARNING;
        bn->data[(len-i)/(2*TYPE_SIZE)]+=tmp<<((len-i)%(2*TYPE_SIZE)*4);
    }
}

/* Write the number as hexadecimal to string thats length is str_size */
void Bign_to_hexstr(Bign* bn, char* str, int str_size){
    memset(str,'0',sizeof(char)*str_size);
    int cap = ceil(str_size/(float)(TYPE_SIZE*2));
    
    if(cap > bn->size)
        cap = bn->size;

    char format[12];
    sprintf(format,"%%.0%lulx",2*TYPE_SIZE);
    char tmp[65];
    int j = str_size - 1 - 2*TYPE_SIZE;
    
    for(int i = 0; i < cap; i++){
        sprintf(tmp, format, bn->data[i]);
        
        strncpy(&str[j],tmp,2*TYPE_SIZE);
        j -= 2*TYPE_SIZE;
    }

    sprintf(&str[str_size-1],"\0");
    char* first_nonzero=str;
    while(*first_nonzero && *first_nonzero == '0')
        first_nonzero++;

    strcpy(str,first_nonzero);

}

/* Prints the number as hexadecimal to the std out */
void Bign_print_hex(Bign* bn){
    char format[12];
    sprintf(format,"%%.0%lulx ",2*TYPE_SIZE);

    for(int i = bn->size-1; i >= 0; i--){
        printf(format,bn->data[i]);
    }
    printf("\n");
}

/*--------------------------------------------------
                BASIC OPERATIONS
--------------------------------------------------*/

int Bign_add(Bign* n1, Bign* n2, Bign* result)
{
    Bign_zero(result);
    int8_t carry = 0;
    
    for(size_t i = 0; i < result->size; i++){
        if(__builtin_add_overflow(n1->data[i] + carry, n2->data[i], &(result->data[i]) )){
            carry = 1;
        } else {
            carry = 0;
        }
    }

    return carry;
}

int Bign_sub(Bign* n1, Bign* n2, Bign* result){
    
    Bign_zero(result);
    int8_t borrow = 0;

    for(size_t i = 0; i < result->size; i++){
        if(__builtin_sub_overflow(n1->data[i], n2->data[i] + borrow, &(result->data[i]))){
            borrow = 1;
        } else {
            borrow = 0;
        }
    }
    return borrow;

}

int Bign_mult(Bign* n1, Bign* n2, Bign* result){
    //TODO
}

void Bign_div(Bign* n1, Bign* n2, Bign* result){
    //TODO    
}

void Bign_mod(Bign* n1, Bign* n2, Bign* result){
    //TODO
}


/*--------------------------------------------------
                BIT OPERATIONS
--------------------------------------------------*/

void Bign_shift_left(Bign* n1, Bign* result, const int shift_bits){
    int shift_words = shift_bits / TYPE_SIZE_BITS;
    int bits = shift_bits;

    // shift first as many words as needed
    if(shift_words){
        Bign_shift_left_words(n1,result,shift_words);
        bits = shift_bits - (TYPE_SIZE_BITS*shift_words);
    } else {
        Bign_cpy(n1,result);
    }

    // then shift the rest
    int cap = (n1->size < result->size ? n1->size : result->size);
    for(int i = cap-1; i > 0; i--)
        result->data[i] = (result->data[i] << bits) | (result->data[i-1] >> (TYPE_SIZE_BITS-bits));
    result->data[0] <<= bits;
}

void Bign_shift_right(Bign* n1, Bign* result, int shift_bits){
    int shift_words = shift_bits / TYPE_SIZE_BITS;
    int bits = shift_bits;

    // shift first as many words as needed
    if(shift_words){
        Bign_shift_right_words(n1,result,shift_words);
        bits = shift_bits - (TYPE_SIZE_BITS*shift_words);
    } else {
        Bign_cpy(n1,result);
    }

    // then shift the rest
    for(int i = 0; i < result->size-1; i++)
        result->data[i] = (result->data[i] >> bits) | (result->data[i+1] << (TYPE_SIZE_BITS-bits));
    result->data[result->size-1] >>= bits;
}

void Bign_and(Bign* n1, Bign* n2, Bign* result){
    int cap = (n1->size < n2->size ? n1->size : n2->size);
    cap = (cap < result->size ? cap : result->size);
    
    for(int i = 0; i < cap; i++){
        result->data[i] = n1->data[i] & n2->data[i];
    }

}

void Bign_or(Bign* n1, Bign* n2, Bign* result){
    int cap = (n1->size < n2->size ? n1->size : n2->size);
    cap = (cap < result->size ? cap : result->size);
    
    for(int i = 0; i < cap; i++){
        result->data[i] = n1->data[i] | n2->data[i];
    }
}

void Bign_xor(Bign* n1, Bign* n2, Bign* result){
        int cap = (n1->size < n2->size ? n1->size : n2->size);
    cap = (cap < result->size ? cap : result->size);
    
    for(int i = 0; i < cap; i++){
        result->data[i] = n1->data[i] ^ n2->data[i];
    }
}

/*--------------------------------------------------
                COMPARE OPERATIONS
--------------------------------------------------*/

/*      n1 < n2     */
int Bign_lessThan(Bign* n1, Bign* n2){
    return (Bign_Compare(n1,n2) == LESS_THAN);
}

/*      n1 > n2     */
int Bign_biggerThan(Bign* n1, Bign* n2){
    return (Bign_Compare(n1,n2) == BIGGER_THAN);
}

/*      n1 == n2     */
int Bign_equals(Bign* n1, Bign* n2){
    return (Bign_Compare(n1,n2) == EQUAL);
}

/*      n1 <= n2     */
int Bign_lessOrEquals(Bign* n1, Bign* n2){
    return (Bign_equals(n1,n2) || Bign_lessThan(n1,n2));
}

/*      n1 >= n2     */
int Bign_biggerOrEquals(Bign* n1, Bign* n2){
    return (Bign_equals(n1,n2) || Bign_biggerThan(n1,n2));
}

#endif //__DIY_BIGNUM_H__