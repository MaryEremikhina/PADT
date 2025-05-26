#include <iostream>
#include <tuple>

#include "ListSequence.h"
#include "LinkedList.cpp"

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
    delete linkedList;
}

///           ФУНКЦИИ ДЛЯ LISTSEQUENCE

template <typename T>
T& ListSequence<T>::Get(int index){
    return linkedList->Get(index);
}

template <typename T>
T& ListSequence<T>::operator[](int index){
    return Get(index);
}

template <typename T>
T& ListSequence<T>::GetFirst(){
    return linkedList->GetFirst();
}

template <typename T>
T& ListSequence<T>::GetLast(){
    return linkedList->GetLast();
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
Sequence<T>* ListSequence<T>::CreateNew(){
    ListSequence<T>* newList = new ListSequence<T>();
    return newList;
}

template <typename T>
Sequence<T>* ListSequence<T>::GetSubsequence(int startIndex, int endIndex){
    LinkedList<T>* newList = linkedList->GetSubList(startIndex, endIndex);
    Sequence<T>* newSeq = new ListSequence<T>(*newList);
    return newSeq;
}

template <typename T>
Sequence<T>* ListSequence<T>::Append(T item){
    linkedList->Append(item);
    return this;
}

template <typename T>
Sequence<T>* ListSequence<T>::Prepend(T item){
    linkedList->Prepend(item);
    return this;
}

template <typename T>
Sequence<T>* ListSequence<T>::InsertAt(T item, int index){
    linkedList->insertAt(item, index);
    return this;
}

template <typename T>
Sequence<T>* ListSequence<T>::DelStart(){
    LinkedList<T>* newLinkedList = linkedList->DelStart();
    Sequence<T>* newList = new ListSequence<T>(*newLinkedList);
    return newList;
}

template <typename T>
Sequence<T>* ListSequence<T>::DelEnd(){
    LinkedList<T>* newLinkedList = linkedList->DelEnd();
    Sequence<T>* newList = new ListSequence<T>(*newLinkedList);
    return newList;
}


template <typename T>
Sequence<std::tuple<T, T>>* ListSequence<T>::Zip(Sequence<T>* list){
    Sequence<std::tuple<T, T>>* newSeq = new ListSequence<std::tuple<T, T>>();
    int minLength = std::min(GetLength(), list->GetLength());
    for (int i = 0; i < minLength; i++) {
        newSeq->Append(std::make_tuple(Get(i), list->Get(i)));
    }
    return newSeq;
}

template <typename T>
std::tuple<Sequence<T>*, Sequence<T>*>* ListSequence<T>::UnZip(Sequence<std::tuple<T, T>>* list){
    Sequence<T>* seq1 = new ListSequence<T>();
    Sequence<T>* seq2 = new ListSequence<T>();
    for (int index = 0; index < list->GetLength(); index++){
        std::tuple<T, T>& node = list->Get(index);
        seq1->Append(std::get<0>(node));
        seq2->Append(std::get<1>(node));
    }
    return new std::tuple<Sequence<T>*, Sequence<T>*>(seq1, seq2);
}
