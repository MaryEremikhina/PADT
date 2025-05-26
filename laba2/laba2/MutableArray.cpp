#include <iostream>
#include <tuple>
#include "MutableArray.h"

///           ФУНКЦИИ ДЛЯ MUTABLEARRAY

template <typename T>
MutableArray<T>* MutableArray<T>::Instance(){
    return this;
}

template <typename T>
MutableArray<T>* MutableArray<T>::Clone(){
    return NULL;
}

template <typename T>
MutableArray<T>* MutableArray<T>::CreateNew(){
    MutableArray<T>* newArray = new MutableArray<T>();
    return newArray;
}

template <typename T>
bool MutableArray<T>::Compare(MutableArray<T>* as){
    return this->GetArray()->Compare(*as->GetArray());
}

template <typename T>
MutableArray<T>* MutableArray<T>::Concat(MutableArray<T>* list){
    MutableArray<T>* newArray = CreateNew();
    for (int index = 0; index < this->GetLength() + list->GetLength(); index++){
        if (index < this->GetLength()){
            newArray->Append(this->Get(index));
        } else {
            newArray->Append(list->Get(index - this->GetLength()));
        }
    }
    return newArray;
}

template <typename T>
MutableArray<MutableArray<T>>* MutableArray<T>::FlatMap(DynamicArray<T>* F(T)){
    MutableArray<MutableArray<T>>* newArray = new MutableArray<MutableArray<T>>;
    for (int i = 0; i < this->GetLength(); i++){
        DynamicArray<T>* results = F(this->Get(i));
        MutableArray<T> newres = MutableArray(*results);
        newArray->Append(newres);
    }
    return newArray;
}

template <typename T>
MutableArray<std::tuple<T, T>>* MutableArray<T>::Zip(MutableArray<T>* ma1){
    MutableArray<std::tuple<T, T>>* res = new MutableArray<std::tuple<T, T>>();
    for (int index = 0; index < std::min(this->GetLength(), ma1->GetLength()); index++){
        std::tuple<T, T> t(this->Get(index), ma1->Get(index));
        res->Append(t);
    }
    return res;
}

template <typename T>
ArraySequence<T>* MutableArray<T>::Slice(int index, int n, MutableArray<T>* as){
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
MutableArray<MutableArray<T>>* MutableArray<T>::Split(bool F(T)){
    MutableArray<MutableArray<T>>* newArray = new MutableArray<MutableArray<T>>;
    MutableArray<T>* node = new MutableArray<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index)) && node->GetLength() != 0){
            newArray->Append(*node);
            node = new MutableArray<T>();
        } else if (F(this->Get(index)) == 0){
            node->Append(this->Get(index));
        }
    }
    if (node->GetLength() != 0){
        newArray->Append(*node);
    }
    return newArray;
}
