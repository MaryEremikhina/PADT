#include <iostream>
#include <tuple>

#include "TestingStack.h"
#include "Stack.h"

template <typename T>
bool TestingMapSt(Stack<T>* st, T F(T), Stack<T>& testSt){
    Sequence<T>* resSt = st->Map(F);
    std::cout << "Map: " << testSt.Compare(resSt) << "\n";
    return testSt.Compare(resSt);
}

template <typename T>
bool TestingWhereSt(Stack<T>* st, bool F(T), Stack<T>& testSt){
    Sequence<T>* resSt = st->Where(F);
    std::cout << "Where: " << testSt.Compare(resSt) << "\n";
    return testSt.Compare(resSt);
}

template <typename T>
bool TestingReduceSt(Stack<T>* st, T F(T, T), T neutral, T testSt){
    T resSt = st->Reduce(F, neutral);
    std::cout << "Reduce: " << (resSt == testSt) << "\n";
    if (resSt == testSt){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingConcatSt(Stack<T>* st, Sequence<T>* seq, Stack<T>& testSt){
    Sequence<T>* resSt = st->Concat(seq);
    std::cout << "Concat: " << testSt.Compare(resSt) << "\n";
    return testSt.Compare(resSt);
}

template <typename T>
bool TestingGetSubSequenceSt(Stack<T>* st, int startIndex, int endIndex, Stack<T>& testSt){
    Sequence<T>* resSt = st->GetSubsequence(startIndex, endIndex);
    std::cout << "SubSequence: " << testSt.Compare(resSt) << "\n";
    return testSt.Compare(resSt);
}

template <typename T>
bool TestingFindSubSequenceSt(Stack<T>* st, Sequence<T>* subSequence, bool testSt){
    bool resSt = st->FindSubSequence(subSequence);
    std::cout << "FindSubSequence: " << (resSt == testSt) << "\n";
    if (resSt == testSt){
        return true;
    } else {
        return false;
    }
}

template <typename T>
void TestingStack(Stack<T>* st){
    std::cout << "Initial Stack: ";
    for (int index = 0; index < st->GetLength(); index++){
        std::cout << st->Get(index) << " ";
    }
    std::cout << "\n";
    bool Map = TestingMapSt(st, FMapSt, StackMap);
    bool Where = TestingWhereSt(st, FWhereSt, StackWhere);
    bool Reduce = TestingReduceSt(st, FReduceSt, 0, StackReduce);
    bool Concat = TestingConcatSt(st, newStackConcat, StackConcat);
    bool SubSequence = TestingGetSubSequenceSt(st, 1, 3, StackSubSequence);
    bool FindSubSequence = TestingFindSubSequenceSt(st, StackFindSubSequence, BoolStackFindSubSequence);
    if (Map * Where * Reduce * Concat * SubSequence * FindSubSequence){
        std::cout << "Everithing is correct with Stack!!!\n\n";
    }
}
