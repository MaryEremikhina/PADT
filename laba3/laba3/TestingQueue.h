#pragma once
#include <iostream>
#include <tuple>

#include "Queue.h"

///         КОНСТАНТНЫЕ ОТВЕТЫ ДЛЯ ПРОВЕРКИ

inline int listMapQ[6] = {0, 10, 20, 30, 40, 50};
inline int* ptrMapQ = listMapQ;
inline Queue<int> QueueMap = Queue<int>(ptrMapQ, 6);

inline int listWhereQ[3] = {0, 2, 4};
inline int* ptrWhereQ = listWhereQ;
inline Queue<int> QueueWhere = Queue<int>(ptrWhereQ, 3);

inline int QueueReduce = 15;

inline int newlistConcatQ[4] = {6, 7, 8, 9};
inline int* ptrnewlistConcatQ = newlistConcatQ;
inline Sequence<int>* newQueueConcat = new Queue<int>(ptrnewlistConcatQ, 4);
inline int listConcatQ[10] = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
inline int* ptrlistConcatQ = listConcatQ;
inline Queue<int> QueueConcat = Queue<int>(ptrlistConcatQ, 10);

inline int listSubSequenceQ[3] = {1, 2, 3};
inline int* ptrSubSequenceQ = listSubSequenceQ;
inline Queue<int> QueueSubSequence = Queue<int>(ptrSubSequenceQ, 3);

inline int listFindSubSequenceQ[3] = {3, 4, 5};
inline int* ptrFindSubSequenceQ = listFindSubSequenceQ;
inline Sequence<int>* QueueFindSubSequence = new Queue<int>(ptrFindSubSequenceQ, 3);
inline bool BoolQueueFindSubSequence = true;

inline int newlistTogetherQ[4] = {6, 7, 8, 9};
inline int* newptrTogetherQ = newlistTogetherQ;
inline Sequence<int>* newQueueTogether = new Queue<int>(newptrTogetherQ, 4);
inline int listTogetherQ[10] = {0, 6, 1, 7, 2, 8, 3, 9, 4, 5};
inline int* ptrTogetherQ = listTogetherQ;
inline Queue<int> QueueTogether = Queue<int>(ptrTogetherQ, 10);

inline int listDivide1Q[3] = {0, 2, 4};
inline int* ptrDivide1Q = listDivide1Q;
inline Sequence<int>* QueueDivide1 = new Queue<int>(ptrDivide1Q, 3);
inline int listDivide2Q[3] = {1, 3, 5};
inline int* ptrDivide2Q = listDivide2Q;
inline Sequence<int>* QueueDivide2 = new Queue<int>(ptrDivide2Q, 3);
inline std::tuple<Sequence<int>*, Sequence<int>*> QueueDivide = std::make_tuple(QueueDivide1, QueueDivide2);

///      КОНСТАНТНЫЕ ФУНКЦИИ ДЛЯ ПРОВЕРКИ ФУНКЦИЙ

inline int FMapQ(int x){
    return 10 * x;
}

inline bool FWhereQ(int x){
    return x % 2 == 0;
}

inline int FReduceQ(int x, int y){
    return x + y;
}

inline bool FDivideQ(int x){
    return x % 2 == 0;
}
 
///        ФУНКЦИИ ДЛЯ ПРОВЕРКИ

template <typename T>
bool TestingMapQ(Queue<T>* q, T F(T), Queue<T>& testQ);

template <typename T>
bool TestingWhereQ(Queue<T>* q, bool F(T), Queue<T>& testQ);

template <typename T>
bool TestingReduceQ(Queue<T>* q, T F(T, T), T neutral, T testQ);

template <typename T>
bool TestingConcatQ(Queue<T>* q, Sequence<T>* seq, Queue<T>& testQ);

template <typename T>
bool TestingGetSubSequenceQ(Queue<T>* q, int startIndex, int endIndex, Queue<T>& testQ);

template <typename T>
bool TestingFindSubSequenceQ(Queue<T>* q, Sequence<T>* subSequence, bool testQ);

template <typename T>
bool TestingTogetherQ(Queue<T>* q, Sequence<T>* newQueue, Queue<T>& testQ);

template <typename T>
bool TestingDivideQ(Queue<T>* q, bool F(T), std::tuple<Sequence<T>*, Sequence<T>*>& testQ);

template <typename T>
inline void TestingQueue(Queue<T>* q);
