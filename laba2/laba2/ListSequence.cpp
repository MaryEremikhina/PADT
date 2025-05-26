#include <iostream>
#include "ListSequence.h"
#include "LinkedList.h"

///                КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
ListSequence<T>::ListSequence(){
    linkedList = new LinkedList<T>();
}

template <typename T>
ListSequence<T>::ListSequence(T* items, int count){
    linkedList = new LinkedList<T>(items, count);
}

template <typename T>
ListSequence<T>::ListSequence(LinkedList<T>& linkedList){
    this->linkedList = new LinkedList<T>(linkedList);
}

template <typename T>
ListSequence<T>::~ListSequence(){
    linkedList->~LinkedList<T>();
}

///           ФУНКЦИИ ДЛЯ LISTSEQUENCE

template <typename T>
T ListSequence<T>::Get(int index){
    return *linkedList->Get(index);
}

template <typename T>
T ListSequence<T>::GetFirst(){
    return *linkedList->GetFirst();
}

template <typename T>
T ListSequence<T>::GetLast(){
    return *linkedList->GetLast();
}

template <typename T>
int ListSequence<T>::GetLength(){
    return linkedList->GetLength();
}

template <typename T>
void ListSequence<T>::Set(int index, T item){
    linkedList->Set(index, item);
}

template <typename T>
LinkedList<T>* ListSequence<T>::GetList(){
    return linkedList;
}

template <typename T>
ListSequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex){
    ListSequence<T>* newArray = this->Instance();
    newArray->GetList()->GetSubList(startIndex, endIndex);
    return newArray;
}

template <typename T>
ListSequence<T>* ListSequence<T>::Append(T item){
    ListSequence<T>* newArray = this->Instance();
    newArray->GetList()->Append(item);
    return newArray;
}

template <typename T>
ListSequence<T>* ListSequence<T>::Prepend(T item){
    ListSequence<T>* newArray = this->Instance();
    newArray->GetList()->Prepend(item);
    return newArray;
}

template <typename T>
ListSequence<T>* ListSequence<T>::InsertAt(T item, int index){
    ListSequence<T>* newArray = this->Instance();
    newArray->GetList()->insertAt(item, index);
    return newArray;
}

template <typename T>
ListSequence<T>* ListSequence<T>::Skip(int index){
    if (index >= GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    return GetSubsequence(index, GetLength() - 1);
}

template <typename T>
ListSequence<T>* ListSequence<T>::Map(T F(T)){
    ListSequence<T>* newArray = this->Instance();
    for (int index = 0; index < GetLength(); index++){
        newArray->Set(index, F(Get(index)));
    }
    return newArray;
}

template <typename T>
T ListSequence<T>::Reduce(T F(T, T), T neutral){
    for (int index = 0; index < GetLength(); index++){
        neutral = F(neutral, Get(index));
    }
    return neutral;
}

template <typename T>
ListSequence<T>* ListSequence<T>::Where(bool F(T)){
    ListSequence<T>* newArray = CreateNew();
    for (int index = 0; index < GetLength(); index++){
        if (F(Get(index))){
            newArray = newArray->Append(Get(index));
        }
    }
    return newArray;
}
