#pragma once
#include <iostream>
#include <tuple>

#include "ListSequence.h"
#include "NodePriorityQueue.cpp"

template <typename T>
class PriorityQueue : public ListSequence<NodePriorityQueue<T>> {
public:
    PriorityQueue(NodePriorityQueue<T>* items, int count);
    PriorityQueue() : ListSequence<NodePriorityQueue<T>>() {};
    PriorityQueue(LinkedList<NodePriorityQueue<T>>& linkedList);
    
    void Set(int index, NodePriorityQueue<T> item) override;
    Sequence<NodePriorityQueue<T>>* Append(NodePriorityQueue<T> item) override;
    Sequence<NodePriorityQueue<T>>* Prepend(NodePriorityQueue<T> item) override;
    Sequence<NodePriorityQueue<T>>* InsertAt(NodePriorityQueue<T> item, int index) override;
    Sequence<NodePriorityQueue<T>>* DelEnd() override;
    
    Sequence<NodePriorityQueue<T>>* Together(Sequence<NodePriorityQueue<T>>* list) override;
    
    std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>* Divide(bool F(NodePriorityQueue<T>));
    
    Sequence<NodePriorityQueue<T>>* CreateNew() override;
};

