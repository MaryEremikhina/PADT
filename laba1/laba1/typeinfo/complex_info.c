#include "complex_info.h"
#include "int_complex_info.h"
#include "double_complex_info.h"

#include <stdio.h>
#include <stdlib.h>

void complex_mult_scalar(void* n, double* number, void* result){
    Complex* complex_n = (Complex*)n;
    Complex* complex_result = (Complex*)result;
    complex_n->typeinfo->mult_scalar(complex_n->a, number, complex_result->a);
    complex_n->typeinfo->mult_scalar(complex_n->b, number, complex_result->b);
}
void complex_add(void* n1, void* n2, void* result){
    Complex* complex_n1 = (Complex*)n1;
    Complex* complex_n2 = (Complex*)n2;
    Complex* complex_result = (Complex*)result;
    if (complex_n1->typeinfo != complex_n2->typeinfo){
        printf("The type of complex is wrong");
    } else if (complex_n1->typeinfo != complex_result->typeinfo){
        printf("The wrong type of result");
    } else {
        complex_n1->typeinfo->add(complex_n1->a, complex_n2->a, complex_result->a);
        complex_n1->typeinfo->add(complex_n1->b, complex_n2->b, complex_result->b);
    }
}

void complex_subtraction(void* n1, void* n2, void* result){
    Complex* complex_n1 = (Complex*)n1;
    Complex* complex_n2 = (Complex*)n2;
    Complex* complex_result = (Complex*)result;
    if (complex_n1->typeinfo != complex_n2->typeinfo){
        printf("The type of complex is wrong");
    } else if (complex_n1->typeinfo != complex_result->typeinfo){
        printf("The wrong type of result");
    } else {
        complex_n1->typeinfo->subtraction(complex_n1->a, complex_n2->a, complex_result->a);
        complex_n1->typeinfo->subtraction(complex_n1->b, complex_n2->b, complex_result->b);
    }
}

void complex_mult(void* n1, void* n2, void* result){
    Complex* complex_n1 = (Complex*)n1;
    Complex* complex_n2 = (Complex*)n2;
    Complex* complex_result = (Complex*)result;
    if (complex_n1->typeinfo != complex_n2->typeinfo){
        printf("The type of complex is wrong");
    } else if (complex_n1->typeinfo != complex_result->typeinfo){
        printf("The wrong type of result");
    } else {
        complex_n1->typeinfo->mult(complex_n1->a, complex_n2->a, complex_result->a);
        complex_n1->typeinfo->mult(complex_n1->b, complex_n2->b, complex_result->b);
    }
}

void* complex_create(void* number){
    void* n = malloc(sizeof(Complex*));
    ((Complex*)number)->typeinfo = ((Complex*)n)->typeinfo;
    ((Complex*)n)->a = ((Complex*)n)->typeinfo->create(((Complex*)number)->a);
    ((Complex*)n)->b = ((Complex*)n)->typeinfo->create(((Complex*)number)->b);
    return n;
}

void* complex_create_zero(void){
    void* zero = malloc(sizeof(Complex*));
    ((Complex*)zero)->a = malloc(sizeof(double*));
    ((Complex*)zero)->b = malloc(sizeof(double*));
    ((Complex*)zero)->typeinfo = &ComplexTypeInfoDouble;
    *(double*)(((Complex*)zero)->a) = 0.0;
    *(double*)(((Complex*)zero)->b) = 0.0;
    return complex_create(zero);
}

int complex_compare(void* n1, void* n2){
    Complex* complex_n1 = (Complex*)n1;
    Complex* complex_n2 = (Complex*)n2;
    if (complex_n1->typeinfo != complex_n2->typeinfo){
        printf("The type of complex is wrong");
        return 0;
    }
    if (complex_n1->typeinfo->compare(complex_n1->a, complex_n2->a) && complex_n1->typeinfo->compare(complex_n1->b, complex_n2->b)){
        return 1;
    }
    return 0;
}
