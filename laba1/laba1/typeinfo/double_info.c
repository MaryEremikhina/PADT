#include "double_info.h"
#include <stdio.h>
#include <stdlib.h>

void double_mult_scalar(void* n, double* number, void* result){
    *(double*)result = *number * *(double*)n;
}

void double_add(void* n1, void* n2, void* result){
    *(double*)result = *(double*)n1 + *(double*)n2;
}

void double_subtraction(void* n1, void* n2, void* result){
    *(double*)result = *(double*)n1 - *(double*)n2;
}

void double_mult(void* n1, void* n2, void* result){
    *(double*)result = *(double*)n1 * *(double*)n2;
}

void double_del(void* n1, void* n2, void* result){
    *(double*)result = *(double*)n1 / *(double*)n2;
}

void* double_create(void* number){
    void* n = malloc(sizeof(double*));
    *(double*)n = *(double*)number;
    return n;
}

void* double_create_zero(void){
    void* zero = malloc(sizeof(double*));
    *(double*)zero = 0.0;
    return double_create(zero);
}

int double_compare(void* n1, void* n2){
    if (*(double*)n1 != *(double*)n2){
        return 0;
    }
    return 1;
}
