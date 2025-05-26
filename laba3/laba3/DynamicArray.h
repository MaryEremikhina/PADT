#pragma once
#include <iostream>

template <typename T>
class DynamicArray {
public:
    DynamicArray();
    DynamicArray(T* items, int count);
    DynamicArray(int count);
    DynamicArray(DynamicArray<T>& dynamicArray);
    ~DynamicArray();
    
    T& Get(int index);
    T& operator[](int index);
    int GetSize();
    void Set(int index, T value);
    DynamicArray<T>* Resize(int newSize);
    DynamicArray<T>* DelStart();
    DynamicArray<T>* DelEnd();
    
    bool Compare(DynamicArray<T> dynamicArray);
private:
    T* data;
    int size;
};
