#pragma once
#include <iostream>

#include "Node.h"

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(T* items, int count);
    LinkedList(LinkedList<T>& linkedList);
    ~LinkedList();
    
    T* GetFirst();
    T* GetLast();
    T* Get(int index);
    //T operator[](int index);
    void Set(int index, T item);
    LinkedList<T>* GetSubList(int startIndex, int endIndex);
    int GetLength();
    
    bool Compare(LinkedList<T> linkedList);
    
    void Append(T item);
    void Prepend(T item);
    void insertAt(T item, int index);
    LinkedList<T>* Concat(LinkedList<T>* list);
private:
    Node<T>* first;
    Node<T>* last;
    int size;
};
