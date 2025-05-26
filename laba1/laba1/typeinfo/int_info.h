#pragma once
#include "typeinfo.h"

void int_mult_scalar(void* n, double* number, void* result);
void int_add(void* n1, void* n2, void* result);
void int_subtraction(void* n1, void* n2, void* result);
void int_mult(void* n1, void* n2, void* result);
void int_del(void* n1, void* n2, void* result);
void* int_create(void* number);
void* int_create_zero(void);
int int_compare(void* n1, void* n2);

static TypeInfo TypeInfoInt = {
    .mult_scalar = int_mult_scalar,
    .add = int_add,
    .subtraction = int_subtraction,
    .mult = int_mult,
    .del = int_del,
    .create = int_create,
    .create_zero = int_create_zero,
    .compare = int_compare
};
