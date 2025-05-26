#pragma once
#include <iostream>
#include <tuple>

#include "DynamicArray.h"
#include "Sequence.h"

template <typename T>
class ArraySequence : public Sequence<T> {
public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(DynamicArray<T>& dynamicArray);
    ~ArraySequence();
    
    DynamicArray<T>* GetArray();
    
    T& GetFirst() override;
    T& GetLast() override;
    T& Get(int index) override;
    T& operator[](int index) override;
    void Set(int index, T value) override;
    int GetLength() override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    
    Sequence<T>* Append(T item) override;
    Sequence<T>* Prepend(T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    Sequence<T>* DelStart() override;
    Sequence<T>* DelEnd() override;
    
    template <typename D>
    Sequence<Sequence<D>*>* FlatMap(Sequence<D>* (*F)(T)){
        Sequence<Sequence<D>*>* newSeq = new ArraySequence<Sequence<D>*>();
        for (int index = 0; index < GetLength(); index++){
            Sequence<D>* node = F(Get(index));
            newSeq->Append(node);
        }
        return newSeq;
    }
    Sequence<std::tuple<T, T>>* Zip(Sequence<T>* list);
    std::tuple<Sequence<T>*, Sequence<T>*>* UnZip(Sequence<std::tuple<T, T>>* list) override;
    
    Sequence<T>* CreateNew() override;
private:
    DynamicArray<T>* dynamicArray;
};
