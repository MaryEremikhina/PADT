#pragma once
#include <iostream>
#include <tuple>
#include "ListSequence.h"

template <typename T>
class ImmutableList : public ListSequence<T> {
public:
    ImmutableList(T* items, int count) : ListSequence<T>(items, count) {};
    ImmutableList() : ListSequence<T>() {};
    ImmutableList(const LinkedList<T>& linkedList) : ListSequence<T>(linkedList) {};
    
    bool Compare(ImmutableList<T>* as);
    
    ImmutableList<T>* Instance() override;
    ImmutableList<T>* CreateNew() override;
    
    ImmutableList<T>* Concat(ImmutableList<T>* list);
    ImmutableList<ImmutableList<T>>* FlatMap(LinkedList<T>* F(T));
    ImmutableList<std::tuple<T, T>>* Zip(ImmutableList<T>* imml1);
    ListSequence<T>* Slice(int index, int n, ImmutableList<T>* ma);
    ImmutableList<ImmutableList<T>>* Split(bool F(T));
private:
    ImmutableList<T>* Clone() override;
};

template <typename T>
std::tuple<ImmutableList<T>, ImmutableList<T>>* Unzip(ImmutableList<std::tuple<T, T>>* ma){
    ImmutableList<T>* ma1 = new ImmutableList<T>();
    ImmutableList<T>* ma2 = new ImmutableList<T>();
    for (int index = 0; index < ma->GetLength(); index++){
        std::tuple<T, T> tmp = ma->Get(index);
        ma1->Append(std::get<0>(tmp));
        ma2->Append(std::get<1>(tmp));
    }
    std::tuple<ImmutableList<T>, ImmutableList<T>>* t = new std::tuple<ImmutableList<T>, ImmutableList<T>>(*ma1, *ma2);
    return t;
}
