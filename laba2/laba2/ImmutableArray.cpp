#include <iostream>
#include <tuple>
#include "ImmutableArray.h"

///           ФУНКЦИИ ДЛЯ IMMUTABLEARRAY

template <typename T>
ImmutableArray<T>* ImmutableArray<T>::Clone(){
    ImmutableArray<T>* clone = new ImmutableArray<T>(this->GetLength());
    for (int index = 0; index < this->GetLength(); index++){
        clone->Set(index, this->Get(index));
    }
    return clone;
}

template <typename T>
ImmutableArray<T>* ImmutableArray<T>::Instance(){
    return Clone();
}

template <typename T>
ImmutableArray<T>* ImmutableArray<T>::CreateNew(){
    ImmutableArray<T>* newArray = new ImmutableArray<T>();
    return newArray;
}

template <typename T>
bool ImmutableArray<T>::Compare(ImmutableArray<T>* as){
    return this->GetArray()->Compare(*as->GetArray());
}

template <typename T>
ImmutableArray<T>* ImmutableArray<T>::Concat(ImmutableArray<T>* list){
    ImmutableArray<T>* newArray = new ImmutableArray<T>(this->GetLength() + list->GetLength());
    for (int index = 0; index < (this->GetLength() + list->GetLength()); index++){
        if (index < this->GetLength()){
            newArray->Set(index, this->Get(index));
        } else {
            newArray->Set(index, list->Get(index - this->GetLength()));
        }
    }
    return newArray;
}

template <typename T>
ImmutableArray<ImmutableArray<T>>* ImmutableArray<T>::FlatMap(DynamicArray<T>* F(T)){
    ImmutableArray<ImmutableArray<T>>* newArray = new ImmutableArray<ImmutableArray<T>>;
    for (int i = 0; i < this->GetLength(); i++){
        DynamicArray<T>* results = F(this->Get(i));
        ImmutableArray<T> newres = ImmutableArray(*results);
        newArray->Append(newres);
    }
    return newArray;
}

template <typename T>
ImmutableArray<std::tuple<T, T>>* ImmutableArray<T>::Zip(ImmutableArray<T>* imma1){
    ImmutableArray<std::tuple<T, T>>* res = new ImmutableArray<std::tuple<T, T>>();
    for (int index = 0; index < std::min(this->GetLength(), imma1->GetLength()); index++){
        std::tuple<T, T> t(this->Get(index), imma1->Get(index));
        res->Append(t);
    }
    return res;
}

template <typename T>
ArraySequence<T>* ImmutableArray<T>::Slice(int index, int n, ImmutableArray<T>* as){
    if (index >= this->GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    if (index < 0){
        index = this->GetLength() + index + 1;
    }
    ArraySequence<T>* newArray = CreateNew();
    if (as->GetLength() == 0){
        newArray = this->GetSubsequence(index, index + n - 1);
    } else {
        for (int i = 0; i < this->GetLength(); i++){
            if (index <= i && i <= index + n - 1){
                newArray = newArray->Append(as->Get(i - index));
            } else {
                newArray = newArray->Append(this->Get(i));
            }
        }
    }
    return newArray;
}

template <typename T>
ImmutableArray<ImmutableArray<T>>* ImmutableArray<T>::Split(bool F(T)){
    ImmutableArray<ImmutableArray<T>>* newArray = new ImmutableArray<ImmutableArray<T>>;
    ImmutableArray<T>* node = new ImmutableArray<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index)) && node->GetLength() != 0){
            newArray->Append(*node);
            node = new ImmutableArray<T>();
        } else if (F(this->Get(index)) == 0){
            node->Append(this->Get(index));
        }
    }
    if (node->GetLength() != 0){
        newArray->Append(*node);
    }
    return newArray;
}
