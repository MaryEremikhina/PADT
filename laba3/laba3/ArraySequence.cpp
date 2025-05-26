#include <iostream>
#include <tuple>

#include "ArraySequence.h"
#include "DynamicArray.cpp"

///                КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
ArraySequence<T>::ArraySequence(){
    dynamicArray = new DynamicArray<T>();
}

template <typename T>
ArraySequence<T>::ArraySequence(T* items, int count){
    dynamicArray = new DynamicArray<T>(items, count);
}

template <typename T>
ArraySequence<T>::ArraySequence(DynamicArray<T>& dynamicArray){
    this->dynamicArray = new DynamicArray<T>(dynamicArray);
}

template <typename T>
ArraySequence<T>::~ArraySequence(){
    delete dynamicArray;
}

///           ФУНКЦИИ ДЛЯ ARRAYSEQUENCE

template <typename T>
T& ArraySequence<T>::Get(int index){
    return dynamicArray->Get(index);
}

template <typename T>
T& ArraySequence<T>::operator[](int index){
    return Get(index);
}

template <typename T>
T& ArraySequence<T>::GetFirst(){
    return dynamicArray->Get(0);
}

template <typename T>
T& ArraySequence<T>::GetLast(){
    return dynamicArray->Get(GetLength() - 1);
}

template <typename T>
int ArraySequence<T>::GetLength(){
    return dynamicArray->GetSize();
}

template <typename T>
void ArraySequence<T>::Set(int index, T value){
    dynamicArray->Set(index, value);
}

template <typename T>
DynamicArray<T>* ArraySequence<T>::GetArray(){
    return dynamicArray;
}

template <typename T>
Sequence<T>* ArraySequence<T>::CreateNew(){
    Sequence<T>* newArray = new ArraySequence<T>();
    return newArray;
}

template <typename T>
Sequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex){
    Sequence<T>* newArray = new ArraySequence<T>();
    if (startIndex < 0 || startIndex >= GetLength() || endIndex < 0 || endIndex >= GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    for (int index = 0; index <= (endIndex - startIndex); index++){
        newArray->Append(Get(startIndex + index));
    }
    return newArray;
}

template <typename T>
Sequence<T>* ArraySequence<T>::Append(T item){
    dynamicArray->Resize(GetLength() + 1);
    Set(GetLength() - 1, item);
    return this;
}

template <typename T>
Sequence<T>* ArraySequence<T>::Prepend(T item){
    dynamicArray->Resize(GetLength() + 1);
    for (int index = GetLength() - 1; index > 0; index--){
        Set(index, Get(index - 1));
    }
    Set(0, item);
    return this;
}

template <typename T>
Sequence<T>* ArraySequence<T>::InsertAt(T item, int index){
    if (index >= GetLength() || index < 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    dynamicArray->Resize(GetLength() + 1);
    for (int i = GetLength() - 1; i > -1; i--){
        if (i < index){
            Set(i, Get(i));
        } else if (i == index){
            Set(index, item);
        } else {
            Set(i, Get(i - 1));
        }
    }
    return this;
}

template <typename T>
Sequence<T>* ArraySequence<T>::DelStart(){
    DynamicArray<T>* newDynamicArray = dynamicArray->DelStart();
    ArraySequence<T>* newArray = new ArraySequence<T>(*newDynamicArray);
    return newArray;
}

template <typename T>
Sequence<T>* ArraySequence<T>::DelEnd(){
    DynamicArray<T>* newDynamicArray = dynamicArray->DelEnd();
    ArraySequence<T>* newArray = new ArraySequence<T>(*newDynamicArray);
    return newArray;
}

template <typename T>
Sequence<std::tuple<T, T>>* ArraySequence<T>::Zip(Sequence<T>* list) {
    Sequence<std::tuple<T, T>>* newSeq = new ArraySequence<std::tuple<T, T>>();
    int minLength = std::min(GetLength(), list->GetLength());
    for (int i = 0; i < minLength; i++) {
        newSeq->Append(std::make_tuple(Get(i), list->Get(i)));
    }
    return newSeq;
}

template <typename T>
std::tuple<Sequence<T>*, Sequence<T>*>* ArraySequence<T>::UnZip(Sequence<std::tuple<T, T>>* list){
    Sequence<T>* seq1 = new ArraySequence<T>();
    Sequence<T>* seq2 = new ArraySequence<T>();
    for (int index = 0; index < list->GetLength(); index++){
        std::tuple<T, T> node = list->Get(index);
        seq1->Append(std::get<0>(node));
        seq2->Append(std::get<1>(node));
    }
    return new std::tuple<Sequence<T>*, Sequence<T>*>(seq1, seq2);
}
