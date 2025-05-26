#pragma once
#include <iostream>
#include <tuple>

#include "PriorityQueue.h"

///         КОНСТАНТНЫЕ ОТВЕТЫ ДЛЯ ПРОВЕРКИ

inline NodePriorityQueue<int> listMapPQ[6] = {NodePriorityQueue<int>(0, 0), NodePriorityQueue<int>(10, 1), NodePriorityQueue<int>(20, 2), NodePriorityQueue<int>(30, 3), NodePriorityQueue<int>(40, 4), NodePriorityQueue<int>(50, 5)};
inline NodePriorityQueue<int>* ptrMapPQ = listMapPQ;
inline PriorityQueue<int> PriorityQueueMap = PriorityQueue<int>(ptrMapPQ, 6);

inline NodePriorityQueue<int> listWherePQ[3] = {NodePriorityQueue<int>(0, 0), NodePriorityQueue<int>(2, 2), NodePriorityQueue<int>(4, 4)};
inline NodePriorityQueue<int>* ptrWherePQ = listWherePQ;
inline PriorityQueue<int> PriorityQueueWhere = PriorityQueue<int>(ptrWherePQ, 3);

inline NodePriorityQueue<int> PriorityQueueReduce = NodePriorityQueue<int>(15, 15);

inline NodePriorityQueue<int> newlistConcatPQ[4] = {NodePriorityQueue<int>(9, 9), NodePriorityQueue<int>(8, 8), NodePriorityQueue<int>(7, 7), NodePriorityQueue<int>(6, 6)};
inline NodePriorityQueue<int>* ptrnewlistConcatPQ = newlistConcatPQ;
inline Sequence<NodePriorityQueue<int>>* newPriorityQueueConcat = new PriorityQueue<int>(ptrnewlistConcatPQ, 4);
inline NodePriorityQueue<int> listConcatPQ[10] = {NodePriorityQueue<int>(9, 9), NodePriorityQueue<int>(8, 8), NodePriorityQueue<int>(7, 7), NodePriorityQueue<int>(6, 6), NodePriorityQueue<int>(5, 5), NodePriorityQueue<int>(4, 4), NodePriorityQueue<int>(3, 3), NodePriorityQueue<int>(2, 2), NodePriorityQueue<int>(1, 1), NodePriorityQueue<int>(0, 0)};
inline NodePriorityQueue<int>* ptrlistConcatPQ = listConcatPQ;
inline PriorityQueue<int> PriorityQueueConcat = PriorityQueue<int>(ptrlistConcatPQ, 10);

inline NodePriorityQueue<int> listSubSequencePQ[3] = {NodePriorityQueue<int>(4, 4), NodePriorityQueue<int>(3, 3), NodePriorityQueue<int>(2, 2)};
inline NodePriorityQueue<int>* ptrSubSequencePQ = listSubSequencePQ;
inline PriorityQueue<int> PriorityQueueSubSequence = PriorityQueue<int>(ptrSubSequencePQ, 3);

inline NodePriorityQueue<int> listFindSubSequencePQ[3] = {NodePriorityQueue<int>(3, 3), NodePriorityQueue<int>(4, 4), NodePriorityQueue<int>(5, 5)};
inline NodePriorityQueue<int>* ptrFindSubSequencePQ = listFindSubSequencePQ;
inline Sequence<NodePriorityQueue<int>>* PriorityQueueFindSubSequence = new PriorityQueue<int>(ptrFindSubSequencePQ, 3);
inline bool BoolPriorityQueueFindSubSequence = true;

inline NodePriorityQueue<int> listDivide1PQ[3] = {NodePriorityQueue<int>(0, 0), NodePriorityQueue<int>(2, 2), NodePriorityQueue<int>(4, 4)};
inline NodePriorityQueue<int>* ptrDivide1PQ = listDivide1PQ;
inline Sequence<NodePriorityQueue<int>>* PriorityQueueDivide1 = new PriorityQueue<int>(ptrDivide1PQ, 3);
inline NodePriorityQueue<int> listDivide2PQ[3] = {NodePriorityQueue<int>(1, 1), NodePriorityQueue<int>(3, 3), NodePriorityQueue<int>(5, 5)};
inline NodePriorityQueue<int>* ptrDivide2PQ = listDivide2PQ;
inline Sequence<NodePriorityQueue<int>>* PriorityQueueDivide2 = new PriorityQueue<int>(ptrDivide2PQ, 3);
inline std::tuple<Sequence<NodePriorityQueue<int>>*, Sequence<NodePriorityQueue<int>>*> PriorityQueueDivide = std::make_tuple(PriorityQueueDivide1, PriorityQueueDivide2);

///      КОНСТАНТНЫЕ ФУНКЦИИ ДЛЯ ПРОВЕРКИ ФУНКЦИЙ

inline NodePriorityQueue<int> FMapPQ(NodePriorityQueue<int> x){
    x.SetValue(10 * x.GetValue());
    return x;
}

inline bool FWherePQ(NodePriorityQueue<int> x){
    return x.GetValue() % 2 == 0;
}

inline NodePriorityQueue<int> FReducePQ(NodePriorityQueue<int> x, NodePriorityQueue<int> y){
    return NodePriorityQueue<int>(x.GetValue() + y.GetValue(), x.GetPriority() + y.GetPriority());
}

inline bool FDividePQ(NodePriorityQueue<int> x){
    return x.GetValue() % 2 == 0;
}
 
///        ФУНКЦИИ ДЛЯ ПРОВЕРКИ

template <typename T>
bool TestingMapPQ(PriorityQueue<T>* pq, NodePriorityQueue<T> F(NodePriorityQueue<T>), PriorityQueue<T>& testPQ);

template <typename T>
bool TestingWherePQ(PriorityQueue<T>* pq, bool F(NodePriorityQueue<T>), PriorityQueue<T>& testPQ);

template <typename T>
bool TestingReducePQ(PriorityQueue<T>* pq, NodePriorityQueue<T> F(NodePriorityQueue<T>, NodePriorityQueue<T>), NodePriorityQueue<T> neutral, NodePriorityQueue<T> testPQ);

template <typename T>
bool TestingConcatPQ(PriorityQueue<T>* pq, Sequence<NodePriorityQueue<T>>* seq, PriorityQueue<T>& testPQ);

template <typename T>
bool TestingGetSubSequencePQ(PriorityQueue<T>* pq, int startIndex, int endIndex, PriorityQueue<T>& testPQ);

template <typename T>
bool TestingFindSubSequencePQ(PriorityQueue<T>* pq, Sequence<NodePriorityQueue<T>>* subSequence, bool testPQ);

template <typename T>
bool TestingDividePQ(PriorityQueue<T>* pq, bool F(NodePriorityQueue<T>), std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>& testPQ);

template <typename T>
inline void TestingPriorityQueue(PriorityQueue<T>* pq);

