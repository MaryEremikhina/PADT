#include <iostream>
#include <tuple>
#include "ImmutableList.h"

///           ФУНКЦИИ ДЛЯ IMMUTABLELIST

template <typename T>
ImmutableList<T>* ImmutableList<T>::Clone(){
    T array[this->GetLength()];
    for (int index = 0; index < this->GetLength(); index++){
        array[index] = this->Get(index);
    }
    int* ptr = array;
    ImmutableList<T>* clone = new ImmutableList<T>(ptr, this->GetLength());
    return clone;
}

template <typename T>
ImmutableList<T>* ImmutableList<T>::Instance(){
    return Clone();
}

template <typename T>
ImmutableList<T>* ImmutableList<T>::CreateNew(){
    ImmutableList<T>* newArray = new ImmutableList<T>();
    return newArray;
}

template <typename T>
bool ImmutableList<T>::Compare(ImmutableList<T>* as){
    return this->GetList()->Compare(*as->GetList());
}

template <typename T>
ImmutableList<T>* ImmutableList<T>::Concat(ImmutableList<T>* list){
    T array[this->GetLength() + list->GetLength()];
    for (int index = 0; index < this->GetLength() + list->GetLength(); index++){
        if (index < this->GetLength()){
            array[index] = this->Get(index);
        } else {
            array[index] = list->Get(index - this->GetLength());
        }
    }
    T* ptr = array;
    ImmutableList<T>* newArray = new ImmutableList<T>(ptr, this->GetLength() + list->GetLength());
    return newArray;
}

template <typename T>
ImmutableList<ImmutableList<T>>* ImmutableList<T>::FlatMap(LinkedList<T>* F(T)){
    ImmutableList<ImmutableList<T>>* newList = new ImmutableList<ImmutableList<T>>;
    for (int i = 0; i < this->GetLength(); i++){
        LinkedList<T>* results = F(this->Get(i));
        ImmutableList<T> newres(*results);
        newList->Append(newres);
    }
    return newList;
}

template <typename T>
ImmutableList<std::tuple<T, T>>* ImmutableList<T>::Zip(ImmutableList<T>* imml1){
    ImmutableList<std::tuple<T, T>>* res = new ImmutableList<std::tuple<T, T>>;
    for (int index = 0; index < std::min(this->GetLength(), imml1->GetLength()); index++){
        std::tuple<T, T> t(this->Get(index), imml1->Get(index));
        res->Append(t);
    }
    return res;
}

template <typename T>
ListSequence<T>* ImmutableList<T>::Slice(int index, int n, ImmutableList<T>* as){
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
ImmutableList<ImmutableList<T>>* ImmutableList<T>::Split(bool F(T)){
    ImmutableList<ImmutableList<T>>* newArray = new ImmutableList<ImmutableList<T>>;
    ImmutableList<T>* node = new ImmutableList<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index)) && node->GetLength() != 0){
            newArray->Append(*node);
            node = new ImmutableList<T>();
        } else if (F(this->Get(index)) == 0){
            node->Append(this->Get(index));
        }
    }
    if (node->GetLength() != 0){
        newArray->Append(*node);
    }
    return newArray;
}
