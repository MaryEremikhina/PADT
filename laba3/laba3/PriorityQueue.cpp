#include <iostream>
#include <tuple>

#include "PriorityQueue.h"
#include "NodePriorityQueue.h"

///           ФУНКЦИИ ДЛЯ PRIORITYQUEUE

template <typename T>
void PriorityQueue<T>::Set(int index, NodePriorityQueue<T> item){
    throw std::invalid_argument("Cannot change in PriorityQueue");
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::Prepend(NodePriorityQueue<T> item){
    throw std::invalid_argument("Cannot prepend in the PriorityQueue");
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::InsertAt(NodePriorityQueue<T> item, int index){
    throw std::invalid_argument("Cannot insert in the PriorityQueue");
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::DelEnd(){
    throw std::invalid_argument("Cannot delete from the end in the PriorityQueue");
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::CreateNew(){
    PriorityQueue<T>* newPriorityQueue = new PriorityQueue<T>();
    return newPriorityQueue;
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::Append(NodePriorityQueue<T> item){
    if (this->GetLength() != 0){
        bool flag = false;
        for (int index = 0; index < this->GetLength(); index++){
            if (this->Get(index).GetPriority() < item.GetPriority()){
                this->GetList()->insertAt(item, index);
                flag = true;
                break;
            }
        }
        if (flag == false){
            this->GetList()->Append(item);
        }
    } else {
        this->GetList()->Append(item);
    }
    return this;
}

template <typename T>
Sequence<NodePriorityQueue<T>>* PriorityQueue<T>::Together(Sequence<NodePriorityQueue<T>>* list){
    throw std::invalid_argument("Cannot together in the PriorityQueue (because of priority)");
}

template <typename T>
std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>* PriorityQueue<T>::Divide(bool F(NodePriorityQueue<T>)){
    Sequence<NodePriorityQueue<T>>* seqTrue = new PriorityQueue<T>();
    Sequence<NodePriorityQueue<T>>* seqFalse = new PriorityQueue<T>();
    for (int index = 0; index < this->GetLength(); index++){
        if (F(this->Get(index))){
            seqTrue->Append(this->Get(index));
        } else {
            seqFalse->Append(this->Get(index));
        }
    }
    std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>* t = new std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>(seqTrue, seqFalse);
    return t;
}

///           КОНСТРУКТОРЫ

template <typename T>
PriorityQueue<T>::PriorityQueue(NodePriorityQueue<T>* items, int count){
    PriorityQueue();
    for (int index = 0; index < count; index++){
        Append(items[index]);
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue(LinkedList<NodePriorityQueue<T>>& linkedList){
    PriorityQueue();
    for (int index = 0; index < linkedList.GetLength(); index++){
        Append(linkedList[index]);
    }
}
