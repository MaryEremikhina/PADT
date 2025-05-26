#pragma once

typedef struct {
    void (*mult_scalar)(void* n, double* number, void* result); // умножение на число
    void (*add)(void* n1, void* n2, void* result); // сложение
    void (*subtraction)(void* n1, void* n2, void* result); // вычитание
    void (*mult)(void* n1, void* n2, void* result); // умножение
    void (*del)(void* n1, void* n2, void* result); // деление
    void* (*create)(void* number); // создание числа
    void* (*create_zero)(void); // получение нуля
    int (*compare)(void* n1, void* n2); // сравнение
} TypeInfo;
