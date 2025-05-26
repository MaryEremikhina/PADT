#pragma once
#include <iostream>
#include <tuple>

template <typename T>
class Sequence {
public:
    virtual ~Sequence() = default;
    
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual T& operator[](int index) = 0;
    virtual void Set(int index, T value) = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    bool FindSubSequence(Sequence<T>* subSequence);
    virtual Sequence<T>* Together(Sequence<T>* list);
    
    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(T item, int index) = 0;
    virtual Sequence<T>* DelStart() = 0;
    virtual Sequence<T>* DelEnd() = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list);
    
    Sequence<T>* Skip(int index);
    Sequence<T>* Map(T F(T));
    T Reduce(T F(T, T), T neutral);
    Sequence<T>* Where(bool F(T));
    virtual std::tuple<Sequence<T>*, Sequence<T>*>* UnZip(Sequence<std::tuple<T, T>>* list) = 0;
    
    virtual Sequence<T>* CreateNew() = 0;
    bool Compare(Sequence<T>* seq);
private:
};
