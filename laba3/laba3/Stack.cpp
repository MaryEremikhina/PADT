#include <iostream>
#include <tuple>

#include "Stack.h"

///           ФУНКЦИИ ДЛЯ STACK

template <typename T>
void Stack<T>::Set(int index, T item){
    throw std::invalid_argument("Cannot change in Stack");
}

template <typename T>
Sequence<T>* Stack<T>::Prepend(T item){
    throw std::invalid_argument("Cannot prepend in the Stack");
}

template <typename T>
Sequence<T>* Stack<T>::InsertAt(T item, int index){
    throw std::invalid_argument("Cannot insert in the Stack");
}

template <typename T>
Sequence<T>* Stack<T>::DelStart(){
    throw std::invalid_argument("Cannot delete from the start in the Stack");
}

template <typename T>
Sequence<T>* Stack<T>::CreateNew(){
    Stack<T>* newStack = new Stack<T>();
    return newStack;
}
