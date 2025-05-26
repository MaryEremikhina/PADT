#pragma once
#include <iostream>

template <typename T>
class Sequence {
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual void Set(int index, T value) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    
    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(T item, int index) = 0;
    
    virtual Sequence<T>* Skip(int index) = 0;
    virtual Sequence<T>* Map(T F(T)) = 0;
    virtual T Reduce(T F(T, T), T neutral) = 0;
    virtual Sequence<T>* Where(bool F(T)) = 0;
private:
};
