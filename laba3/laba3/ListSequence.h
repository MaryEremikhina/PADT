#pragma once
#include <iostream>
#include <tuple>

#include "LinkedList.h"
#include "Sequence.h"

template <typename T>
class ListSequence : public Sequence<T> {
public:
    ListSequence(T* items, int count);
    ListSequence();
    ListSequence(LinkedList<T>& linkedList);
    ~ListSequence();
    
    LinkedList<T>* GetList();
    
    T& GetFirst() override;
    T& GetLast() override;
    T& Get(int index) override;
    T& operator[](int index) override;
    virtual void Set(int index, T item) override;
    int GetLength() override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) override;
    
    virtual Sequence<T>* Append(T item) override;
    virtual Sequence<T>* Prepend(T item) override;
    virtual Sequence<T>* InsertAt(T item, int index) override;
    virtual Sequence<T>* DelStart() override;
    virtual Sequence<T>* DelEnd() override;
    
    template <typename D>
    Sequence<Sequence<D>*>* FlatMap(Sequence<D>* (*F)(T)){
        Sequence<Sequence<D>*>* newSeq = new ListSequence<Sequence<D>*>();
        for (int index = 0; index < GetLength(); index++){
            Sequence<D>* node = F(Get(index));
            newSeq->Append(node);
        }
        return newSeq;
    }
    Sequence<std::tuple<T, T>>* Zip(Sequence<T>* list);
    std::tuple<Sequence<T>*, Sequence<T>*>* UnZip(Sequence<std::tuple<T, T>>* list) override;
    
    virtual Sequence<T>* CreateNew() override;
private:
    LinkedList<T>* linkedList;
};
