#include <iostream>
#include "LinkedList.h"
#include "Node.cpp"

///                КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ

template <typename T>
LinkedList<T>::LinkedList(T* items, int count){
    Node<T>* fi = new Node<T>(items[0]);
    first = fi;
    Node<T>* before = first;
    for (int index = 1; index < count; index++){
        Node<T>* tmp = new Node<T>(before, NULL, items[index]);
        before->SetAfter(tmp);
        before = tmp;
    }
    last = before;
    size = count;
}


template <typename T>
LinkedList<T>::LinkedList(){
    first = NULL;
    last = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& linkedList){
    first = NULL;
    last = NULL;
    size = 0;
        
    Node<T>* node = linkedList.first;
    while (node != NULL) {
        this->Append(*node->GetValue());
        node = node->GetAfter();
    }
}

template <typename T>
LinkedList<T>::~LinkedList(){}

///           ФУНКЦИИ ДЛЯ LINKEDLIST

template <typename T>
T* LinkedList<T>::GetFirst(){
    if (size == 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    return first->GetValue();
}

template <typename T>
T* LinkedList<T>::GetLast(){
    if (size == 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    return last->GetValue();
}

template <typename T>
T* LinkedList<T>::Get(int index){
    T* result;
    if (index >= size || index < 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    if (index == 0){
        result = GetFirst();
    } else if (index == size - 1){
        result = GetLast();
    } else {
        Node<T>* node = first;
        for (int i = 0; i < index; i++){
            node = node->GetAfter();
        }
        result = node->GetValue();
    }
    return result;
}

template <typename T>
void LinkedList<T>::Set(int index, T item){
    if (index >= size || index < 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    if (index == 0){
        first->SetValue(item);
    } else if (index == size - 1){
        last->SetValue(item);
    } else {
        Node<T>* node = first;
        for (int i = 0; i < index; i++){
            node = node->GetAfter();
        }
        return node->SetValue(item);
    }
}

/*template <typename T>
T LinkedList<T>::operator[](int index){
    return *Get(index);
}*/

template <typename T>
int LinkedList<T>::GetLength(){
    return size;
}

template <typename T>
bool LinkedList<T>::Compare(LinkedList<T> linkedList){
    if (size != linkedList.GetLength()){
        return false;
    }
    int flag = 1;
    for (int index = 0; index < this->GetLength(); index++){
        if (*this->Get(index) != *linkedList.Get(index)){
            flag = 0;
            break;
        }
    }
    if (flag == 0){
        return false;
    } else {
        return true;
    }
}

template <typename T>
void LinkedList<T>::Append(T item){
    if (size == 0){
        Node<T>* node = new Node<T>(item);
        first = node;
        last = node;
    } else {
        Node<T>* node = new Node<T>(last, NULL, item);
        last->SetAfter(node);
        last = node;
    }
    size++;
}

template <typename T>
void LinkedList<T>::Prepend(T item){
    size++;
    Node<T>* node = new Node<T>(NULL, first, item);
    first->SetPrevious(node);
    first = node;
}

template <typename T>
LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex){
    if (startIndex < 0 || startIndex >= size || endIndex < 0 || endIndex >= size || startIndex == endIndex){
        throw std::out_of_range("IndexOutOfRange");
    }
    LinkedList<T>* list = new LinkedList<T>();
    for (int i = startIndex; i <= endIndex; i++){
        list->Append(*Get(i));
    }
    first = list->first;
    last = list->last;
    size = endIndex - startIndex + 1;
    return this;
}

template <typename T>
void LinkedList<T>::insertAt(T item, int index){
    if (index >= size || index < 0){
        throw std::out_of_range("IndexOutOfRange");
    }
    size++;
    if (index == 0){
        Prepend(item);
    } else {
        Node<T>* node = first;
        for (int i = 0; i < index - 1; i++){
            node = node->GetAfter();
        }
        Node<T>* newnode = new Node(node, node->GetAfter(), item);
        node->SetAfter(newnode);
        node->GetAfter()->SetPrevious(newnode);
    }
}

template <typename T>
LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* list){
    LinkedList<T>* listed = new LinkedList<T>();
    listed->first = first;
    listed->last = list->last;
    listed->size = size + list->size;
    last->SetAfter(list->first);
    list->first->SetPrevious(last);
    return listed;
}
