#pragma once
#include <iostream>
#include <tuple>

#include "DeQueueSegment.h"

///         КОНСТАНТНЫЕ ОТВЕТЫ ДЛЯ ПРОВЕРКИ
    
inline int listSortDQS1[3] = {0, 1, 2};
inline int* ptrSortDQS1 = listSortDQS1;
inline NodeDeQueueSegment<int> Sortnode1 = NodeDeQueueSegment<int>(ptrSortDQS1, 3);
inline int listSortDQS2[3] = {3, 4, 5};
inline int* ptrSortDQS2 = listSortDQS2;
inline NodeDeQueueSegment<int> Sortnode2 = NodeDeQueueSegment<int>(ptrSortDQS2, 3);
inline NodeDeQueueSegment<int> listSortDQS[2] = {Sortnode1, Sortnode2};
inline NodeDeQueueSegment<int>* ptrSortDQS= listSortDQS;
inline DeQueueSegment<int> DeQueueSegmentSort = DeQueueSegment<int>(ptrSortDQS, 2);

inline int listMapDQS1[3] = {0, 20, 40};
inline int* ptrMapDQS1 = listMapDQS1;
inline NodeDeQueueSegment<int> Mapnode1 = NodeDeQueueSegment<int>(ptrMapDQS1, 3);
inline int listMapDQS2[3] = {10, 30, 50};
inline int* ptrMapDQS2 = listMapDQS2;
inline NodeDeQueueSegment<int> Mapnode2 = NodeDeQueueSegment<int>(ptrMapDQS2, 3);
inline NodeDeQueueSegment<int> listMapDQS[2] = {Mapnode1, Mapnode2};
inline NodeDeQueueSegment<int>* ptrMapDQS= listMapDQS;
inline DeQueueSegment<int> DeQueueSegmentMap = DeQueueSegment<int>(ptrMapDQS, 2);

inline int listWhereDQS1[3] = {0, 2, 4};
inline int* ptrWhereDQS1 = listWhereDQS1;
inline NodeDeQueueSegment<int> Wherenode = NodeDeQueueSegment<int>(ptrWhereDQS1, 3);
inline NodeDeQueueSegment<int> listWhereDQS[1] = {Wherenode};
inline NodeDeQueueSegment<int>* ptrWhereDQS = listWhereDQS;
inline DeQueueSegment<int> DeQueueSegmentWhere = DeQueueSegment<int>(ptrWhereDQS, 1);

inline int listReduceDQS[3] = {1, 5, 9};
inline int* ptrReduceDQS = listReduceDQS;
inline NodeDeQueueSegment<int> DeQueueSegmentReduce = NodeDeQueueSegment<int>(ptrReduceDQS, 3);
inline int listNeutralDQS[3] = {0, 0, 0};
inline int* ptrNeutralDQS = listNeutralDQS;
inline NodeDeQueueSegment<int> neutral = NodeDeQueueSegment<int>(ptrNeutralDQS, 3);

inline int newlistConcatDQS1[3] = {6, 7, 8};
inline int* ptrnewConcatDQS1 = newlistConcatDQS1;
inline NodeDeQueueSegment<int> Concatnode = NodeDeQueueSegment<int>(ptrnewConcatDQS1, 3);
inline NodeDeQueueSegment<int> newlistConcatDQS[1] = {Concatnode};
inline NodeDeQueueSegment<int>* ptrnewConcatDQS = newlistConcatDQS;
inline Sequence<NodeDeQueueSegment<int>>* newDeQueueSegmentConcat = new DeQueueSegment<int>(ptrnewConcatDQS, 1);

inline int listConcatDQS1[3] = {0, 2, 4};
inline int* ptrConcatDQS1 = listConcatDQS1;
inline NodeDeQueueSegment<int> Concatnode1 = NodeDeQueueSegment<int>(ptrConcatDQS1, 3);
inline int listConcatDQS2[3] = {1, 3, 5};
inline int* ptrConcatDQS2 = listConcatDQS2;
inline NodeDeQueueSegment<int> Concatnode2 = NodeDeQueueSegment<int>(ptrConcatDQS2, 3);
inline int listConcatDQS3[3] = {6, 7, 8};
inline int* ptrConcatDQS3 = listConcatDQS3;
inline NodeDeQueueSegment<int> Concatnode3 = NodeDeQueueSegment<int>(ptrConcatDQS3, 3);
inline NodeDeQueueSegment<int> listConcatDQS[3] = {Concatnode1, Concatnode2, Concatnode3};
inline NodeDeQueueSegment<int>* ptrConcatDQS= listConcatDQS;
inline DeQueueSegment<int> DeQueueSegmentConcat = DeQueueSegment<int>(ptrConcatDQS, 3);

inline int listSubSequenceDQS1[3] = {1, 3, 5};
inline int* ptrSubSequenceDQS1 = listSubSequenceDQS1;
inline NodeDeQueueSegment<int> SubSequencenode = NodeDeQueueSegment<int>(ptrSubSequenceDQS1, 3);
inline NodeDeQueueSegment<int> listSubSequenceDQS[1] = {SubSequencenode};
inline NodeDeQueueSegment<int>* ptrSubSequenceDQS = listSubSequenceDQS;
inline DeQueueSegment<int> DeQueueSegmentSubSequence = DeQueueSegment<int>(ptrSubSequenceDQS, 1);

inline int listFindSubSequenceDQS1[3] = {1, 3, 5};
inline int* ptrFindSubSequenceDQS1 = listFindSubSequenceDQS1;
inline NodeDeQueueSegment<int> FindSubSequencenode = NodeDeQueueSegment<int>(ptrFindSubSequenceDQS1, 3);
inline NodeDeQueueSegment<int> listFindSubSequenceDQS[1] = {FindSubSequencenode};
inline NodeDeQueueSegment<int>* ptrFindSubSequenceDQS = listFindSubSequenceDQS;
inline Sequence<NodeDeQueueSegment<int>>* DeQueueSegmentFindSubSequence = new DeQueueSegment<int>(ptrFindSubSequenceDQS, 1);
inline bool BoolDeQueueSegmentFindSubSequence = true;

inline int newlistTogetherDQS1[3] = {6, 7, 8};
inline int* ptrnewTogetherDQS1 = newlistTogetherDQS1;
inline NodeDeQueueSegment<int> Togethernode = NodeDeQueueSegment<int>(ptrnewTogetherDQS1, 3);
inline NodeDeQueueSegment<int> newlistTogetherDQS[1] = {Togethernode};
inline NodeDeQueueSegment<int>* ptrnewTogetherDQS = newlistTogetherDQS;
inline Sequence<NodeDeQueueSegment<int>>* newDeQueueSegmentTogether = new DeQueueSegment<int>(ptrnewTogetherDQS, 1);

inline int listTogetherDQS1[3] = {0, 2, 4};
inline int* ptrTogetherDQS1 = listTogetherDQS1;
inline NodeDeQueueSegment<int> Togethernode1 = NodeDeQueueSegment<int>(ptrTogetherDQS1, 3);
inline int listTogetherDQS2[3] = {6, 7, 8};
inline int* ptrTogetherDQS2 = listTogetherDQS2;
inline NodeDeQueueSegment<int> Togethernode2 = NodeDeQueueSegment<int>(ptrTogetherDQS2, 3);
inline int listTogetherDQS3[3] = {1, 3, 5};
inline int* ptrTogetherDQS3 = listTogetherDQS3;
inline NodeDeQueueSegment<int> Togethernode3 = NodeDeQueueSegment<int>(ptrTogetherDQS3, 3);
inline NodeDeQueueSegment<int> listTogetherDQS[3] = {Togethernode1, Togethernode2, Togethernode3};
inline NodeDeQueueSegment<int>* ptrTogetherDQS= listTogetherDQS;
inline DeQueueSegment<int> DeQueueSegmentTogether = DeQueueSegment<int>(ptrTogetherDQS, 3);

///      КОНСТАНТНЫЕ ФУНКЦИИ ДЛЯ ПРОВЕРКИ ФУНКЦИЙ

inline NodeDeQueueSegment<int> FMapDQS(NodeDeQueueSegment<int> x){
    for (int index = 0; index < x.GetLength(); index++){
        x.Set(index, x.Get(index) * 10);
    }
    return x;
}

inline bool FWhereDQS(NodeDeQueueSegment<int> x){
    return x.Get(0) % 2 == 0;
}

inline NodeDeQueueSegment<int> FReduceDQS(NodeDeQueueSegment<int> x, NodeDeQueueSegment<int> y){
    NodeDeQueueSegment<int> node = NodeDeQueueSegment<int>();
    for (int index = 0; index < std::min(x.GetLength(), y.GetLength()); index++){
        node.Append(x.Get(index) + y.Get(index));
    }
    return node;
}
 
///        ФУНКЦИИ ДЛЯ ПРОВЕРКИ

template <typename T>
bool TestingSortDQS(DeQueueSegment<T>* dqs, DeQueueSegment<T>& testDQS);

template <typename T>
bool TestingMapDQS(DeQueueSegment<T>* dqs, NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>), DeQueueSegment<T>& testDQS);

template <typename T>
bool TestingWhereDQS(DeQueueSegment<T>* dqs, bool F(NodeDeQueueSegment<T>), DeQueueSegment<T>& testDQS);

template <typename T>
bool TestingReduceDQS(DeQueueSegment<T>* dqs, NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>, NodeDeQueueSegment<T>), NodeDeQueueSegment<T> neutral, NodeDeQueueSegment<T> testDQS);

template <typename T>
bool TestingConcatDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* seq, DeQueueSegment<T>& testDQS);

template <typename T>
bool TestingGetSubSequenceDQS(DeQueueSegment<T>* dqs, int startIndex, int endIndex, DeQueueSegment<T>& testDQS);

template <typename T>
bool TestingFindSubSequenceDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* subSequence, bool testDQS);

template <typename T>
bool TestingTogetherDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* newDeQueueSegment, DeQueueSegment<T>& testDQS);

template <typename T>
inline void TestingDeQueueSegment(DeQueueSegment<T>* dqs);
