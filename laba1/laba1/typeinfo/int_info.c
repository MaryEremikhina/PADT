#include "int_info.h"
#include <stdlib.h>
#include <stdio.h>

void int_mult_scalar(void* n, double* number, void* result){
    *(double*)result = *number * *(int*)n;
}

void int_add(void* n1, void* n2, void* result){
    *(int*)result = *(int*)n1 + *(int*)n2;
}

void int_subtraction(void* n1, void* n2, void* result){
    *(int*)result = *(int*)n1 - *(int*)n2;
}

void int_mult(void* n1, void* n2, void* result){
    *(int*)result = *(int*)n1 * *(int*)n2;
}

void int_del(void* n1, void* n2, void* result){
    *(double*)result = *(int*)n1 / *(int*)n2;
}

void* int_create(void* number){
    void* n = malloc(sizeof(int*));
    *(int*)n = *(int*)number;
    return n;
}

void* int_create_zero(void){
    void* zero = malloc(sizeof(int*));
    *(int*)zero = 0;
    return int_create(zero);
}

int int_compare(void* n1, void* n2){
    if (*(int*)n1 != *(int*)n2){
        return 0;
    }
    return 1;
}
