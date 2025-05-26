#include <iostream>
#include <tuple>
#include "MutableList.h"

///           ФУНКЦИИ ДЛЯ MUTABLELIST

template <typename T>
MutableList<T>* MutableList<T>::Instance(){
    return this;
}

template <typename T>
MutableList<T>* MutableList<T>::Clone(){
    return NULL;
}

template <typename T>
MutableList<T>* MutableList<T>::CreateNew(){
    MutableList<T>* newArray = new MutableList<T>();
    return newArray;
}

template <typename T>
bool MutableList<T>::Compare(MutableList<T>* as){
    return this->GetList()->Compare(*as->GetList());
}

template <typename T>
MutableList<T>* MutableList<T>::Concat(MutableList<T>* list){
    MutableList<T>* newArray = CreateNew();
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
MutableList<MutableList<T>>* MutableList<T>::FlatMap(LinkedList<T>* F(T)){
    MutableList<MutableList<T>>* newList = new MutableList<MutableList<T>>;
    for (int i = 0; i < this->GetLength(); i++){
        LinkedList<T>* results = F(this->Get(i));
        MutableList<T> newres(*results);
        newList->Append(newres);
    }
    return newList;
}

template <typename T>
MutableList<std::tuple<T, T>>* MutableList<T>::Zip(MutableList<T>* ml1){
    MutableList<std::tuple<T, T>>* res = new MutableList<std::tuple<T, T>>;
    for (int index = 0; index < std::min(this->GetLength(), ml1->GetLength()); index++){
        std::tuple<T, T> t(this->Get(index), ml1->Get(index));
        res->Append(t);
    }
    return res;
}

template <typename T>
ListSequence<T>* MutableList<T>::Slice(int index, int n, MutableList<T>* as){
    if (index >= this->GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    if (index < 0){
        index = this->GetLength() + index + 1;
    }
    ListSequence<T>* newArray = CreateNew();
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
MutableList<MutableList<T>>* MutableList<T>::Split(bool F(T)){
    MutableList<MutableList<T>>* newArray = new MutableList<MutableList<T>>;
    MutableList<T>* node = new MutableList<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index)) && node->GetLength() != 0){
            newArray->Append(*node);
            node = new MutableList<T>();
        } else if (F(this->Get(index)) == 0){
            node->Append(this->Get(index));
        }
    }
    if (node->GetLength() != 0){
        newArray->Append(*node);
    }
    return newArray;
}
