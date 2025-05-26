#include <iostream>
#include "Node.h"
#include <tuple>

///                КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
Node<T>::Node(Node* prev, Node* last, T v){
    previous = prev;
    after = last;
    value = v;
}

template <typename T>
Node<T>::Node(T v){
    previous = NULL;
    after = NULL;
    value = v;
}

template <typename T>
Node<T>::Node(){
    previous = NULL;
    after = NULL;
}

///           ФУНКЦИИ ДЛЯ NODE

template <typename T>
T& Node<T>::GetValue(){
    return value;
}

template <typename T>
Node<T>* Node<T>::GetPrevious(){
    return previous;
}

template <typename T>
Node<T>* Node<T>::GetAfter(){
    return after;
}

template <typename T>
void Node<T>::SetValue(T v){
    value = v;
}

template <typename T>
void Node<T>::SetPrevious(Node<T>* prev){
    previous = prev;
}

template <typename T>
void Node<T>::SetAfter(Node<T>* last){
    after = last;
}

template <typename T>
bool operator==(Node<T> node1, Node<T> node2){
    return node1.GetValue() == node2.GetValue();
}
