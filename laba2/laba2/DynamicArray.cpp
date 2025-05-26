#include <iostream>
#include "DynamicArray.h"

///                КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
DynamicArray<T>::DynamicArray(){
    data = NULL;
    size = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(T* items, int count){
    data = items;
    size = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(int count){
    data = new T[count];
    size = count;
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>& dynamicArray){
    data = new T[dynamicArray.GetSize()];
    size = dynamicArray.GetSize();
    for (int index = 0; index < dynamicArray.GetSize(); index++) {
            data[index] = *dynamicArray.Get(index);
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray(){}

///           ФУНКЦИИ ДЛЯ DYNAMICARRAY

template <typename T>
T* DynamicArray<T>::Get(int index){
    if (index >= size){
        throw std::out_of_range("IndexOutOfRange");
    }
    return &data[index];
}

template <typename T>
T DynamicArray<T>::operator[](int index){
    return *Get(index);
}

template <typename T>
int DynamicArray<T>::GetSize(){
    return size;
}

template <typename T>
void DynamicArray<T>::Set(int index, T value){
    if (index >= size){
        throw std::out_of_range("IndexOutOfRange");
    }
    data[index] = value;
}

template <typename T>
void DynamicArray<T>::Resize(int newSize){
    T* newData = new T[newSize];
    for (int index = 0; index < size; index++){
        if (index < newSize){
            newData[index] = data[index];
        }
    }
    data = newData;
    size = newSize;
}

template <typename T>
bool DynamicArray<T>::Compare(DynamicArray<T> dynamicArray){
    if (size != dynamicArray.GetSize()){
        return false;
    }
    int flag = 1;
    for (int index = 0; index < this->GetSize(); index++){
        if (*this->Get(index) != *dynamicArray.Get(index)){
            flag = 0;
            break;
        }
    }
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}
