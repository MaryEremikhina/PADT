#pragma once

template <typename T>
class NodePriorityQueue {
public:
    NodePriorityQueue();
    NodePriorityQueue(T value, int priority);
    ~NodePriorityQueue();
    
    T GetValue();
    int GetPriority();
    void Set(T value, int priority);
    void SetValue(T value);
    void SetPriority(int priority);
private:
    T value;
    int priority;
};

template <typename T>
bool operator==(NodePriorityQueue<T> node1, NodePriorityQueue<T> node2);
