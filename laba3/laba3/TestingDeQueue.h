#pragma once
#include <iostream>
#include <tuple>

#include "DeQueue.h"

///         КОНСТАНТНЫЕ ОТВЕТЫ ДЛЯ ПРОВЕРКИ

inline int listSortDQ[6] = {0, 1, 2, 3, 4, 5};
inline int* ptrSortDQ = listSortDQ;
inline DeQueue<int> DeQueueSort = DeQueue<int>(ptrSortDQ, 6);

inline int listMapDQ[6] = {0, 10, 20, 30, 40, 50};
inline int* ptrMapDQ = listMapDQ;
inline DeQueue<int> DeQueueMap = DeQueue<int>(ptrMapDQ, 6);

inline int listWhereDQ[3] = {0, 2, 4};
inline int* ptrWhereDQ = listWhereDQ;
inline DeQueue<int> DeQueueWhere = DeQueue<int>(ptrWhereDQ, 3);

inline int DeQueueReduce = 15;

inline int newlistConcatDQ[4] = {6, 7, 8, 9};
inline int* ptrnewlistConcatDQ = newlistConcatDQ;
inline Sequence<int>* newDeQueueConcat = new DeQueue<int>(ptrnewlistConcatDQ, 4);
inline int listConcatDQ[10] = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
inline int* ptrlistConcatDQ = listConcatDQ;
inline DeQueue<int> DeQueueConcat = DeQueue<int>(ptrlistConcatDQ, 10);

inline int listSubSequenceDQ[3] = {1, 2, 3};
inline int* ptrSubSequenceDQ = listSubSequenceDQ;
inline DeQueue<int> DeQueueSubSequence = DeQueue<int>(ptrSubSequenceDQ, 3);

inline int listFindSubSequenceDQ[3] = {3, 4, 5};
inline int* ptrFindSubSequenceDQ = listFindSubSequenceDQ;
inline Sequence<int>* DeQueueFindSubSequence = new DeQueue<int>(ptrFindSubSequenceDQ, 3);
inline bool BoolDeQueueFindSubSequence = true;

inline int newlistTogetherDQ[4] = {6, 7, 8, 9};
inline int* newptrTogetherDQ = newlistTogetherDQ;
inline Sequence<int>* newDeQueueTogether = new DeQueue<int>(newptrTogetherDQ, 4);
inline int listTogetherDQ[10] = {0, 6, 1, 7, 2, 8, 3, 9, 4, 5};
inline int* ptrTogetherDQ = listTogetherDQ;
inline DeQueue<int> DeQueueTogether = DeQueue<int>(ptrTogetherDQ, 10);

///      КОНСТАНТНЫЕ ФУНКЦИИ ДЛЯ ПРОВЕРКИ ФУНКЦИЙ

inline int FMapDQ(int x){
    return 10 * x;
}

inline bool FWhereDQ(int x){
    return x % 2 == 0;
}

inline int FReduceDQ(int x, int y){
    return x + y;
}
 
///        ФУНКЦИИ ДЛЯ ПРОВЕРКИ

template <typename T>
bool TestingSortDQ(DeQueue<T>* dq, DeQueue<T>& testDQ);

template <typename T>
bool TestingMapDQ(DeQueue<T>* dq, T F(T), DeQueue<T>& testDQ);

template <typename T>
bool TestingWhereDQ(DeQueue<T>* dq, bool F(T), DeQueue<T>& testDQ);

template <typename T>
bool TestingReduceDQ(DeQueue<T>* dq, T F(T, T), T neutral, T testDQ);

template <typename T>
bool TestingConcatDQ(DeQueue<T>* dq, Sequence<T>* seq, DeQueue<T>& testDQ);

template <typename T>
bool TestingGetSubSequenceDQ(DeQueue<T>* dq, int startIndex, int endIndex, DeQueue<T>& testDQ);

template <typename T>
bool TestingFindSubSequenceDQ(DeQueue<T>* dq, Sequence<T>* subSequence, bool testDQ);

template <typename T>
bool TestingTogetherDQ(DeQueue<T>* dq, Sequence<T>* newDeQueue, DeQueue<T>& testDQ);

template <typename T>
inline void TestingDeQueue(DeQueue<T>* dq);
