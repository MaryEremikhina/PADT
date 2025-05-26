#pragma once
#include <iostream>
#include <tuple>

#include "ListSequence.h"
#include "NodeDeQueueSegment.h"

template <typename T>
class DeQueueSegment : public ListSequence<NodeDeQueueSegment<T>> {
public:
    DeQueueSegment(NodeDeQueueSegment<T>* items, int count);
    DeQueueSegment();
    DeQueueSegment(LinkedList<NodeDeQueueSegment<T>>& linkedList);
    
    void Set(int index, NodeDeQueueSegment<T> item) override;
    Sequence<NodeDeQueueSegment<T>>* InsertAt(NodeDeQueueSegment<T> item, int index) override;
    
    int GetSize();
    
    Sequence<NodeDeQueueSegment<T>>* Sort();
    Sequence<NodeDeQueueSegment<T>>* Append(T item);
    NodeDeQueueSegment<T> Reduce(NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>, NodeDeQueueSegment<T>), NodeDeQueueSegment<T> neutral);
    
    Sequence<NodeDeQueueSegment<T>>* CreateNew() override;
private:
    int length;
};
