#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "typeinfo/typeinfo.h"
#include "typeinfo/int_info.h"
#include "typeinfo/double_info.h"
#include "typeinfo/complex_info.h"
#include "typeinfo/int_complex_info.h"
#include "typeinfo/double_complex_info.h"

#define INPUT1 "/Users/meremikhina/Desktop/laba1/projectc/input1.txt"
#define INPUT2 "/Users/meremikhina/Desktop/laba1/projectc/input2.txt"
#define OUTPUT "/Users/meremikhina/Desktop/laba1/projectc/output.txt"

const char* global_error = "No errors"; // буфер ошибок
int complex_flag = 0; // флаг для определения типа комплексного числа

typedef struct {
    int n; // размер матрицы
    void** matrix; // матрица чисел
    TypeInfo* typeinfo; // указатель на тип элементов
} Matrix;

Matrix* matrixCreate(int size, TypeInfo* typeinfo){
    void** rmatrix = (void**)malloc(size * sizeof(void*));
    for (int i = 0; i < size; i++){
        if (typeinfo == &TypeInfoInt){
            rmatrix[i] = malloc(sizeof(int));
        } else if (typeinfo == &TypeInfoDouble){
            rmatrix[i] = malloc(sizeof(double));
        } else {
            rmatrix[i] = malloc(sizeof(Complex));
            if (complex_flag == 1){
                ((Complex*)rmatrix[i])->a = malloc(sizeof(double));
                ((Complex*)rmatrix[i])->b = malloc(sizeof(double));
                ((Complex*)rmatrix[i])->typeinfo = &ComplexTypeInfoDouble;
            } else {
                ((Complex*)rmatrix[i])->a = malloc(sizeof(int));
                ((Complex*)rmatrix[i])->b = malloc(sizeof(int));
                ((Complex*)rmatrix[i])->typeinfo = &ComplexTypeInfoInt;
            }
        }
    }
    Matrix* rm = malloc(sizeof(Matrix));
    rm->n = size;
    rm->matrix = rmatrix;
    rm->typeinfo = typeinfo;
    return rm;
}

void matrixFree(Matrix* m){
    for (int i = 0; i < m->n; i++){
            free(m->matrix[i]);
    }
    free(m->matrix);
}

int matrixGetSize(FILE* input){
    char buffer[256];
    int n = 0;
    if (fgets(buffer, sizeof(buffer), input)) {
        n = atoi(buffer);
    }
    return n;
}

TypeInfo* matrixGetType(FILE* input){
    char type[256];
    if (fgets(type, sizeof(type), input)){
        if (strcmp(type, "int\n") == 0){
            return &TypeInfoInt;
        } else if (strcmp(type, "double\n") == 0){
            return &TypeInfoDouble;
        } else if (strcmp(type, "int complex\n") == 0){
            return &TypeInfoComplex;
        } else {
            complex_flag = 1;
            return &TypeInfoComplex;
        }
    } else {
        return &TypeInfoInt;
    }
}

void matrixPrint(Matrix* m, FILE* output){
    if (strcmp(global_error, "No errors") == 0){
        int n = sqrt(m->n);
        fprintf(output, "%d\n", n);
        if (m->typeinfo == &TypeInfoInt){
            fprintf(output, "%s\n", "int");
        } else if (m->typeinfo == &TypeInfoDouble){
            fprintf(output, "%s\n", "double");
        } else {
            fprintf(output, "%s\n", "complex");
        }
        for (int i = 0; i < m->n; i++){
            if (i % n == 0 && i != 0){
                fprintf(output, "\n");
            }
            if (m->typeinfo == &TypeInfoInt){
                fprintf(output, "%d ", *(int*)m->matrix[i]);
            } else if (m->typeinfo == &TypeInfoDouble){
                fprintf(output, "%2.f ", *(double*)m->matrix[i]);
            } else {
                if (complex_flag == 1){
                    fprintf(output, "%2.f;%2.f ", *(double*)((Complex*)m->matrix[i])->a, *(double*)((Complex*)m->matrix[i])->b);
                } else {
                    fprintf(output, "%d;%d ", *(int*)((Complex*)m->matrix[i])->a, *(int*)((Complex*)m->matrix[i])->b);
                }
            }
        }
    } else {
        fprintf(output, "%s\n", global_error);
    }
    fprintf(output, "\n");
}

Matrix* matrixGetMatrix(FILE* input){
    int n = matrixGetSize(input);
    int size = n * n;
    TypeInfo* flag = matrixGetType(input);
    void** matrix = malloc(size * sizeof(void*));
    Matrix* m = NULL;
    m = (Matrix*)malloc(sizeof(Matrix));
    m->n = size;
    m->typeinfo = flag;
    if (flag == &TypeInfoInt){
        for (int i = 0; i < size; i++){
            matrix[i] = malloc(sizeof(int));
            fscanf(input, "%d", (int*)matrix[i]);
        }
        m->matrix = matrix;
    } else if (flag == &TypeInfoDouble){
        for (int i = 0; i < size; i++){
            matrix[i] = malloc(sizeof(double));
            fscanf(input, "%lf", (double*)matrix[i]);
        }
        m->matrix = matrix;
    } else {
        for (int i = 0; i < size; i++){
            matrix[i] = malloc(sizeof(Complex));
            ((Complex*)matrix[i])->a = malloc(sizeof(int*));
            ((Complex*)matrix[i])->b = malloc(sizeof(int*));
            int tmpa, tmpb;
            fscanf(input, "%d;%d", &tmpa, &tmpb);
            *(int*)(((Complex*)matrix[i])->a) = tmpa;
            *(int*)(((Complex*)matrix[i])->b) = tmpb;
            if (complex_flag == 1){
                ((Complex*)matrix[i])->typeinfo = &ComplexTypeInfoDouble;
            } else {
                ((Complex*)matrix[i])->typeinfo = &ComplexTypeInfoInt;
            }
        }
        m->matrix = matrix;
    }
    fclose(input);
    return m;
}

///                МАТРИЧНЫЕ ФУНКЦИИ

int matrixCompare(Matrix* m1, Matrix* m2){
    if (m1->n != m2->n || m1->typeinfo != m2->typeinfo){
        global_error = "Can't compare matrix";
    } else {
        for (int i = 0; i < m1->n; i++){
            if ((m1->typeinfo->compare(m1->matrix[i], m2->matrix[i])) == 0){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

void matrixMultScalar(Matrix m, double number, Matrix rm){
    if (m.n != rm.n){
        global_error = "The wrong size of result";
        return;
    }
    for (int i = 0; i < m.n; i++){
        m.typeinfo->mult_scalar(m.matrix[i], &number, rm.matrix[i]);
    }
}

void matrixAdd(Matrix* m1, Matrix* m2, Matrix* rm){
    if (m1->n != m2->n){
        global_error = "Can't add the matrix";
        return;
    }
    if (m1->n != rm->n){
        global_error = "The wrong size of result";
        return;
    }
    if (m1->typeinfo != m2->typeinfo){
        global_error = "The type of matrix is wrong";
        return;
    }
    if (m1->typeinfo != rm->typeinfo){
        global_error = "The wrong type of result";
        return;
    }
    for (int i = 0; i < m1->n; i++){
        m1->typeinfo->add(m1->matrix[i], m2->matrix[i], rm->matrix[i]);
    }
}

void matrixSubtraction(Matrix* m1, Matrix* m2, Matrix* rm){
    if (m1->n != m2->n){
        global_error = "Can't subtract the matrix";
        return;
    }
    if (m1->n != rm->n){
        global_error = "The wrong size of result";
        return;
    }
    if (m1->typeinfo != m2->typeinfo){
        global_error = "The type of matrix is wrong";
        return;
    }
    if (m1->typeinfo != rm->typeinfo){
        global_error = "The wrong type of result";
        return;
    }
    for (int i = 0; i < m1->n; i++){
        m1->typeinfo->subtraction(m1->matrix[i], m2->matrix[i], rm->matrix[i]);
    }
}

void matrixMult(Matrix* m1, Matrix* m2, Matrix* rm){
    if (m1->n != m2->n){
        global_error = "Can't add the matrix";
        return;
    }
    if (m1->n != rm->n){
        global_error = "The wrong size of result";
        return;
    }
    if (m1->typeinfo != m2->typeinfo){
        global_error = "The type of matrix is wrong";
        return;
    }
    if (m1->typeinfo != rm->typeinfo){
        global_error = "The wrong type of result";
        return;
    }
    int n = sqrt(m1->n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // void* new_element = m1->typeinfo->create_zero;
            void* new_element = malloc(sizeof(int));
            *(int*)new_element = 0;
            for (int k = 0; k < n - 1; k++){
                //void* result = m1->typeinfo->create_zero;
                void* result = malloc(sizeof(int));
                *(int*)result = 0;
                m1->typeinfo->mult(m1->matrix[i * n + k], m2->matrix[k * n + j], result);
                rm->typeinfo->add(result, new_element, new_element);
            }
            // void* result = m1->typeinfo->create_zero;
            void* result = malloc(sizeof(int));
            *(int*)result = 0;
            m1->typeinfo->mult(m1->matrix[i * n + (n - 1)], m2->matrix[(n - 1) * n + j], result);
            rm->typeinfo->add(result, new_element, rm->matrix[i * n + j]);
        }
    }
}

void matrixTransposition(Matrix* m, Matrix* rm){
    if (m->n != rm->n){
        global_error = "The wrong size of result";
        return;
    }
    if (m->typeinfo != rm->typeinfo){
        global_error = "The wrong type of result";
        return;
    }
    int n = sqrt(m->n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (m->typeinfo == &TypeInfoInt){
                *(int*)rm->matrix[i * n + j] = *(int*)m->matrix[j * n + i];
            } else {
                *(double*)rm->matrix[i * n + j] = *(double*)m->matrix[j * n + i];
            }
        }
    }
}

void matrixLineCombination(Matrix* m, int* number, int* size, double* k, Matrix* rm){
    if (m->n != rm->n){
        global_error = "The wrong size of result";
        return;
    }
    if (sqrt(m->n) != *size){
        global_error = "The wrong size of combinations";
        return;
    }
    if (*number >= sqrt(m->n)){
        global_error = "Can't do the operation";
        return;
    }
    int n = sqrt(m->n);
    for (int j = 0; j < n; j++){
        double sum = 0.0;
        for (int i = 0; i < n; i++){
            void* result = malloc(sizeof(double));
            m->typeinfo->mult_scalar(m->matrix[i * n + j], &k[i], result);
            sum += *(double*)result;
            if (i != *number){
                *(double*)rm->matrix[i * n + j] = (double)*(int*)m->matrix[i * n + j];
            }
        }
        *(double*)rm->matrix[*number * n + j] = sum;
    }
}

///                МАТРИЧНЫЕ ФУНКЦИИ
///                LU-РАЗЛОЖЕНИЕ И РЕШЕНИЕ СИСТЕМ РАВЕНСТВ

void prepareLU(Matrix* m, Matrix* Lmatrix, Matrix* Umatrix){
    int size = sqrt(m->n);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i > j){
                *(double*)Umatrix->matrix[i * size + j] = 0.0;
            } else {
                *(double*)Umatrix->matrix[i * size + j] = *(double*)m->matrix[i * size + j];
            }
            if (i == j){
                *(double*)Lmatrix->matrix[i * size + j] = 1.0;
            } else {
                *(double*)Lmatrix->matrix[i * size + j] = 0.0;
            }
        }
    }
}

void matrixGetLU(Matrix* m, Matrix* Lmatrix, Matrix* Umatrix, Matrix* LUmatrix){
    prepareLU(m, Lmatrix, Umatrix);
    int size = sqrt(m->n);
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (i > j){ // L
                void* sum1 = m->typeinfo->create_zero();
                for (int k = 0; k < j; k++){
                    void* result = m->typeinfo->create_zero();
                    m->typeinfo->mult(Lmatrix->matrix[i * size + k], Umatrix->matrix[k * size + j], result);
                    m->typeinfo->add(sum1, result, sum1);
                }
                void* number = m->typeinfo->create_zero();
                m->typeinfo->subtraction(m->matrix[i * size + j], sum1, number);
                m->typeinfo->del(number, Umatrix->matrix[j * size + j], Lmatrix->matrix[i * size + j]);
            } else if (j >= i && i != 0){ // U
                void* sum2 = m->typeinfo->create_zero();
                for (int k = 0; k < i; k++){
                    void* result = m->typeinfo->create_zero();
                    m->typeinfo->mult(Lmatrix->matrix[i * size + k], Umatrix->matrix[k * size + j], result);
                    m->typeinfo->add(sum2, result, sum2);
                }
                void* number = m->typeinfo->create_zero();
                m->typeinfo->subtraction(m->matrix[i * size + j], sum2, number);
                Umatrix->matrix[i * size + j] = number;
            }
        }
    }
    matrixMult(Lmatrix, Umatrix, LUmatrix);
    int flag = 0;
    for (int i = 0; i < m->n; i++){
        if (*(double*)m->matrix[i] != *(double*)LUmatrix->matrix[i]){
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        global_error = "LU decomposition was calculated wrong";
    }
}

void getYmatrix(Matrix* Lmatrix, void* Bmatrix, void* Ymatrix){
    int size = sqrt(Lmatrix->n);
    for (int i = 0; i < size; i++){
        void* sum = Lmatrix->typeinfo->create_zero();
        for (int j = 0; j < i; j++){
            //void* result = Lmatrix->typeinfo->create_zero();
            *(double*)sum += ((double*)Ymatrix)[j] * *(double*)Lmatrix->matrix[i * size + j];
            //Lmatrix->typeinfo->mult(&Ymatrix[j], Lmatrix->matrix[i * size + j], result);
            //Lmatrix->typeinfo->add(sum, result, sum);
        }
        ((double*)Ymatrix)[i] = ((double*)Bmatrix)[i] - *(double*)sum;
        //Lmatrix->typeinfo->subtraction(&Bmatrix[i], sum, &Ymatrix[i]);
    }
}

void getXmatrix(Matrix* Umatrix, void* Ymatrix, void* Xmatrix){
    int size = sqrt(Umatrix->n);
    for (int i = size - 1; i > -1; i--){
        void* sum = Umatrix->typeinfo->create_zero();
        for (int j = i + 1; j < size; j++){
            //void* result = Umatrix->typeinfo->create_zero();
            //Umatrix->typeinfo->mult(&Xmatrix[j], Umatrix->matrix[i * size + j], result);
            *(double*)sum += ((double*)Xmatrix)[j] * *(double*)Umatrix->matrix[i * size + j];
            //Umatrix->typeinfo->add(sum, result, sum);
        }
        ((double*)Xmatrix)[i] = (((double*)Ymatrix)[i] - *(double*)sum) / *(double*)Umatrix->matrix[i * size + i];
        //void* number = Umatrix->typeinfo->create_zero();
        //Umatrix->typeinfo->subtraction(&Ymatrix[i], sum, number);
        //Umatrix->typeinfo->del(number, Umatrix->matrix[i * size + i], &Xmatrix[i]);
    }
}

void matrixSolution(Matrix* m, void* b, void* x, void* y){
    Matrix* Lmatrix = matrixCreate(m->n, &TypeInfoDouble);
    Matrix* Umatrix = matrixCreate(m->n, &TypeInfoDouble);
    Matrix* LUmatrix = matrixCreate(m->n, &TypeInfoDouble);
    
    matrixGetLU(m, Lmatrix, Umatrix, LUmatrix);
    getYmatrix(Lmatrix, b, y);
    getXmatrix(Umatrix, y, x);
    
    matrixFree(Lmatrix);
    matrixFree(Umatrix);
    matrixFree(LUmatrix);
}

void resPrint(int n, void* x, FILE* output){
    fprintf(output, "Solution:\n");
    for (int i = 0; i < sqrt(n); i++){
        fprintf(output, "X%d = %2.f\n", i, ((double*)x)[i]);
    }
}

///                LU-РАЗЛОЖЕНИЕ И РЕШЕНИЕ СИСТЕМ РАВЕНСТВ

void chooseOperation(int numberOperation){
    switch (numberOperation){
        case 1: { // MultScalar
            double number;
            printf("Scalar: ");
            scanf("%lf", &number);
            char input_file_name[256];
            printf("Input filename: ");
            scanf("%255s", input_file_name);
            FILE* f_input = fopen(input_file_name, "r");
            if (!f_input) {
                perror("Error with opening the file");
            }
            Matrix* m = matrixGetMatrix(f_input);
            fclose(f_input);
            
            Matrix* rm = malloc(sizeof(Matrix*));
            if (m->typeinfo == &TypeInfoInt || m->typeinfo == &TypeInfoDouble){
                rm = matrixCreate(m->n, &TypeInfoDouble);
            } else {
                rm = matrixCreate(m->n, &TypeInfoComplex);
            }
            
            matrixMultScalar(*m, number, *rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m);
            matrixFree(rm);
            break;
        }
        case 2: { // Add
            char input1_file_name[256];
            printf("Input filename for the first matrix: ");
            scanf("%255s", input1_file_name);
            FILE* f_input1 = fopen(input1_file_name, "r");
            if (!f_input1) {
                perror("Error with opening the file");
            }
            Matrix* m1 = matrixGetMatrix(f_input1);
            fclose(f_input1);
            
            char input2_file_name[256];
            printf("Input filename for the second matrix: ");
            scanf("%255s", input2_file_name);
            FILE* f_input2 = fopen(input2_file_name, "r");
            if (!f_input2) {
                perror("Error with opening the file");
            }
            Matrix* m2 = matrixGetMatrix(f_input2);
            fclose(f_input2);
            
            Matrix* rm = malloc(sizeof(Matrix*));
            rm = matrixCreate(m1->n, m1->typeinfo);
            
            matrixAdd(m1, m2, rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m1);
            matrixFree(m2);
            matrixFree(rm);
            break;
        }
        case 3: { // Substract
            char input1_file_name[256];
            printf("Input filename for the first matrix: ");
            scanf("%255s", input1_file_name);
            FILE* f_input1 = fopen(input1_file_name, "r");
            if (!f_input1) {
                perror("Error with opening the file");
            }
            Matrix* m1 = matrixGetMatrix(f_input1);
            fclose(f_input1);
            
            char input2_file_name[256];
            printf("Input filename for the second matrix: ");
            scanf("%255s", input2_file_name);
            FILE* f_input2 = fopen(input2_file_name, "r");
            if (!f_input2) {
                perror("Error with opening the file");
            }
            Matrix* m2 = matrixGetMatrix(f_input2);
            fclose(f_input2);
            
            Matrix* rm = malloc(sizeof(Matrix*));
            rm = matrixCreate(m1->n, m1->typeinfo);
            
            matrixSubtraction(m1, m2, rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m1);
            matrixFree(m2);
            matrixFree(rm);
            break;
        }
        case 4: { // Mult
            char input1_file_name[256];
            printf("Input filename for the first matrix: ");
            scanf("%255s", input1_file_name);
            FILE* f_input1 = fopen(input1_file_name, "r");
            if (!f_input1) {
                perror("Error with opening the file");
            }
            Matrix* m1 = matrixGetMatrix(f_input1);
            fclose(f_input1);
            
            char input2_file_name[256];
            printf("Input filename for the second matrix: ");
            scanf("%255s", input2_file_name);
            FILE* f_input2 = fopen(input2_file_name, "r");
            if (!f_input2) {
                perror("Error with opening the file");
            }
            Matrix* m2 = matrixGetMatrix(f_input2);
            fclose(f_input2);
            
            Matrix* rm = malloc(sizeof(Matrix*));
            rm = matrixCreate(m1->n, m1->typeinfo);
            
            matrixMult(m1, m2, rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m1);
            matrixFree(m2);
            matrixFree(rm);
            break;
        }
        case 5: { // Transpose
            char input_file_name[256];
            printf("Input filename: ");
            scanf("%255s", input_file_name);
            FILE* f_input = fopen(input_file_name, "r");
            if (!f_input) {
                perror("Error with opening the file");
            }
            Matrix* m = matrixGetMatrix(f_input);
            fclose(f_input);
            
            Matrix* rm = malloc(sizeof(Matrix*));
            rm = matrixCreate(m->n, m->typeinfo);
            
            matrixTransposition(m, rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m);
            matrixFree(rm);
            break;
        }
        case 6: { // Line combination
            int line_number;
            printf("Number of line: ");
            scanf("%d", &line_number);
            int n;
            printf("Size of k: ");
            scanf("%d", &n);
            printf("Matrix of k: ");
            double* k = malloc(n * sizeof(double));
            for (int i = 0; i < n; i++){
                scanf("%lf", &k[i]);
            }
            
            char input_file_name[256];
            printf("Input filename: ");
            scanf("%255s", input_file_name);
            FILE* f_input = fopen(input_file_name, "r");
            if (!f_input) {
                perror("Error with opening the file");
            }
            Matrix* m = matrixGetMatrix(f_input);
            fclose(f_input);
            
            Matrix* rm = malloc(sizeof(Matrix));
            if (m->typeinfo == &TypeInfoInt || m->typeinfo == &TypeInfoDouble){
                rm = matrixCreate(m->n, &TypeInfoDouble);
            } else {
                rm = matrixCreate(m->n, &TypeInfoComplex);
            }
            
            matrixLineCombination(m, &line_number, &n, k, rm);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            matrixPrint(rm, f_output);
            fclose(f_output);
            
            matrixFree(m);
            matrixFree(rm);
            break;
        }
        case 7: { // System of equations
            int size_b;
            printf("Size of matrix for results: ");
            scanf("%d", &size_b);
            printf("Matrix of result: ");
            void* b = malloc(size_b * sizeof(double));
            for (int i = 0; i < size_b; i++){
                scanf("%lf", &((double*)b)[i]);
            }
            void* x = malloc(size_b * sizeof(double));
            void* y = malloc(size_b * sizeof(double)); // вспомогательная матрица для расчета уравнения
            
            char input_file_name[256];
            printf("Input filename: ");
            scanf("%255s", input_file_name);
            FILE* f_input = fopen(input_file_name, "r");
            if (!f_input) {
                perror("Error with opening the file");
            }
            Matrix* m = matrixGetMatrix(f_input);
            fclose(f_input);
            
            matrixSolution(m, b, x, y);
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            resPrint(m->n, x, f_output);
            fclose(f_output);
            
            matrixFree(m);
            free(b);
            free(y);
            free(x);
            break;
        }
        case 8: { // Determinant
            char input_file_name[256];
            printf("Input filename: ");
            scanf("%255s", input_file_name);
            FILE* f_input = fopen(input_file_name, "r");
            if (!f_input) {
                perror("Error with opening the file");
            }
            Matrix* m = matrixGetMatrix(f_input);
            fclose(f_input);
            
            Matrix* Lmatrix = matrixCreate(m->n, &TypeInfoDouble);
            Matrix* Umatrix = matrixCreate(m->n, &TypeInfoDouble);
            Matrix* LUmatrix = matrixCreate(m->n, &TypeInfoDouble);
            
            matrixGetLU(m, Lmatrix, Umatrix, LUmatrix);
            double determinant = 1.0;
            int size = sqrt(m->n);
            for (int i = 0; i < size; i++){
                determinant = determinant * *(double*)Umatrix->matrix[i * size + i];
            }
            
            char output_file_name[256];
            printf("Output filename: ");
            scanf("%255s", output_file_name);
            FILE* f_output = fopen(output_file_name, "w");
            if (!f_output) {
                perror("Error with opening the file");
            }
            fprintf(f_output, "Determinant of matrix = %2.f", determinant);
            fclose(f_output);
            
            matrixFree(m);
            matrixFree(Lmatrix);
            matrixFree(Umatrix);
            matrixFree(LUmatrix);
            break;
        }
    }
}

int main(void) {
    printf("Choose the operation\n1. Mult on scalar\n2. Add matrix\n3. Subtract matrix\n4. Mult matrix\n5. Transpose matrix\n6. Line combination\n7. System of equations\n8. Determinant of matrix\n");
    int numberOperation;
    scanf("%d", &numberOperation);
    chooseOperation(numberOperation);
    return 0;
}
