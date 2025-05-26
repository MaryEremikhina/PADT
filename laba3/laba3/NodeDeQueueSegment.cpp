#include <iostream>
#include "NodeDeQueueSegment.h"

///           КОНСТРУКТОРЫ И ДЕСТРУКТОР

template <typename T>
NodeDeQueueSegment<T>::NodeDeQueueSegment(){
    data = NULL;
    count = 0;
}

template <typename T>
NodeDeQueueSegment<T>::NodeDeQueueSegment(int count){
    data = new T[count];
    this->count = count;
}

template <typename T>
NodeDeQueueSegment<T>::NodeDeQueueSegment(T* items, int count){
    data = new T[count];
    for (int index = 0; index < count; index++){
        data[index] = items[index];
    }
    this->count = count;
}

template <typename T>
NodeDeQueueSegment<T>::NodeDeQueueSegment(NodeDeQueueSegment<T>& other) {
    count = other.count;
    data = new T[count];
    for (int i = 0; i < count; i++)
        data[i] = other.data[i];
}

template <typename T>
NodeDeQueueSegment<T>::~NodeDeQueueSegment(){
    delete[] data;
}

///           ФУНКЦИИ ДЛЯ NODEDEQUEUESEGENT

template <typename T>
int NodeDeQueueSegment<T>::GetLength(){
    return count;
}

template <typename T>
T NodeDeQueueSegment<T>::Get(int index){
    return data[index];
}

template <typename T>
T NodeDeQueueSegment<T>::operator[](int index){
    return data[index];
}

template <typename T>
void NodeDeQueueSegment<T>::Set(int index, T item){
    data[index] = item;
}

template <typename T>
NodeDeQueueSegment<T>& NodeDeQueueSegment<T>::operator=(NodeDeQueueSegment<T>& other){
    if (this != &other) {
        delete[] data;
        count = other.GetLength();
        data = new T[count];
        for (int i = 0; i < count; i++) {
            data[i] = other.Get(i);
        }
    }
        return *this;
}

template <typename T>
NodeDeQueueSegment<T>* NodeDeQueueSegment<T>::Append(T item){
    T* newData = new T[GetLength() + 1];
    for (int index = 0; index < GetLength(); index++){
        newData[index] = this->Get(index);
    }
    newData[GetLength()] = item;
    delete[] data;
    data = newData;
    count++;
    return this;
}

template <typename T>
NodeDeQueueSegment<T>* NodeDeQueueSegment<T>::Sort(){
    for (int i = 0; i < this->GetLength(); i++){
        for (int j = 0; j < this->GetLength(); j++){
            if (this->Get(j) > this->Get(j + 1)){
                std::swap(this->Get(j), this->Get(j + 1));
            }
        }
    }
    return this;
}

template <typename T>
void NodeDeQueueSegment<T>::Clear(){
    data = NULL;
    count = 0;
}

template <typename T>
bool operator==(NodeDeQueueSegment<T> node1, NodeDeQueueSegment<T> node2){
    if (node1.GetLength() != node2.GetLength()){
        return false;
    }
    bool flag = true;
    for (int index = 0; index < node1.GetLength(); index++){
        if (node1.Get(index) != node2.Get(index)){
            flag = false;
            break;
        }
    }
    return flag;
}
