#ifndef __DIY_BIGNUM_H__
#define __DIY_BIGNUM_H__

#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#ifdef _MSC_VER
    #include <intrin.h>
#else
    #include <x86intrin.h>
#endif

#ifndef BIGN_WORD_SIZE
    #define BIGN_WORD_SIZE 4
#endif

#if (BIGN_WORD_SIZE == 1)
    #define BIGN_BASE_TYPE          uint8_t
    #define BIGN_FORMAT_HEX_OUT     "%.2lx"
    #define BIGN_BASE_TYPE_HIGH_BIT 0x80
    #define BIGN_BASE_TYPE_MAX      0xff
#elif (BIGN_WORD_SIZE == 2)
    #define BIGN_BASE_TYPE          uint16_t
    #define BIGN_FORMAT_HEX_OUT     "%.4lx"
    #define BIGN_BASE_TYPE_HIGH_BIT 0x8000
    #define BIGN_BASE_TYPE_MAX      0xffff
#elif (BIGN_WORD_SIZE == 4)
    #define BIGN_BASE_TYPE          uint32_t
    #define BIGN_FORMAT_HEX_OUT     "%.8lx"
    #define BIGN_BASE_TYPE_HIGH_BIT 0x80000000
    #define BIGN_BASE_TYPE_MAX      0xffffffff
#elif (BIGN_WORD_SIZE == 8)
    #define BIGN_BASE_TYPE          uint64_t
    #define BIGN_FORMAT_HEX_OUT     "%.16lx"
    #define BIGN_BASE_TYPE_HIGH_BIT 0x8000000000000000
    #define BIGN_BASE_TYPE_MAX      0xffffffffffffffff
#endif

#define TYPE_SIZE sizeof(BIGN_BASE_TYPE)
#define TYPE_SIZE_BITS (8*sizeof(BIGN_BASE_TYPE))

#define PUSH_IGNORE_WARNING_WFORMAT _Pragma("GCC diagnostic push")\
                            _Pragma("GCC diagnostic ignored \"-Wformat=\"")

#define POP_IGNORE_WARNING _Pragma("GCC diagnostic pop")

typedef enum {LESS_THAN,EQUAL,BIGGER_THAN} comparison;

typedef struct _Bign
{
    BIGN_BASE_TYPE* data;
    size_t size;
} Bign;

/*--------------------------------------------------
                SETUP
--------------------------------------------------*/

Bign* Bign_new(size_t sizeof_data)
{
    Bign* bn = malloc(sizeof(Bign));
    bn->data = calloc(sizeof_data,TYPE_SIZE);
        if(bn->data == NULL)
            perror("alloc fail\n");
    bn->size = sizeof_data;
    return bn;
}

void Bign_free_data(Bign* bn)
{
    free(bn->data);
}

void Bign_init(Bign* bn, size_t sizeof_data)
{
    bn->data = calloc(sizeof_data,TYPE_SIZE);
        if(bn->data == NULL)
            perror("alloc fail\n");
    bn->size = sizeof_data;
}

void Bign_realloc(Bign* bn, size_t sizeof_data)
{
    bn->data = realloc(bn->data, sizeof_data*TYPE_SIZE);
    bn->size = sizeof_data;
}

void Bign_cpy(Bign* src, Bign* dest)
{
    if(src->size > dest->size) Bign_realloc(dest,src->size);
    for(int i = 0; i < src->size; i++)
        dest->data[i] = src->data[i];
}

/*--------------------------------------------------
                    UTILITY
--------------------------------------------------*/

/* Substract one from the input number*/
void Bign_Substract_one(Bign* bn)
{
    BIGN_BASE_TYPE tmp,res;

    for(int i = 0; i < bn->size; i++){
        tmp = bn->data[i];
        res = tmp - 1;
        bn->data[i] = res;
        if(res < tmp)
            return;
    }
}

/* Add one to the input number*/
void Bign_Add_one(Bign* bn)
{
    BIGN_BASE_TYPE tmp,res;

    for(int i = 0; i < bn->size; i++){
        tmp = bn->data[i];
        res = tmp + 1;
        bn->data[i] = res;
        if(res > tmp)
            return;
    }
}

int Bign_equals_zero(Bign* bn)
{
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
int Bign_Compare(Bign* n1, Bign* n2)
{
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

void Bign_shift_left_one(Bign* n1, Bign* result)
{
    for(int i = result->size-1; i>0; i--)
        result->data[i] = (n1->data[i] << 1) | (n1->data[i-1] >> (TYPE_SIZE_BITS-1));
    result->data[0] = n1->data[0] << 1;
}

void Bign_shift_right_one(Bign* n1, Bign* result)
{
    for(int i = 0; i < result->size-1; i++)
        result->data[i] = (n1->data[i] >> 1) | (n1->data[i+1] << (TYPE_SIZE_BITS-1));
    result->data[result->size-1] = n1->data[result->size-1] >> 1;
}

/* Bit shift left n words (TYPE_SIZE_BITS)*/
void Bign_shift_left_words(Bign* n1, Bign* result, int nwords)
{
    for(int i = result->size-1; i >= nwords; i--)
        result->data[i] = n1->data[i-nwords];
    for(int i = 0; i<nwords; i++)
        result->data[0]=0;
}

/* Bit shift right n words (TYPE_SIZE_BITS) */
void Bign_shift_right_words(Bign* n1, Bign* result, int nwords)
{
    for(int i = 0; i <= result->size-1-nwords; i++)
        result->data[i] = n1->data[i+nwords];
    for(int i = result->size-nwords; i < result->size; i++)
        result->data[i]=0;
}

/*--------------------------------------------------
                READ WRITE
--------------------------------------------------*/

/* Sets the number to zero */
void Bign_zero(Bign* bn)
{
    memset(bn->data,(BIGN_BASE_TYPE)0,bn->size*TYPE_SIZE);
}

/* Makes a number from int */
void Bign_from_int(Bign* bn, unsigned int n)
{
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
        default:
            bn->data[0] = n;
            break;
    }
}

/* Returns the number as int */
int Bign_to_int(Bign* bn)
{
    int n = 0;
    for(int i = 0; i < sizeof(int)/TYPE_SIZE; i++){
        n += bn->data[i] << i*TYPE_SIZE_BITS;
    }
    return n;
}

/* Read hexadecimal number from string */
void Bign_from_hexstr(Bign* bn, char* str)
{

    BIGN_BASE_TYPE tmp;
    int len = strlen(str)-1;
    int cap = len - bn->size * TYPE_SIZE * 2;
    if(cap < 0) cap = 0;

    for(int i = len; i >= cap;--i){
        tmp=0;
        sscanf(&str[i],"%1hhx",&tmp);
        bn->data[(len-i)/(2*TYPE_SIZE)] += tmp << ((len-i)%(2*TYPE_SIZE)*4);
    }

}

/* Write the number as hexadecimal to string thats length is str_size */
// should redo this
void Bign_to_hexstr(Bign* bn, char* str, int str_size)
{
    memset(str,'0',sizeof(char)*str_size);
    int cap = ceil(str_size/(float)(TYPE_SIZE*2));
    
    if(cap > bn->size)
        cap = bn->size;

    //char format[12];
    //sprintf(format,"%%.0%lulx",2*TYPE_SIZE);
    char tmp[65];
    int j = str_size - 1 - 2*TYPE_SIZE;
    
    for(int i = 0; i < cap; i++){
        sprintf(tmp, BIGN_FORMAT_HEX_OUT, bn->data[i]);
        
        strncpy(&str[j],tmp,2*TYPE_SIZE); // probably bad idea
        j -= 2*TYPE_SIZE;
    }

    sprintf(&str[str_size-1],"\0");
    char* first_nonzero=str;
    while(*first_nonzero && *first_nonzero == '0')
        first_nonzero++;

    strcpy(str,first_nonzero);

}

char* Bign_to_decimal_str(const Bign *bn)
{
    
    //space for Double dabble
    const size_t bits = bn->size*TYPE_SIZE_BITS;
    int digits = floor(bits*log10(2)) + 1;
    size_t space = ceil(( bits + 4*digits ) / (double)TYPE_SIZE_BITS);

    //printf("space %d\n",space);

    Bign tmp;
    Bign_init(&tmp, bn->size + space);
    Bign_cpy(bn,&tmp);
    
    for(size_t i = 0; i < bits; i++){
        for(int k = bn->size;k<tmp.size;k++){
            if( (tmp.data[k] & 0x0f) > 4      ) (tmp.data[k]) += 3; // 0000 0011 low bits
            if( (tmp.data[k] & 0xf0) > (4<<4) ) (tmp.data[k]) += (3<<4); // 0011 0000 high bits etc..
        #if (BIGN_WORD_SIZE > 1)
            if( (tmp.data[k] & 0x0f00) > (4<<8) ) (tmp.data[k]) += (3<<8);
            if( (tmp.data[k] & 0xf000) > (4<<12)) (tmp.data[k]) += (3<<12); 
        #endif
        #if (BIGN_WORD_SIZE > 2)
            if( (tmp.data[k] & 0x000f0000) > (4<<16)    ) (tmp.data[k]) += (3<<16);
            if( (tmp.data[k] & 0x00f00000) > (4<<20)    ) (tmp.data[k]) += (3<<20);
            if( (tmp.data[k] & 0x0f000000) > (4<<24)    ) (tmp.data[k]) += (3<<24);
            if( (tmp.data[k] & 0xf0000000) > (4<<28)    ) (tmp.data[k]) += (3<<28); 
        #endif
        #if (BIGN_WORD_SIZE > 4)
            if( (tmp.data[k] & 0x0000000f00000000) > (4l<<32)) (tmp.data[k]) += (3l<<32);
            if( (tmp.data[k] & 0x000000f000000000) > (4l<<36)) (tmp.data[k]) += (3l<<36);
            if( (tmp.data[k] & 0x00000f0000000000) > (4l<<40)) (tmp.data[k]) += (3l<<40);
            if( (tmp.data[k] & 0x0000f00000000000) > (4l<<44)) (tmp.data[k]) += (3l<<44); 
            if( (tmp.data[k] & 0x000f000000000000) > (4l<<48)) (tmp.data[k]) += (3l<<48);
            if( (tmp.data[k] & 0x00f0000000000000) > (4l<<52)) (tmp.data[k]) += (3l<<52);
            if( (tmp.data[k] & 0x0f00000000000000) > (4l<<56)) (tmp.data[k]) += (3l<<56);
            if( (tmp.data[k] & 0xf000000000000000) > (4l<<60)) (tmp.data[k]) += (3l<<60);  
        #endif
        }
        Bign_shift_left_one(&tmp,&tmp);
    }

    char *result = malloc((digits+2)*sizeof(char));
    memset(result,'0',(digits+1)*sizeof(char));
    result[digits+1]='\0';
    char* ptr = result;

    int k = tmp.size-1;
    while(tmp.data[k]==0) k--; // get rid of 0 on the front
    for(;k>=bn->size;k--){
        
        for(int j = TYPE_SIZE_BITS-4;j>=0;j-=4){
            (*ptr) += ( (tmp.data[k] >> j) & 0xf);
            ptr++;
        }
    }
    (*ptr) = '\0';

    //resize
    result = realloc(result, (ptr - result + 1 ));

    printf("\n");        
    Bign_free_data(&tmp);
    return result;
}

/* Prints the number as hexadecimal to the std out */
void Bign_print_hex(Bign* bn)
{
    for(int i = bn->size-1; i >= 0; i--){
        printf(BIGN_FORMAT_HEX_OUT,bn->data[i]);
    }
    printf("\n");
}

void Bign_print_decimal(const Bign *bn)
{
    
    //space for Double dabble
    const size_t bits = bn->size*TYPE_SIZE_BITS;
    int digits = floor(bits*log10(2)) + 1;
    size_t space = ceil(( bits + 4*digits ) / (double)TYPE_SIZE_BITS);

    //printf("space %d\n",space);

    Bign tmp;
    Bign_init(&tmp, bn->size + space);
    Bign_cpy(bn,&tmp);
    
    for(size_t i = 0; i < bits; i++){
        for(int k = bn->size;k<tmp.size;k++){
            if( (tmp.data[k] & 0x0f) > 4      ) (tmp.data[k]) += 3; // 0000 0011 low bits
            if( (tmp.data[k] & 0xf0) > (4<<4) ) (tmp.data[k]) += (3<<4); // 0011 0000 high bits etc..
        #if (BIGN_WORD_SIZE > 1)
            if( (tmp.data[k] & 0x0f00) > (4<<8) ) (tmp.data[k]) += (3<<8);
            if( (tmp.data[k] & 0xf000) > (4<<12)) (tmp.data[k]) += (3<<12); 
        #endif
        #if (BIGN_WORD_SIZE > 2)
            if( (tmp.data[k] & 0x000f0000) > (4<<16)    ) (tmp.data[k]) += (3<<16);
            if( (tmp.data[k] & 0x00f00000) > (4<<20)    ) (tmp.data[k]) += (3<<20);
            if( (tmp.data[k] & 0x0f000000) > (4<<24)    ) (tmp.data[k]) += (3<<24);
            if( (tmp.data[k] & 0xf0000000) > (4<<28)    ) (tmp.data[k]) += (3<<28); 
        #endif
        #if (BIGN_WORD_SIZE > 4)
            if( (tmp.data[k] & 0x0000000f00000000) > (4l<<32)) (tmp.data[k]) += (3l<<32);
            if( (tmp.data[k] & 0x000000f000000000) > (4l<<36)) (tmp.data[k]) += (3l<<36);
            if( (tmp.data[k] & 0x00000f0000000000) > (4l<<40)) (tmp.data[k]) += (3l<<40);
            if( (tmp.data[k] & 0x0000f00000000000) > (4l<<44)) (tmp.data[k]) += (3l<<44); 
            if( (tmp.data[k] & 0x000f000000000000) > (4l<<48)) (tmp.data[k]) += (3l<<48);
            if( (tmp.data[k] & 0x00f0000000000000) > (4l<<52)) (tmp.data[k]) += (3l<<52);
            if( (tmp.data[k] & 0x0f00000000000000) > (4l<<56)) (tmp.data[k]) += (3l<<56);
            if( (tmp.data[k] & 0xf000000000000000) > (4l<<60)) (tmp.data[k]) += (3l<<60);  
        #endif
        }
        Bign_shift_left_one(&tmp,&tmp);
    }
  
    int k = tmp.size-1;
    while(tmp.data[k]==0) k--;
    for(;k>=bn->size;k--){
        printf(BIGN_FORMAT_HEX_OUT,tmp.data[k]);
    }
    printf(" \n");        
    Bign_free_data(&tmp);
}

/*--------------------------------------------------
                BASIC OPERATIONS
--------------------------------------------------*/

uint8_t Bign_add(Bign* n1, Bign* n2, Bign* result)
{
    int8_t carry = 0;    
    for(size_t i = 0; i < result->size; i++){
        // dont know if there is _addcarry_u8 /_u16 on gcc
        #if (BIGN_WORD_SIZE == 1)
            #ifdef _MSC_VER
                carry = _addcarry_u8(carry,n1->data[i], n2->data[i], &(result->data[i]));
            #else
                if(__builtin_add_overflow(n1->data[i] + carry, n2->data[i], &(result->data[i]) )){
                    carry = 1;
                } else {
                    carry = 0;
                }
            #endif
        #elif (BIGN_WORD_SIZE == 2)
            #ifdef _MSC_VER
                carry = _addcarry_u16(carry,n1->data[i], n2->data[i], &(result->data[i]));
            #else
                if(__builtin_add_overflow(n1->data[i] + carry, n2->data[i], &(result->data[i]) )){
                    carry = 1;
                } else {
                    carry = 0;
                }
            #endif
        #elif (BIGN_WORD_SIZE == 4)
            carry = _addcarry_u32(carry,n1->data[i], n2->data[i], &(result->data[i]));
        #elif (BIGN_WORD_SIZE == 8)
            carry = _addcarry_u64(carry,n1->data[i], n2->data[i], &(result->data[i]));
        #endif
    }
    return carry;
}

uint8_t Bign_sub(Bign* n1, Bign* n2, Bign* result)
{    
    uint8_t borrow = 0;
    for(size_t i = 0; i < result->size; i++){
        // dont know if there is _subborrow_u8 /_u16 on gcc 
        #if (BIGN_WORD_SIZE == 1)
            #ifdef _MSC_VER
                borrow = _subborrow_u8(borrow,n2->data[i], n1->data[i], &(result->data[i]));
            #else
                if(__builtin_sub_overflow(n1->data[i], n2->data[i] + borrow, &(result->data[i]))){
                    borrow = 1;
                } else {
                    borrow = 0;
                }
            #endif    
        
        #elif (BIGN_WORD_SIZE == 2)
            #ifdef _MSC_VER
                borrow = _subborrow_u16(borrow,n2->data[i], n1->data[i], &(result->data[i]));
            #else
                if(__builtin_sub_overflow(n1->data[i], n2->data[i] + borrow, &(result->data[i]))){
                    borrow = 1;
                } else {
                    borrow = 0;
                }
            #endif
        #elif (BIGN_WORD_SIZE == 4)
            borrow = _subborrow_u32(borrow,n2->data[i], n1->data[i], &(result->data[i]));
        #elif (BIGN_WORD_SIZE == 8)
            borrow = _subborrow_u64(borrow,n2->data[i], n1->data[i], &(result->data[i]));
        #endif
    }
    return borrow;
}

uint8_t Bign_mult(Bign* n1, Bign* n2, Bign* result)
{
    //TODO
    return 0;
}

uint8_t Bign_div(Bign* n1, Bign* n2, Bign* result)
{
    //TODO   
    return 0; 
}

uint8_t Bign_mod(Bign* n1, Bign* n2, Bign* result)
{
    //TODO
    return 0;
}


/*--------------------------------------------------
                BIT OPERATIONS
--------------------------------------------------*/

void Bign_shift_left(Bign* n1, Bign* result, const int shift_bits)
{
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

void Bign_shift_right(Bign* n1, Bign* result, int shift_bits)
{
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

void Bign_and(Bign* n1, Bign* n2, Bign* result)
{
    int cap = (n1->size < n2->size ? n1->size : n2->size);
    cap = (cap < result->size ? cap : result->size);
    
    for(int i = 0; i < cap; i++){
        result->data[i] = n1->data[i] & n2->data[i];
    }

}

void Bign_or(Bign* n1, Bign* n2, Bign* result)
{
    int cap = (n1->size < n2->size ? n1->size : n2->size);
    cap = (cap < result->size ? cap : result->size);
    
    for(int i = 0; i < cap; i++){
        result->data[i] = n1->data[i] | n2->data[i];
    }
}

void Bign_xor(Bign* n1, Bign* n2, Bign* result)
{
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
int Bign_lessThan(Bign* n1, Bign* n2)
{
    return (Bign_Compare(n1,n2) == LESS_THAN);
}

/*      n1 > n2     */
int Bign_biggerThan(Bign* n1, Bign* n2)
{
    return (Bign_Compare(n1,n2) == BIGGER_THAN);
}

/*      n1 == n2     */
int Bign_equals(Bign* n1, Bign* n2)
{
    return (Bign_Compare(n1,n2) == EQUAL);
}

/*      n1 <= n2     */
int Bign_lessOrEquals(Bign* n1, Bign* n2)
{
    return (Bign_equals(n1,n2) || Bign_lessThan(n1,n2));
}

/*      n1 >= n2     */
int Bign_biggerOrEquals(Bign* n1, Bign* n2)
{
    return (Bign_equals(n1,n2) || Bign_biggerThan(n1,n2));
}


/*--------------------------------------------------
                MATH OPERATIONS
--------------------------------------------------*/


int Bign_isqrt(Bign *num, Bign *res)
{
    // temps
    Bign bit, res_plus_bit;
    Bign_init(&bit, num->size);
    Bign_init(&res_plus_bit, num->size);

    // resize if needed
    if(num->size != res->size) Bign_realloc(res, num->size);
    // zero out the result
    Bign_zero(res);

    //#### ALGORITHM ####
    Bign_from_int(&bit,1);
    Bign_shift_left(&bit,&bit, (num->size - 1)*TYPE_SIZE_BITS + TYPE_SIZE_BITS - 2);
    
    while(Bign_biggerThan(&bit, num)){
        Bign_shift_right(&bit,&bit,2);
    }

    while(!Bign_equals_zero(&bit)){
        Bign_add(res,&bit, &res_plus_bit);
    
        if(Bign_biggerOrEquals(num, &res_plus_bit)){
            Bign_sub(num, &res_plus_bit, num);
            Bign_shift_right_one(res,res);
            Bign_add(res,&bit,res);
        }else{
            Bign_shift_right_one(res,res);
        }

        Bign_shift_right(&bit,&bit,2);
    }
    //###################

    Bign_free_data(&bit);
    Bign_free_data(&res_plus_bit);
    return 1;
}

#endif //__DIY_BIGNUM_H__