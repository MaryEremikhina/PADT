#include "Sequence.h"

///           ФУНКЦИИ ДЛЯ SEQUENCE

template <typename T>
Sequence<T>* Sequence<T>::Concat(Sequence<T>* list){
    Sequence<T>* newSeq = CreateNew();
    for (int index = 0; index < this->GetLength(); index++){
        newSeq->Append(this->Get(index));
    }
    for (int index = 0; index < list->GetLength(); index++){
        newSeq->Append(list->Get(index));
    }
    return newSeq;
}

template <typename T>
Sequence<T>* Sequence<T>::Together(Sequence<T>* list){
    Sequence<T>* newSeq = CreateNew();
    if (GetLength() > list->GetLength()){
        for (int index = 0; index < list->GetLength(); index++){
            newSeq->Append(Get(index));
            newSeq->Append(list->Get(index));
        }
        for (int i = list->GetLength(); i < GetLength(); i++){
            newSeq->Append(Get(i));
        }
    } else {
        for (int index = 0; index < GetLength(); index++){
            newSeq->Append(Get(index));
            newSeq->Append(list->Get(index));
        }
        for (int i = list->GetLength(); i < list->GetLength(); i++){
            newSeq->Append(list->Get(i));
        }
    }
    return newSeq;
}

template <typename T>
bool Sequence<T>::FindSubSequence(Sequence<T>* subSequence){
    if (GetLength() < subSequence->GetLength()){
        throw std::out_of_range("IndexOutOfRange");
    }
    bool flag = false;
    for (int index = 0; index < (GetLength() - subSequence->GetLength() + 1); index++){
        if (Get(index) == subSequence->GetFirst() && flag == false){
            flag = true;
            for (int i = 1; i < subSequence->GetLength(); i++){
                if (Get(index + i) != subSequence->Get(i)){
                    flag = false;
                    break;
                }
            }
            if (flag){
                break;
            }
        }
    }
    return flag;
}

template <typename T>
Sequence<T>* Sequence<T>::Skip(int index){
    Sequence<T>* newSeq = CreateNew();
    for (int i = index; i < GetLength(); i++){
        newSeq->Append(Get(i));
    }
    return newSeq;
}

template <typename T>
Sequence<T>* Sequence<T>::Map(T F(T)){
    Sequence<T>* newSeq = CreateNew();
    for (int index = 0; index < this->GetLength(); index++){
        newSeq->Append(F(this->Get(index)));
    }
    return newSeq;
}

template <typename T>
T Sequence<T>::Reduce(T F(T, T), T neutral){
    for (int index = 0; index < GetLength(); index++){
        neutral = F(Get(index), neutral);
    }
    return neutral;
}

template <typename T>
Sequence<T>* Sequence<T>::Where(bool F(T)){
    Sequence<T>* newSeq = CreateNew();
    for (int index = 0; index < GetLength(); index++){
        if (F(Get(index))){
            newSeq->Append(Get(index));
        }
    }
    return newSeq;
}

template <typename T>
bool Sequence<T>::Compare(Sequence<T>* seq){
    bool flag = true;
    if (this->GetLength() == seq->GetLength()){
        for (int index = 0; index < this->GetLength(); index++){
            if (this->Get(index) != seq->Get(index)){
                flag = false;
                break;
            }
        }
        return flag;
    } else {
        return false;
    }
}
