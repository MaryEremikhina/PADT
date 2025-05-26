#include <iostream>
#include <tuple>

#include "TestingDeQueue.h"
#include "DeQueue.h"

template <typename T>
bool TestingSortDQ(DeQueue<T>* dq, DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->Sort();
    std::cout << "Sort: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
bool TestingMapDQ(DeQueue<T>* dq, T F(T), DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->Map(F);
    std::cout << "Map: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
bool TestingWhereDQ(DeQueue<T>* dq, bool F(T), DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->Where(F);
    std::cout << "Where: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
bool TestingReduceDQ(DeQueue<T>* dq, T F(T, T), T neutral, T testDQ){
    T resDQ = dq->Reduce(F, neutral);
    std::cout << "Reduce: " << (resDQ == testDQ) << "\n";
    if (resDQ == testDQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingConcatDQ(DeQueue<T>* dq, Sequence<T>* seq, DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->Concat(seq);
    std::cout << "Concat: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
bool TestingGetSubSequenceDQ(DeQueue<T>* dq, int startIndex, int endIndex, DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->GetSubsequence(startIndex, endIndex);
    std::cout << "SubSequence: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
bool TestingFindSubSequenceDQ(DeQueue<T>* dq, Sequence<T>* subSequence, bool testDQ){
    bool resDQ = dq->FindSubSequence(subSequence);
    std::cout << "FindSubSequence: " << (resDQ == testDQ) << "\n";
    if (resDQ == testDQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingTogetherDQ(DeQueue<T>* dq, Sequence<T>* newDeQueue, DeQueue<T>& testDQ){
    Sequence<T>* resDQ = dq->Together(newDeQueue);
    std::cout << "Together: " << testDQ.Compare(resDQ) << "\n";
    return testDQ.Compare(resDQ);
}

template <typename T>
void TestingDeQueue(DeQueue<T>* dq){
    std::cout << "Initial DeQueue: ";
    for (int index = 0; index < dq->GetLength(); index++){
        std::cout << dq->Get(index) << " ";
    }
    std::cout << "\n";
    bool Sort = TestingSortDQ(dq, DeQueueSort);
    bool Map = TestingMapDQ(dq, FMapDQ, DeQueueMap);
    bool Where = TestingWhereDQ(dq, FWhereDQ, DeQueueWhere);
    bool Reduce = TestingReduceDQ(dq, FReduceDQ, 0, DeQueueReduce);
    bool Concat = TestingConcatDQ(dq, newDeQueueConcat, DeQueueConcat);
    bool SubSequence = TestingGetSubSequenceDQ(dq, 1, 3, DeQueueSubSequence);
    bool FindSubSequence = TestingFindSubSequenceDQ(dq, DeQueueFindSubSequence, BoolDeQueueFindSubSequence);
    bool Together = TestingTogetherDQ(dq, newDeQueueTogether, DeQueueTogether);
    if (Sort * Map * Where * Reduce * Concat * SubSequence * FindSubSequence * Together){
        std::cout << "Everithing is correct with DeQueue!!!\n\n";
    }
}
