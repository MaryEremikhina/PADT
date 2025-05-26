#pragma once
#include <iostream>
#include "DynamicArray.cpp"
#include "Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(int count);
    ArraySequence(DynamicArray<T>& dynamicArray);
    ~ArraySequence();
    
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    void Set(int index, T value) override;
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    int GetLength() override;
    DynamicArray<T>* GetArray();
    ArraySequence<T>* Append(T item) override;
    ArraySequence<T>* Prepend(T item) override;
    ArraySequence<T>* InsertAt(T item, int index) override;
    
    ArraySequence<T>* Skip(int index) override;
    ArraySequence<T>* Map(T F(T)) override;
    T Reduce(T F(T, T), T neutral) override;
    ArraySequence<T>* Where(bool F(T)) override;
    
    virtual ArraySequence<T>* Instance() = 0;
    virtual ArraySequence<T>* Clone() = 0;
    virtual ArraySequence<T>* CreateNew() = 0;
private:
    DynamicArray<T>* dynamicArray;
};
