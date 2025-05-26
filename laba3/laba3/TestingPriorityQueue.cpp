#include <iostream>
#include <tuple>

#include "TestingPriorityQueue.h"
#include "PriorityQueue.h"

template <typename T>
bool TestingMapPQ(PriorityQueue<T>* pq, NodePriorityQueue<T> F(NodePriorityQueue<T>), PriorityQueue<T>& testPQ){
    Sequence<NodePriorityQueue<T>>* resPQ = pq->Map(F);
    std::cout << "Map: " << testPQ.Compare(resPQ) << "\n";
    return testPQ.Compare(resPQ);
}

template <typename T>
bool TestingWherePQ(PriorityQueue<T>* pq, bool F(NodePriorityQueue<T>), PriorityQueue<T>& testPQ){
    Sequence<NodePriorityQueue<T>>* resPQ = pq->Where(F);
    std::cout << "Where: " << testPQ.Compare(resPQ) << "\n";
    return testPQ.Compare(resPQ);
}

template <typename T>
bool TestingReducePQ(PriorityQueue<T>* pq, NodePriorityQueue<T> F(NodePriorityQueue<T>, NodePriorityQueue<T>), NodePriorityQueue<T> neutral, NodePriorityQueue<T> testPQ){
    NodePriorityQueue<T> resPQ = pq->Reduce(F, neutral);
    std::cout << "Reduce: " << (resPQ == testPQ) << "\n";
    if (resPQ == testPQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingConcatPQ(PriorityQueue<T>* pq, Sequence<NodePriorityQueue<T>>* seq, PriorityQueue<T>& testPQ){
    Sequence<NodePriorityQueue<T>>* resPQ = pq->Concat(seq);
    std::cout << "Concat: " << testPQ.Compare(resPQ) << "\n";
    return testPQ.Compare(resPQ);
}

template <typename T>
bool TestingGetSubSequencePQ(PriorityQueue<T>* pq, int startIndex, int endIndex, PriorityQueue<T>& testPQ){
    Sequence<NodePriorityQueue<T>>* resPQ = pq->GetSubsequence(startIndex, endIndex);
    std::cout << "SubSequence: " << testPQ.Compare(resPQ) << "\n";
    return testPQ.Compare(resPQ);
}

template <typename T>
bool TestingFindSubSequencePQ(PriorityQueue<T>* pq, Sequence<NodePriorityQueue<T>>* subSequence, bool testPQ){
    bool resPQ = pq->FindSubSequence(subSequence);
    std::cout << "FindSubSequence: " << (resPQ == testPQ) << "\n";
    if (resPQ == testPQ){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingDividePQ(PriorityQueue<T>* pq, bool F(NodePriorityQueue<T>), std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>& testPQ){
    std::tuple<Sequence<NodePriorityQueue<T>>*, Sequence<NodePriorityQueue<T>>*>* resPQ = pq->Divide(F);
    if (std::get<0>(*resPQ)->Compare(std::get<0>(testPQ)) && std::get<1>(*resPQ)->Compare(std::get<1>(testPQ))){
        std::cout << "Divide: " << true << "\n";
        return true;
    } else {
        std::cout << "Divide: " << false << "\n";
        return false;
    }
}

template <typename T>
void TestingPriorityQueue(PriorityQueue<T>* pq){
    std::cout << "Initial PriorityQueue: ";
    for (int index = 0; index < pq->GetLength(); index++){
        std::cout << pq->Get(index).GetValue() << ", " << pq->Get(index).GetPriority() << " ";
    }
    std::cout << "\n";
    bool Map = TestingMapPQ(pq, FMapPQ, PriorityQueueMap);
    bool Where = TestingWherePQ(pq, FWherePQ, PriorityQueueWhere);
    bool Reduce = TestingReducePQ(pq, FReducePQ, NodePriorityQueue<int>(0, 0), PriorityQueueReduce);
    bool Concat = TestingConcatPQ(pq, newPriorityQueueConcat, PriorityQueueConcat);
    bool SubSequence = TestingGetSubSequencePQ(pq, 1, 3, PriorityQueueSubSequence);
    bool FindSubSequence = TestingFindSubSequencePQ(pq, PriorityQueueFindSubSequence, BoolPriorityQueueFindSubSequence);
    bool Divide = TestingDividePQ(pq, FDividePQ, PriorityQueueDivide);
    if (Map * Where * Reduce * Concat * SubSequence * FindSubSequence * Divide){
        std::cout << "Everithing is correct with PriorityQueue!!!\n\n";
    }
}
