#pragma once
#include "typeinfo.h"

void complex_mult_scalar(void* n, double* number, void* result);
void complex_add(void* n1, void* n2, void* result);
void complex_subtraction(void* n1, void* n2, void* result);
void complex_mult(void* n1, void* n2, void* result);
void* complex_create(void* number);
void* complex_create_zero(void);
int complex_compare(void* n1, void* n2);

static TypeInfo TypeInfoComplex = {
    .mult_scalar = complex_mult_scalar,
    .add = complex_add,
    .subtraction = complex_subtraction,
    .mult = complex_mult,
    .create = complex_create,
    .create_zero = complex_create_zero,
    .compare = complex_compare
};

typedef struct {
    void (*mult_scalar)(void* n, double* number, void* result); // умножение на число
    void (*add)(void* n1, void* n2, void* result); // сложение
    void (*subtraction)(void* n1, void* n2, void* result); // вычитание
    void (*mult)(void* n1, void* n2, void* result); // умножение
    void* (*create)(void* number); // создание числа
    void* (*create_zero)(void); // получение нуля
    int (*compare)(void* n1, void* n2); // сравнение
} ComplexTypeInfo;

typedef struct {
    void* a;
    void* b;
    ComplexTypeInfo* typeinfo;
} Complex;
