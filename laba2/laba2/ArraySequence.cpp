#include <iostream>
#include "ArraySequence.h"
#include "DynamicArray.h"

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
ArraySequence<T>::ArraySequence(int count){
    dynamicArray = new DynamicArray<T>(count);
}

template <typename T>
ArraySequence<T>::ArraySequence(DynamicArray<T>& dynamicArray){
    this->dynamicArray = new DynamicArray<T>(dynamicArray);
}

template <typename T>
ArraySequence<T>::~ArraySequence(){
    dynamicArray->~DynamicArray();
}

///           ФУНКЦИИ ДЛЯ ARRAYSEQUENCE

template <typename T>
T ArraySequence<T>::Get(int index){
    return *dynamicArray->Get(index);
}

template <typename T>
T ArraySequence<T>::GetFirst(){
    return *dynamicArray->Get(0);
}

template <typename T>
T ArraySequence<T>::GetLast(){
    return *dynamicArray->Get(dynamicArray->GetSize() - 1);
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
ArraySequence<T>* ArraySequence<T>::GetSubsequence(int startIndex, int endIndex){
    ArraySequence<T>* newArray = Instance();
    if (startIndex < 0 || startIndex >= this->GetLength() || endIndex < 0 || endIndex >= this->GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    for (int index = 0; index <= (endIndex - startIndex); index++){
        newArray->GetArray()->Set(index, *dynamicArray->Get(startIndex + index));
    }
    newArray->GetArray()->Resize(endIndex - startIndex + 1);
    return newArray;
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Append(T item){
    ArraySequence<T>* newArray = Instance();
    newArray->GetArray()->Resize(newArray->GetArray()->GetSize() + 1);
    newArray->GetArray()->Set(newArray->GetArray()->GetSize() - 1, item);
    return newArray;
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Prepend(T item){
    ArraySequence<T>* newArray = Instance();
    newArray->GetArray()->Resize(newArray->GetArray()->GetSize() + 1);
    for (int index = newArray->GetArray()->GetSize() - 1; index > 0; index--){
        newArray->Set(index, *newArray->GetArray()->Get(index - 1));
    }
    newArray->Set(0, item);
    return newArray;
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::InsertAt(T item, int index){
    if (index >= GetArray()->GetSize() || index < 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    ArraySequence<T>* newArray = Instance();
    newArray->GetArray()->Resize(newArray->GetArray()->GetSize() + 1);
    for (int i = newArray->GetArray()->GetSize() - 1; i > -1; i--){
        if (i < index){
            newArray->Set(i, *newArray->GetArray()->Get(i));
        } else if (i == index){
            newArray->Set(index, item);
        } else {
            newArray->Set(i, *newArray->GetArray()->Get(i - 1));
        }
    }
    return newArray;
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Skip(int index){
    if (index >= GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    return GetSubsequence(index, GetLength() - 1);
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Map(T F(T)){
    ArraySequence<T>* newArray = Instance();
    for (int index = 0; index < GetLength(); index++){
        newArray->Set(index, F(Get(index)));
    }
    return newArray;
}

template <typename T>
T ArraySequence<T>::Reduce(T F(T, T), T neutral){
    for (int index = 0; index < GetLength(); index++){
        neutral = F(neutral, Get(index));
    }
    return neutral;
}

template <typename T>
ArraySequence<T>* ArraySequence<T>::Where(bool F(T)){
    ArraySequence<T>* newArray = CreateNew();
    for (int index = 0; index < GetLength(); index++){
        if (F(Get(index))){
            newArray = newArray->Append(Get(index));
        }
    }
    return newArray;
}
