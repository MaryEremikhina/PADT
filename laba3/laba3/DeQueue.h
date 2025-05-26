#pragma once
#include <iostream>
#include <tuple>

#include "ListSequence.h"

template <typename T>
class DeQueue : public ListSequence<T> {
public:
    DeQueue(T* items, int count) : ListSequence<T>(items, count) {};
    DeQueue() : ListSequence<T>() {};
    DeQueue(LinkedList<T>& linkedList) : ListSequence<T>(linkedList) {};
    
    void Set(int index, T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    
    Sequence<T>* Sort();
    
    Sequence<T>* CreateNew() override;
};
