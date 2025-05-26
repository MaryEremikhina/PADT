#include <iostream>
#include "NodePriorityQueue.h"

///           КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
NodePriorityQueue<T>::NodePriorityQueue(){}

template <typename T>
NodePriorityQueue<T>::NodePriorityQueue(T value, int priority){
    this->value = value;
    this->priority = priority;
}

template <typename T>
NodePriorityQueue<T>::~NodePriorityQueue(){}

///           ФУНКЦИИ ДЛЯ NODEPRIORITYQUEUE

template <typename T>
T NodePriorityQueue<T>::GetValue(){
    return value;
}

template <typename T>
int NodePriorityQueue<T>::GetPriority(){
    return priority;
}

template <typename T>
void NodePriorityQueue<T>::SetValue(T value){
    this->value = value;
}

template <typename T>
void NodePriorityQueue<T>::SetPriority(int priority){
    this->priority = priority;
}

template <typename T>
void NodePriorityQueue<T>::Set(T value, int priority){
    SetValue(value);
    SetPriority(priority);
}

template <typename T>
bool operator==(NodePriorityQueue<T> node1, NodePriorityQueue<T> node2){
    return (node1.GetValue() == node2.GetValue() && node2.GetPriority() == node2.GetPriority());
}
