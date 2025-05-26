#pragma once
#include <iostream>
#include "LinkedList.cpp"
#include "Sequence.h"

template <typename T>
class ListSequence : public Sequence<T> {
public:
    ListSequence(T* items, int count);
    ListSequence();
    ListSequence(LinkedList<T>& linkedList);
    ~ListSequence();
    
    T GetFirst() override;
    T GetLast() override;
    T Get(int index) override;
    void Set(int index, T item) override;
    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    int GetLength() override;
    LinkedList<T>* GetList();
    
    ListSequence<T>* Append(T item) override;
    ListSequence<T>* Prepend(T item) override;
    ListSequence<T>* InsertAt(T item, int index) override;
    
    ListSequence<T>* Skip(int index) override;
    ListSequence<T>* Map(T F(T)) override;
    T Reduce(T F(T, T), T neutral) override;
    ListSequence<T>* Where(bool F(T)) override;
    
    virtual ListSequence<T>* Instance() = 0;
    virtual ListSequence<T>* Clone() = 0;
    virtual ListSequence<T>* CreateNew() = 0;
private:
    LinkedList<T>* linkedList;
};
