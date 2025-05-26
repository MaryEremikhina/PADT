#pragma once

template <typename T>
class NodeDeQueueSegment {
public:
    NodeDeQueueSegment();
    NodeDeQueueSegment(T* items, int count);
    NodeDeQueueSegment(int count);
    NodeDeQueueSegment(NodeDeQueueSegment<T>& other);
    ~NodeDeQueueSegment();
    
    int GetLength();
    T Get(int index);
    T operator[](int index);
    void Set(int index, T item);
    NodeDeQueueSegment<T>& operator=(NodeDeQueueSegment<T>& other);
    NodeDeQueueSegment<T>* Append(T item);
    NodeDeQueueSegment<T>* Sort();
    
    void Clear();
private:
    T* data;
    int count;
};

template <typename T>
bool operator==(NodeDeQueueSegment<T> node1, NodeDeQueueSegment<T> node2);
