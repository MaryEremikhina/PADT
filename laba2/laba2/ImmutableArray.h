#pragma once
#include <iostream>
#include <tuple>
#include "ArraySequence.h"

template <typename T>
class ImmutableArray : public ArraySequence<T> {
public:
    ImmutableArray(T* items, int count) : ArraySequence<T>(items, count) {};
    ImmutableArray() : ArraySequence<T>() {};
    ImmutableArray(int count) : ArraySequence<T>(count) {};
    ImmutableArray(const DynamicArray<T>& dynamicArray) : ArraySequence<T>(dynamicArray) {};
    
    bool Compare(ImmutableArray<T>* as);
    
    ImmutableArray<T>* Concat(ImmutableArray<T>* list);
    ImmutableArray<ImmutableArray<T>>* FlatMap(DynamicArray<T>* F(T));
    ImmutableArray<std::tuple<T, T>>* Zip(ImmutableArray<T>* imma1);
    ArraySequence<T>* Slice(int index, int n, ImmutableArray<T>* ma);
    ImmutableArray<ImmutableArray<T>>* Split(bool F(T));
    
    ImmutableArray<T>* Instance() override;
    ImmutableArray<T>* Clone() override;
    ImmutableArray<T>* CreateNew() override;
private:
};

template <typename T>
std::tuple<ImmutableArray<T>, ImmutableArray<T>>* Unzip(ImmutableArray<std::tuple<T, T>>* ma){
    ImmutableArray<T> ma1 = ImmutableArray<T>(ma->GetLength());
    ImmutableArray<T> ma2 = ImmutableArray<T>(ma->GetLength());
    for (int index = 0; index < ma->GetLength(); index++){
        std::tuple<T, T> tmp = ma->Get(index);
        ma1.Set(index, std::get<0>(tmp));
        ma2.Set(index, std::get<1>(tmp));
    }
    std::tuple<ImmutableArray<T>, ImmutableArray<T>>* t = new std::tuple<ImmutableArray<T>, ImmutableArray<T>>(ma1, ma2);
    return t;
}
