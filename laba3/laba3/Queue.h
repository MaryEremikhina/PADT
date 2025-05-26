#pragma once
#include <iostream>
#include <tuple>

#include "ListSequence.h"

template <typename T>
class Queue : public ListSequence<T> {
public:
    Queue(T* items, int count) : ListSequence<T>(items, count) {};
    Queue() : ListSequence<T>() {};
    Queue(LinkedList<T>& linkedList) : ListSequence<T>(linkedList) {};
    
    void Set(int index, T item) override;
    Sequence<T>* Prepend(T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    Sequence<T>* DelEnd() override;
    
    std::tuple<Sequence<T>*, Sequence<T>*>* Divide(bool F(T));
    
    Sequence<T>* CreateNew() override;
};
