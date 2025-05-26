#pragma once
#include <iostream>
#include <tuple>

#include "ListSequence.h"

template <typename T>
class Stack : public ListSequence<T> {
public:
    Stack(T* items, int count) : ListSequence<T>(items, count) {};
    Stack() : ListSequence<T>() {};
    Stack(LinkedList<T>& linkedList) : ListSequence<T>(linkedList) {};
    
    void Set(int index, T item) override;
    Sequence<T>* Prepend(T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    Sequence<T>* DelStart() override;
    
    Sequence<T>* CreateNew() override;
};
