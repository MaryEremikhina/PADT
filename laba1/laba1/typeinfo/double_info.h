#pragma once
#include "typeinfo.h"

void double_mult_scalar(void* n, double* number, void* result);
void double_add(void* n1, void* n2, void* result);
void double_subtraction(void* n1, void* n2, void* result);
void double_mult(void* n1, void* n2, void* result);
void double_del(void* n1, void* n2, void* result);
void* double_create(void* number);
void* double_create_zero(void);
int double_compare(void* n1, void* n2);

static TypeInfo TypeInfoDouble = {
    .mult_scalar = double_mult_scalar,
    .add = double_add,
    .subtraction = double_subtraction,
    .mult = double_mult,
    .del = double_del,
    .create = double_create,
    .create_zero = double_create_zero,
    .compare = double_compare
};
