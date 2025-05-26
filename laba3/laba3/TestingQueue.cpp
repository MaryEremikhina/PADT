#include <iostream>
#include <tuple>

#include "TestingQueue.h"
#include "Queue.h"

template <typename T>
bool TestingMapQ(Queue<T>* q, T F(T), Queue<T>& testQ){
    Sequence<T>* resQ = q->Map(F);
    std::cout << "Map: " << testQ.Compare(resQ) << "\n";
    return testQ.Compare(resQ);
}

template <typename T>
bool TestingWhereQ(Queue<T>* q, bool F(T), Queue<T>& testQ){
    Sequence<T>* resQ = q->Where(F);
    std::cout << "Where: " << testQ.Compare(resQ) << "\n";
    return testQ.Compare(resQ);
}

template <typename T>
bool TestingReduceQ(Queue<T>* q, T F(T, T), T neutral, T testQ){
    T resQ = q->Reduce(F, neutral);
    std::cout << "Reduce: " << (resQ == testQ) << "\n";
    if (resQ == testQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingConcatQ(Queue<T>* q, Sequence<T>* seq, Queue<T>& testQ){
    Sequence<T>* resQ = q->Concat(seq);
    std::cout << "Concat: " << testQ.Compare(resQ) << "\n";
    return testQ.Compare(resQ);
}

template <typename T>
bool TestingGetSubSequenceQ(Queue<T>* q, int startIndex, int endIndex, Queue<T>& testQ){
    Sequence<T>* resQ = q->GetSubsequence(startIndex, endIndex);
    std::cout << "SubSequence: " << testQ.Compare(resQ) << "\n";
    return testQ.Compare(resQ);
}

template <typename T>
bool TestingFindSubSequenceQ(Queue<T>* q, Sequence<T>* subSequence, bool testQ){
    bool resQ = q->FindSubSequence(subSequence);
    std::cout << "FindSubSequence: " << (resQ == testQ) << "\n";
    if (resQ == testQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingTogetherQ(Queue<T>* q, Sequence<T>* newQueue, Queue<T>& testQ){
    Sequence<T>* resQ = q->Together(newQueue);
    std::cout << "Together: " << testQ.Compare(resQ) << "\n";
    return testQ.Compare(resQ);
}

template <typename T>
bool TestingDivideQ(Queue<T>* q, bool F(T), std::tuple<Sequence<T>*, Sequence<T>*>& testQ){
    std::tuple<Sequence<T>*, Sequence<T>*>* resQ = q->Divide(F);
    if (std::get<0>(*resQ)->Compare(std::get<0>(testQ)) && std::get<1>(*resQ)->Compare(std::get<1>(testQ))){
        std::cout << "Divide: " << true << "\n";
        return true;
    } else {
        std::cout << "Divide: " << false << "\n";
        return false;
    }
}

template <typename T>
void TestingQueue(Queue<T>* q){
    std::cout << "Initial Queue: ";
    for (int index = 0; index < q->GetLength(); index++){
        std::cout << q->Get(index) << " ";
    }
    std::cout << "\n";
    bool Map = TestingMapQ(q, FMapQ, QueueMap);
    bool Where = TestingWhereQ(q, FWhereQ, QueueWhere);
    bool Reduce = TestingReduceQ(q, FReduceQ, 0, QueueReduce);
    bool Concat = TestingConcatQ(q, newQueueConcat, QueueConcat);
    bool SubSequence = TestingGetSubSequenceQ(q, 1, 3, QueueSubSequence);
    bool FindSubSequence = TestingFindSubSequenceQ(q, QueueFindSubSequence, BoolQueueFindSubSequence);
    bool Together = TestingTogetherQ(q, newQueueTogether, QueueTogether);
    bool Divide = TestingDivideQ(q, FDivideQ, QueueDivide);
    if (Map * Where * Reduce * Concat * SubSequence * FindSubSequence * Together * Divide){
        std::cout << "Everithing is correct with Queue!!!\n\n";
    }
}
