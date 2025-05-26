#pragma once
#include <iostream>

template <typename T>
class Node {
public:
    Node();
    Node(T v);
    Node(Node* prev, Node* last, T v);
    ~Node();
    
    T* GetValue();
    Node<T>* GetPrevious();
    Node<T>* GetAfter();
    void SetValue(T v);
    void SetPrevious(Node* prev);
    void SetAfter(Node* last);
private:
    Node* previous;
    Node* after;
    T value;
};
