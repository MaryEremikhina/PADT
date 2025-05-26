#pragma once
#include <iostream>
#include <tuple>
#include "ArraySequence.h"

template <typename T>
class MutableArray : public ArraySequence<T> {
public:
    MutableArray(T* items, int count) : ArraySequence<T>(items, count) {};
    MutableArray() : ArraySequence<T>() {};
    MutableArray(int count) : ArraySequence<T>(count) {};
    MutableArray(DynamicArray<T>& dynamicArray) : ArraySequence<T>(dynamicArray) {};
    
    MutableArray<T>* Instance() override;
    MutableArray<T>* CreateNew() override;
    
    bool Compare(MutableArray<T>* as);
    
    MutableArray<T>* Concat(MutableArray<T>* list);
    MutableArray<MutableArray<T>>* FlatMap(DynamicArray<T>* F(T));
    MutableArray<std::tuple<T, T>>* Zip(MutableArray<T>* ma1);
    ArraySequence<T>* Slice(int index, int n, MutableArray<T>* ma);
    MutableArray<MutableArray<T>>* Split(bool F(T));
private:
    MutableArray<T>* Clone() override;
};

template <typename T>
std::tuple<MutableArray<T>, MutableArray<T>>* Unzip(MutableArray<std::tuple<T, T>>* ma){
    MutableArray<T> ma1 = MutableArray<T>(ma->GetLength());
    MutableArray<T> ma2 = MutableArray<T>(ma->GetLength());
    for (int index = 0; index < ma->GetLength(); index++){
        std::tuple<T, T> tmp = ma->Get(index);
        ma1.Set(index, std::get<0>(tmp));
        ma2.Set(index, std::get<1>(tmp));
    }
    std::tuple<MutableArray<T>, MutableArray<T>>* t = new std::tuple<MutableArray<T>, MutableArray<T>>(ma1, ma2);
    return t;
}
