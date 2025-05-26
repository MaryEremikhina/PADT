#pragma once
#include <iostream>
#include <tuple>
#include "ListSequence.h"

template <typename T>
class MutableList : public ListSequence<T> {
public:
    MutableList(T* items, int count) : ListSequence<T>(items, count) {};
    MutableList() : ListSequence<T>() {};
    MutableList(LinkedList<T>& linkedList) : ListSequence<T>(linkedList) {};
    
    MutableList<T>* Concat(MutableList<T>* list);
    MutableList<MutableList<T>>* FlatMap(LinkedList<T>* F(T));
    MutableList<std::tuple<T, T>>* Zip(MutableList<T>* ml1);
    ListSequence<T>* Slice(int index, int n, MutableList<T>* ma);
    MutableList<MutableList<T>>* Split(bool F(T));
    
    bool Compare(MutableList<T>* as);
    
    MutableList<T>* Instance() override;
    MutableList<T>* CreateNew() override;
private:
    MutableList<T>* Clone() override;
};

template <typename T>
std::tuple<MutableList<T>, MutableList<T>>* Unzip(MutableList<std::tuple<T, T>>* ma){
    MutableList<T>* ma1 = new MutableList<T>();
    MutableList<T>* ma2 = new MutableList<T>();
    for (int index = 0; index < ma->GetLength(); index++){
        std::tuple<T, T> tmp = ma->Get(index);
        ma1->Append(std::get<0>(tmp));
        ma2->Append(std::get<1>(tmp));
    }
    std::tuple<MutableList<T>, MutableList<T>>* t = new std::tuple<MutableList<T>, MutableList<T>>(*ma1, *ma2);
    return t;
}
