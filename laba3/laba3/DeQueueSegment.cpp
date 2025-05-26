#include <iostream>
#include <tuple>
#include <vector>

#include "DeQueueSegment.h"
#include "NodeDeQueueSegment.cpp"

template <typename T>
void Merge(std::vector<T>& v, int left, int mid, int right) {
    std::vector<T> leftVec(v.begin() + left, v.begin() + mid + 1);
    std::vector<T> rightVec(v.begin() + mid + 1, v.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < leftVec.size() && j < rightVec.size()) {
        if (leftVec[i] < rightVec[j]) {
            v[k++] = leftVec[i++];
        } else {
            v[k++] = rightVec[j++];
        }
    }

    while (i < leftVec.size()) {
        v[k++] = leftVec[i++];
    }

    while (j < rightVec.size()) {
        v[k++] = rightVec[j++];
    }
}

template <typename T>
void MergeSort(std::vector<T>& v, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);
    Merge(v, left, mid, right);
}

template <typename T>
void MergeSort(std::vector<T>& v) {
    MergeSort(v, 0, v.size() - 1);
}

template <typename T>
void SortedVector(std::vector<T>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < (v.size() - 1 - i); j++){
            if (v[j] > v[j + 1]){
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

///        КОНСТРУКТОРЫ

template <typename T>
DeQueueSegment<T>::DeQueueSegment(NodeDeQueueSegment<T>* items, int count) : ListSequence<NodeDeQueueSegment<T>>(items, count){
    length = items[0].GetLength();
}

template <typename T>
DeQueueSegment<T>::DeQueueSegment() :  ListSequence<NodeDeQueueSegment<T>>(){
    length = 0;
}

template <typename T>
DeQueueSegment<T>::DeQueueSegment(LinkedList<NodeDeQueueSegment<T>>& linkedList) : ListSequence<NodeDeQueueSegment<T>>(linkedList){
    length = linkedList.Get(0).GetLength();
}

///           ФУНКЦИИ ДЛЯ DEQUEUESEGMENT

template <typename T>
void DeQueueSegment<T>::Set(int index, NodeDeQueueSegment<T> item){
    throw std::invalid_argument("Cannot change in DeQueueSegment");
}

template <typename T>
Sequence<NodeDeQueueSegment<T>>* DeQueueSegment<T>::InsertAt(NodeDeQueueSegment<T> item, int index){
    throw std::invalid_argument("Cannot insert in the DeQueueSegment");
}

template <typename T>
int DeQueueSegment<T>::GetSize(){
    return length;
}

template <typename T>
Sequence<NodeDeQueueSegment<T>>* DeQueueSegment<T>::CreateNew(){
    DeQueueSegment<T>* newDeQueueSegment = new DeQueueSegment<T>();
    return newDeQueueSegment;
}

template <typename T>
NodeDeQueueSegment<T> DeQueueSegment<T>::Reduce(NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>, NodeDeQueueSegment<T>), NodeDeQueueSegment<T> neutral){
    for (int index = 0; index < this->GetLength(); index++){
        NodeDeQueueSegment<T> tmp = F(this->Get(index), neutral);
        for (int j = 0; j < tmp.GetLength(); j++){
            neutral.Set(j, tmp.Get(j));
        }
    }
    return neutral;
}

template <typename T>
Sequence<NodeDeQueueSegment<T>>* DeQueueSegment<T>::Sort() {
    std::vector<T> v;
    for (int i = 0; i < this->GetLength(); i++) {
        for (int j = 0; j < this->Get(i).GetLength(); j++) {
            v.push_back(this->Get(i).Get(j));
        }
    }

//    SortedVector(v);
    MergeSort(v);
    Sequence<NodeDeQueueSegment<T>>* newSeq = new DeQueueSegment<T>();
    NodeDeQueueSegment<T> node = NodeDeQueueSegment<T>();
    for (int index = 0; index < v.size(); index++){
        node.Append(v[index]);
        if ((index + 1) % length == 0){
            newSeq->Append(node);
            node.Clear();
        }
    }
//    newSeq->Append(node);
    return newSeq;
}

template <typename T>
Sequence<NodeDeQueueSegment<T>>* DeQueueSegment<T>::Append(T item){
    if (this->Get(this->GetLength() - 1).GetLength() == length){
        NodeDeQueueSegment<T> node = NodeDeQueueSegment<T>();
        node.Append(item);
        this->ListSequence<NodeDeQueueSegment<T>>::Append(node);
    } else {
        this->Get(this->GetLength() - 1).Append(item);
    }
    return this;
}
