#pragma once
#include <iostream>
#include <tuple>

#include "Stack.h"

///         КОНСТАНТНЫЕ ОТВЕТЫ ДЛЯ ПРОВЕРКИ

inline int listMapSt[6] = {0, 10, 20, 30, 40, 50};
inline int* ptrMapSt = listMapSt;
inline Stack<int> StackMap = Stack<int>(ptrMapSt, 6);

inline int listWhereSt[3] = {0, 2, 4};
inline int* ptrWhereSt = listWhereSt;
inline Stack<int> StackWhere = Stack<int>(ptrWhereSt, 3);

inline int StackReduce = 15;

inline int newlistConcatSt[4] = {6, 7, 8, 9};
inline int* ptrnewlistConcatSt = newlistConcatSt;
inline Sequence<int>* newStackConcat = new Stack<int>(ptrnewlistConcatSt, 4);
inline int listConcatSt[10] = {0, 1, 2,3, 4, 5, 6, 7, 8, 9};
inline int* ptrlistConcatSt = listConcatSt;
inline Stack<int> StackConcat = Stack<int>(ptrlistConcatSt, 10);

inline int listSubSequenceSt[3] = {1, 2, 3};
inline int* ptrSubSequenceSt = listSubSequenceSt;
inline Stack<int> StackSubSequence = Stack<int>(ptrSubSequenceSt, 3);

inline int listFindSubSequenceSt[3] = {3, 4, 5};
inline int* ptrFindSubSequenceSt = listFindSubSequenceSt;
inline Sequence<int>* StackFindSubSequence = new Stack<int>(ptrFindSubSequenceSt, 3);
inline bool BoolStackFindSubSequence = true;

///      КОНСТАНТНЫЕ ФУНКЦИИ ДЛЯ ПРОВЕРКИ ФУНКЦИЙ

inline int FMapSt(int x){
    return 10 * x;
}

inline bool FWhereSt(int x){
    return x % 2 == 0;
}

inline int FReduceSt(int x, int y){
    return x + y;
}
 
///        ФУНКЦИИ ДЛЯ ПРОВЕРКИ

template <typename T>
bool TestingMapSt(Stack<T>* st, T F(T), Stack<T>& testSt);

template <typename T>
bool TestingWhereSt(Stack<T>* st, bool F(T), Stack<T>& testSt);

template <typename T>
bool TestingReduceSt(Stack<T>* st, T F(T, T), T neutral, T testSt);

template <typename T>
bool TestingConcatSt(Stack<T>* st, Sequence<T>* seq, Stack<T>& testSt);

template <typename T>
bool TestingGetSubSequenceSt(Stack<T>* st, int startIndex, int endIndex, Stack<T>& testSt);

template <typename T>
bool TestingFindSubSequenceSt(Stack<T>* st, Sequence<T>* subSequence, bool testSt);

template <typename T>
inline void TestingStack(Stack<T>* st);
