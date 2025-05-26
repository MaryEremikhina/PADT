#include <iostream>
#include <tuple>

#include "DeQueue.h"

///           ФУНКЦИИ ДЛЯ DEQUEUE

template <typename T>
void DeQueue<T>::Set(int index, T item){
    throw std::invalid_argument("Cannot change in DeQueue");
}

template <typename T>
Sequence<T>* DeQueue<T>::InsertAt(T item, int index){
    throw std::invalid_argument("Cannot insert in the DeQueue");
}

template <typename T>
Sequence<T>* DeQueue<T>::CreateNew(){
    DeQueue<T>* newDeQueue = new DeQueue<T>();
    return newDeQueue;
}

template <typename T>
Sequence<T>* DeQueue<T>::Sort(){
    for (int i = 0; i < this->GetLength(); i++){
        for (int j = 0; j < (this->GetLength() - 1 - i); j++){
            if (this->Get(j) > this->Get(j + 1)){
                T tmp = this->Get(j);
                this->GetList()->Set(j, this->Get(j + 1));
                this->GetList()->Set(j + 1, tmp);
            }
        }
    }
    return this;
}
