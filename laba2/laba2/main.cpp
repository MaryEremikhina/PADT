//
//  main.cpp
//  laba2
//
//  Created by Maria Eremikhina on 20.03.2025.
//

#include <iostream>
#include <algorithm>
#include <tuple>
#include <fstream>
#include <cassert>

#include "Sequence.h"
#include "ArraySequence.cpp"
#include "ListSequence.cpp"

#include "MutableList.cpp"
#include "MutableArray.cpp"
#include "ImmutableList.cpp"
#include "ImmutableArray.cpp"

#define INPUT_MA "/Users/meremikhina/Desktop/laba2/laba2/TestingMutableArray.txt"
#define INPUT_ML "/Users/meremikhina/Desktop/laba2/laba2/TestingMutableList.txt"
#define INPUT_IMMA "/Users/meremikhina/Desktop/laba2/laba2/TestingImmutableArray.txt"
#define INPUT_IMML "/Users/meremikhina/Desktop/laba2/laba2/TestingImmutableList.txt"

template <typename T>
T MapF(T x){
    return x + 2;
}

template <typename T>
T ReduceF(T a, T b){
    return a + b;
}

template <typename T>
bool WhereF(T x){
    if (x % 2 == 0){
        return true;
    }
    return false;
}

template <typename T>
void TestingMutableArray(std::ifstream& f, MutableArray<T> ma){
    int indexInsertAt, startIndex, endIndex, size;
    T valueAppend, valuePrepend, valueInsertAt;
    std::cout << "Value to Append: ";
    std::cin >> valueAppend;
    std::cout << "Value to Prepend: ";
    std::cin >> valuePrepend;
    std::cout << "Item and index to InsertAt: ";
    std::cin >> valueInsertAt >> indexInsertAt;
    
    std::cout << "StartIndex and endIndex to GetSubSequence: ";
    std::cin >> startIndex >> endIndex;
    
    std::cout << "Size of other sequence: ";
    std::cin >> size;
    int array[size];
    std::cout << "Values of other MutableArray: ";
    for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
    }
    int* ptr = array;
    MutableArray<int>* ma_other = new MutableArray<int>(ptr, size);
    ma.Append(valueAppend);
    MutableArray<int>* testma1 = new MutableArray<int>();
    for (int index = 0; index < ma.GetLength(); index++){
        int number;
        f >> number;
        testma1->Append(number);
    }
    if (ma.Compare(testma1)){
        std::cout << "Appending: OK\n";
    } else {
        assert(0);
    }
    
    ma.Prepend(valuePrepend);
    MutableArray<int>* testma2 = new MutableArray<int>();
    for (int index = 0; index < ma.GetLength(); index++){
        int number;
        f >> number;
        testma2->Append(number);
    }
    if (ma.Compare(testma2)){
        std::cout << "Prepending: OK\n";
    } else {
        assert(0);
    }
    
    ma.InsertAt(valueInsertAt, indexInsertAt);
    MutableArray<int>* testma3 = new MutableArray<int>();
    for (int index = 0; index < ma.GetLength(); index++){
        int number;
        f >> number;
        testma3->Append(number);
    }
    if (ma.Compare(testma3)){
        std::cout << "InsertingAt: OK\n";
    } else {
        assert(0);
    }
    
    ma.GetSubsequence(startIndex, endIndex);
    MutableArray<int>* testma4 = new MutableArray<int>();
    for (int index = 0; index < ma.GetLength(); index++){
        int number;
        f >> number;
        testma4->Append(number);
    }
    if (ma.Compare(testma4)){
        std::cout << "GetingSubsequence: OK\n";
    } else {
        assert(0);
    }
    
    MutableArray<int>* ConcatSequence = ma.Concat(ma_other);
    MutableArray<int>* testma5 = new MutableArray<int>();
    for (int index = 0; index < (ma.GetLength() + ma_other->GetLength()); index++){
        int number;
        f >> number;
        testma5->Append(number);
    }
    if (ConcatSequence->Compare(testma5)){
        std::cout << "Concating: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* MapSequence = ma.Map(MapF);
    MutableArray<int>* testma6 = new MutableArray<int>();
    for (int index = 0; index < ma.GetLength(); index++){
        int number;
        f >> number;
        testma6->Append(number);
    }
    if (MapSequence->GetArray()->Compare(*testma6->GetArray())){
        std::cout << "Maping: OK\n";
    } else {
        assert(0);
    }
    
    int result = ma.Reduce(ReduceF, 0);
    int number;
    f >> number;
    if (result == number){
        std::cout << "Reducing: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* WhereSequence = ma.Where(WhereF);
    MutableArray<int>* testma7 = new MutableArray<int>();
    for (int index = 0; index < WhereSequence->GetLength(); index++){
        int number;
        f >> number;
        testma7->Append(number);
    }
    if (WhereSequence->GetArray()->Compare(*testma7->GetArray())){
        std::cout << "Where: OK\n";
    } else {
        assert(0);
    }
}

template <typename T>
void TestingMutableList(std::ifstream& f, MutableList<T> ml){
    int indexInsertAt, startIndex, endIndex, size;
    T valueAppend, valuePrepend, valueInsertAt;
    std::cout << "Value to Append: ";
    std::cin >> valueAppend;
    std::cout << "Value to Prepend: ";
    std::cin >> valuePrepend;
    std::cout << "Item and index to InsertAt: ";
    std::cin >> valueInsertAt >> indexInsertAt;
    
    std::cout << "StartIndex and endIndex to GetSubSequence: ";
    std::cin >> startIndex >> endIndex;
    
    std::cout << "Size of other sequence: ";
    std::cin >> size;
    int array[size];
    std::cout << "Values of other MutableList: ";
    for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
    }
    int* ptr = array;
    MutableList<int>* ml_other = new MutableList<int>(ptr, size);
    ml.Append(valueAppend);
    MutableList<int>* testml1 = new MutableList<int>();
    for (int index = 0; index < ml.GetLength(); index++){
        int number;
        f >> number;
        testml1->Append(number);
    }
    if (ml.Compare(testml1)){
        std::cout << "Appending: OK\n";
    } else {
        assert(0);
    }
    
    ml.Prepend(valuePrepend);
    MutableList<int>* testml2 = new MutableList<int>();
    for (int index = 0; index < ml.GetLength(); index++){
        int number;
        f >> number;
        testml2->Append(number);
    }
    if (ml.Compare(testml2)){
        std::cout << "Prepending: OK\n";
    } else {
        assert(0);
    }
    
    ml.InsertAt(valueInsertAt, indexInsertAt);
    MutableList<int>* testml3 = new MutableList<int>();
    for (int index = 0; index < ml.GetLength(); index++){
        int number;
        f >> number;
        testml3->Append(number);
    }
    if (ml.Compare(testml3)){
        std::cout << "InsertingAt: OK\n";
    } else {
        assert(0);
    }
    
    ml.GetSubsequence(startIndex, endIndex);
    MutableList<int>* testml4 = new MutableList<int>();
    for (int index = 0; index < ml.GetLength(); index++){
        int number;
        f >> number;
        testml4->Append(number);
    }
    if (ml.Compare(testml4)){
        std::cout << "GetingSubsequence: OK\n";
    } else {
        assert(0);
    }
    
    MutableList<int>* ConcatSequence = ml.Concat(ml_other);
    MutableList<int>* testml5 = new MutableList<int>();
    for (int index = 0; index < (ml.GetLength() + ml_other->GetLength()); index++){
        int number;
        f >> number;
        testml5->Append(number);
    }
    if (ConcatSequence->Compare(testml5)){
        std::cout << "Concating: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* MapSequence = ml.Map(MapF);
    MutableList<int>* testml6 = new MutableList<int>();
    for (int index = 0; index < ml.GetLength(); index++){
        int number;
        f >> number;
        testml6->Append(number);
    }
    if (MapSequence->GetList()->Compare(*testml6->GetList())){
        std::cout << "Maping: OK\n";
    } else {
        assert(0);
    }
    
    int result = ml.Reduce(ReduceF, 0);
    int number;
    f >> number;
    if (result == number){
        std::cout << "Reducing: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* WhereSequence = ml.Where(WhereF);
    MutableList<int>* testml7 = new MutableList<int>();
    for (int index = 0; index < WhereSequence->GetLength(); index++){
        int number;
        f >> number;
        testml7->Append(number);
    }
    if (WhereSequence->GetList()->Compare(*testml7->GetList())){
        std::cout << "Where: OK\n";
    } else {
        assert(0);
    }
}

template <typename T>
void TestingImmutableArray(std::ifstream& f, ImmutableArray<T> imma){
    int indexInsertAt, startIndex, endIndex, size;
    T valueAppend, valuePrepend, valueInsertAt;
    std::cout << "Value to Append: ";
    std::cin >> valueAppend;
    std::cout << "Value to Prepend: ";
    std::cin >> valuePrepend;
    std::cout << "Item and index to InsertAt: ";
    std::cin >> valueInsertAt >> indexInsertAt;
    
    std::cout << "StartIndex and endIndex to GetSubSequence: ";
    std::cin >> startIndex >> endIndex;
    
    std::cout << "Size of other sequence: ";
    std::cin >> size;
    int array[size];
    std::cout << "Values of other ImmutableArray: ";
    for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
    }
    int* ptr = array;
    ImmutableArray<int>* imma_other = new ImmutableArray<int>(ptr, size);
    
    ArraySequence<int>* immaNew1 = imma.Append(valueAppend);
    int array1[immaNew1->GetLength()];
    for (int index = 0; index < immaNew1->GetLength(); index++){
        int number;
        f >> number;
        array1[index] = number;
    }
    int* ptr1 = array1;
    ImmutableArray<int>* testimma1 = new ImmutableArray<int>(ptr1, immaNew1->GetLength());
    if (immaNew1->GetArray()->Compare(*testimma1->GetArray())){
        std::cout << "Appending: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* immaNew2 = imma.Prepend(valuePrepend);
    int array2[immaNew2->GetLength()];
    for (int index = 0; index < immaNew2->GetLength(); index++){
        int number;
        f >> number;
        array2[index] = number;
    }
    int* ptr2 = array2;
    ImmutableArray<int>* testimma2 = new ImmutableArray<int>(ptr2, immaNew2->GetLength());
    if (immaNew2->GetArray()->Compare(*testimma2->GetArray())){
        std::cout << "Prepending: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* immaNew3 = imma.InsertAt(valueInsertAt, indexInsertAt);
    int array3[immaNew3->GetLength()];
    for (int index = 0; index < immaNew3->GetLength(); index++){
        int number;
        f >> number;
        array3[index] = number;
    }
    int* ptr3 = array3;
    ImmutableArray<int>* testimma3 = new ImmutableArray<int>(ptr3, immaNew3->GetLength());
    if (immaNew3->GetArray()->Compare(*testimma3->GetArray())){
        std::cout << "InsertingAt: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* immaNew4 = imma.GetSubsequence(startIndex, endIndex);
    int array4[immaNew4->GetLength()];
    for (int index = 0; index < immaNew4->GetLength(); index++){
        int number;
        f >> number;
        array4[index] = number;
    }
    int* ptr4 = array4;
    ImmutableArray<int>* testimma4 = new ImmutableArray<int>(ptr4, immaNew4->GetLength());
    if (immaNew4->GetArray()->Compare(*testimma4->GetArray())){
        std::cout << "GettingSubSequence: OK\n";
    } else {
        assert(0);
    }
    
    ImmutableArray<int>* ConcatSequence = imma.Concat(imma_other);
    int array5[ConcatSequence->GetLength()];
    for (int index = 0; index < ConcatSequence->GetLength(); index++){
        int number;
        f >> number;
        array5[index] = number;
    }
    int* ptr5 = array5;
    ImmutableArray<int>* testimma5 = new ImmutableArray<int>(ptr5, ConcatSequence->GetLength());
    if (ConcatSequence->Compare(testimma5)){
        std::cout << "Concating: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* MapSequence = imma.Map(MapF);
    int array6[imma.GetLength()];
    for (int index = 0; index < imma.GetLength(); index++){
        int number;
        f >> number;
        array6[index] = number;
    }
    int* ptr6 = array6;
    ImmutableArray<int>* testimma6 = new ImmutableArray<int>(ptr6, imma.GetLength());
    if (MapSequence->GetArray()->Compare(*testimma6->GetArray())){
        std::cout << "Maping: OK\n";
    } else {
        assert(0);
    }
    
    int result = imma.Reduce(ReduceF, 0);
    int number;
    f >> number;
    if (result == number){
        std::cout << "Reducing: OK\n";
    } else {
        assert(0);
    }
    
    ArraySequence<int>* WhereSequence = imma.Where(WhereF);
    int array7[WhereSequence->GetLength()];
    for (int index = 0; index < WhereSequence->GetLength(); index++){
        int number;
        f >> number;
        array7[index] = number;
    }
    int* ptr7 = array7;
    ImmutableArray<int>* testimma7 = new ImmutableArray<int>(ptr7, WhereSequence->GetLength());
    if (WhereSequence->GetArray()->Compare(*testimma7->GetArray())){
        std::cout << "Where: OK\n";
    } else {
        assert(0);
    }
}

template <typename T>
void TestingImmutableList(std::ifstream& f, ImmutableList<T> imml){
    int indexInsertAt, startIndex, endIndex, size;
    T valueAppend, valuePrepend, valueInsertAt;
    std::cout << "Value to Append: ";
    std::cin >> valueAppend;
    std::cout << "Value to Prepend: ";
    std::cin >> valuePrepend;
    std::cout << "Item and index to InsertAt: ";
    std::cin >> valueInsertAt >> indexInsertAt;
    
    std::cout << "StartIndex and endIndex to GetSubSequence: ";
    std::cin >> startIndex >> endIndex;
    
    std::cout << "Size of other sequence: ";
    std::cin >> size;
    int array[size];
    std::cout << "Values of other ImmutableList: ";
    for (int i = 0; i < size; ++i) {
            std::cin >> array[i];
    }
    int* ptr = array;
    ImmutableList<int>* imml_other = new ImmutableList<int>(ptr, size);
    
    ListSequence<int>* immlNew1 = imml.Append(valueAppend);
    int array1[immlNew1->GetLength()];
    for (int index = 0; index < immlNew1->GetLength(); index++){
        int number;
        f >> number;
        array1[index] = number;
    }
    int* ptr1 = array1;
    ImmutableList<int>* testimml1 = new ImmutableList<int>(ptr1, immlNew1->GetLength());
    if (immlNew1->GetList()->Compare(*testimml1->GetList())){
        std::cout << "Appending: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* immlNew2 = imml.Prepend(valuePrepend);
    int array2[immlNew2->GetLength()];
    for (int index = 0; index < immlNew2->GetLength(); index++){
        int number;
        f >> number;
        array2[index] = number;
    }
    int* ptr2 = array2;
    ImmutableList<int>* testimml2 = new ImmutableList<int>(ptr2, immlNew2->GetLength());
    if (immlNew2->GetList()->Compare(*testimml2->GetList())){
        std::cout << "Prepending: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* immlNew3 = imml.InsertAt(valueInsertAt, indexInsertAt);
    int array3[immlNew3->GetLength()];
    for (int index = 0; index < immlNew3->GetLength(); index++){
        int number;
        f >> number;
        array3[index] = number;
    }
    int* ptr3 = array3;
    ImmutableList<int>* testimml3 = new ImmutableList<int>(ptr3, immlNew3->GetLength());
    if (immlNew3->GetList()->Compare(*testimml3->GetList())){
        std::cout << "InsertingAt: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* immlNew4 = imml.GetSubsequence(startIndex, endIndex);
    int array4[immlNew4->GetLength()];
    for (int index = 0; index < immlNew4->GetLength(); index++){
        int number;
        f >> number;
        array4[index] = number;
    }
    int* ptr4 = array4;
    ImmutableList<int>* testimml4 = new ImmutableList<int>(ptr4, immlNew4->GetLength());
    if (immlNew4->GetList()->Compare(*testimml4->GetList())){
        std::cout << "GettingSubSequence: OK\n";
    } else {
        assert(0);
    }
    
    ImmutableList<int>* ConcatSequence = imml.Concat(imml_other);
    int array5[ConcatSequence->GetLength()];
    for (int index = 0; index < ConcatSequence->GetLength(); index++){
        int number;
        f >> number;
        array5[index] = number;
    }
    int* ptr5 = array5;
    ImmutableList<int>* testimml5 = new ImmutableList<int>(ptr5, ConcatSequence->GetLength());
    if (ConcatSequence->Compare(testimml5)){
        std::cout << "Concating: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* MapSequence = imml.Map(MapF);
    int array6[imml.GetLength()];
    for (int index = 0; index < imml.GetLength(); index++){
        int number;
        f >> number;
        array6[index] = number;
    }
    int* ptr6 = array6;
    ImmutableList<int>* testimml6 = new ImmutableList<int>(ptr6, imml.GetLength());
    if (MapSequence->GetList()->Compare(*testimml6->GetList())){
        std::cout << "Maping: OK\n";
    } else {
        assert(0);
    }
    
    int result = imml.Reduce(ReduceF, 0);
    int number;
    f >> number;
    if (result == number){
        std::cout << "Reducing: OK\n";
    } else {
        assert(0);
    }
    
    ListSequence<int>* WhereSequence = imml.Where(WhereF);
    int array7[WhereSequence->GetLength()];
    for (int index = 0; index < WhereSequence->GetLength(); index++){
        int number;
        f >> number;
        array7[index] = number;
    }
    int* ptr7 = array7;
    ImmutableList<int>* testimml7 = new ImmutableList<int>(ptr7, WhereSequence->GetLength());
    if (WhereSequence->GetList()->Compare(*testimml7->GetList())){
        std::cout << "Where: OK\n";
    } else {
        assert(0);
    }
}

int main() {
    std::cout << "Let's make a Sequence. Choose type of Sequence:\n1. ArraySequence\n2. ListSequence\n";
    int type1;
    std::cin >> type1;
    if (type1 == 1){
        std::cout << "Choose type of ArraySequence:\n1. MutableArray\n2. ImmutableArray\n";
        int type2;
        std::cin >> type2;
        if (type2 == 1){
            std::cout << "Size of MutableArray: ";
            int size;
            std::cin >> size;
            std::cout << "Values of MutableArray: ";
            int array[size];
            for (int i = 0; i < size; ++i) {
                    std::cin >> array[i];
            }
            int* ptr = array;
            MutableArray<int> ma = MutableArray<int>(ptr, size);
            char input_file_name[256];
            std::cout << "Input filename for answers: ";
            std::cin >> input_file_name;
            std::ifstream file(input_file_name);
            if (!file) {
                std::cerr << "Error with opening file\n";
                return 1;
            }
            TestingMutableArray(file, ma);
        } else {
            std::cout << "Size of ImmutableArray: ";
            int size;
            std::cin >> size;
            std::cout << "Values of ImmutableArray: ";
            int array[size];
            for (int i = 0; i < size; ++i) {
                    std::cin >> array[i];
            }
            int* ptr = array;
            ImmutableArray<int> ma = ImmutableArray<int>(ptr, size);
            char input_file_name[256];
            std::cout << "Input filename for answers: ";
            std::cin >> input_file_name;
            std::ifstream file(input_file_name);
            if (!file) {
                std::cerr << "Error with opening file\n";
                return 1;
            }
            TestingImmutableArray(file, ma);
        }
    } else {
        std::cout << "Choose type of ListSequence:\n1. MutableList\n2. ImmutableList\n";
        int type2;
        std::cin >> type2;
        if (type2 == 1){
            std::cout << "Size of MutableList: ";
            int size;
            std::cin >> size;
            std::cout << "Values of MutableList: ";
            int array[size];
            for (int i = 0; i < size; ++i) {
                    std::cin >> array[i];
            }
            int* ptr = array;
            MutableList<int> ma = MutableList<int>(ptr, size);
            char input_file_name[256];
            std::cout << "Input filename for answers: ";
            std::cin >> input_file_name;
            std::ifstream file(input_file_name);
            if (!file) {
                std::cerr << "Error with opening file\n";
                return 1;
            }
            TestingMutableList(file, ma);
        } else {
            std::cout << "Size of ImmutableList: ";
            int size;
            std::cin >> size;
            std::cout << "Values of ImmutableList: ";
            int array[size];
            for (int i = 0; i < size; ++i) {
                    std::cin >> array[i];
            }
            int* ptr = array;
            ImmutableList<int> ma = ImmutableList<int>(ptr, size);
            char input_file_name[256];
            std::cout << "Input filename for answers: ";
            std::cin >> input_file_name;
            std::ifstream file(input_file_name);
            if (!file) {
                std::cerr << "Error with opening file\n";
                return 1;
            }
            TestingImmutableList(file, ma);
        }
    }
}
