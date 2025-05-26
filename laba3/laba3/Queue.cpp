#include <iostream>
#include <tuple>

#include "Queue.h"

///           ФУНКЦИИ ДЛЯ QUEUE

template <typename T>
void Queue<T>::Set(int index, T item){
    throw std::invalid_argument("Cannot change in Queue");
}

template <typename T>
Sequence<T>* Queue<T>::Prepend(T item){
    throw std::invalid_argument("Cannot prepend in the Queue");
}

template <typename T>
Sequence<T>* Queue<T>::InsertAt(T item, int index){
    throw std::invalid_argument("Cannot insert in the Queue");
}

template <typename T>
Sequence<T>* Queue<T>::DelEnd(){
    throw std::invalid_argument("Cannot delete from the end in the Queue");
}

template <typename T>
Sequence<T>* Queue<T>::CreateNew(){
    Queue<T>* newQueue = new Queue<T>();
    return newQueue;
}

template <typename T>
std::tuple<Sequence<T>*, Sequence<T>*>* Queue<T>::Divide(bool F(T)){
    Sequence<T>* seqTrue = new Queue<T>();
    Sequence<T>* seqFalse = new Queue<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index))){
            seqTrue->Append(this->Get(index));
        } else {
            seqFalse->Append(this->Get(index));
        }
    }
    std::tuple<Sequence<T>*, Sequence<T>*>* t = new std::tuple<Sequence<T>*, Sequence<T>*>(seqTrue, seqFalse);
    return t;
}
