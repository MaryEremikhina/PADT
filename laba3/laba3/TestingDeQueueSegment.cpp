#include <iostream>
#include <tuple>

#include "TestingDeQueueSegment.h"
#include "DeQueueSegment.h"

template <typename T>
bool TestingSortDQS(DeQueueSegment<T>* dqs, DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->Sort();
    std::cout << "Sort: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
bool TestingMapDQS(DeQueueSegment<T>* dqs, NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>), DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->Map(F);
    std::cout << "Map: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
bool TestingWhereDQS(DeQueueSegment<T>* dqs, bool F(NodeDeQueueSegment<T>), DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->Where(F);
    std::cout << "Where: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
bool TestingReduceDQS(DeQueueSegment<T>* dqs, NodeDeQueueSegment<T> F(NodeDeQueueSegment<T>, NodeDeQueueSegment<T>), NodeDeQueueSegment<T> neutral, NodeDeQueueSegment<T> testDQS){
    NodeDeQueueSegment<T> resDQS = dqs->Reduce(F, neutral);
    std::cout << "Reduce: " << (resDQS == testDQS) << "\n";
    if (resDQS == testDQS){
        return true;
    } else {
        return false;
    }
    return true;
}

template <typename T>
bool TestingConcatDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* seq, DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->Concat(seq);
    std::cout << "Concat: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
bool TestingGetSubSequenceDQS(DeQueueSegment<T>* dqs, int startIndex, int endIndex, DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->GetSubsequence(startIndex, endIndex);
    std::cout << "SubSequence: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
bool TestingFindSubSequenceDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* subSequence, bool testDQS){
    bool resDQS = dqs->FindSubSequence(subSequence);
    std::cout << "FindSubSequence: " << (resDQS == testDQS) << "\n";
    if (resDQS == testDQS){
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool TestingTogetherDQS(DeQueueSegment<T>* dqs, Sequence<NodeDeQueueSegment<T>>* newDeQueueSegment, DeQueueSegment<T>& testDQS){
    Sequence<NodeDeQueueSegment<T>>* resDQS = dqs->Together(newDeQueueSegment);
    std::cout << "Together: " << testDQS.Compare(resDQS) << "\n";
    return testDQS.Compare(resDQS);
}

template <typename T>
inline void TestingDeQueueSegment(DeQueueSegment<T>* dqs){
    std::cout << "Initial DeQueueSegment: ";
    for (int i = 0; i < dqs->GetLength(); i++){
        for (int j = 0; j < dqs->Get(i).GetLength(); j++){
            std::cout << dqs->Get(i).Get(j) << ", ";
        }
        std::cout << std::endl;
    }
    bool Sort = TestingSortDQS(dqs, DeQueueSegmentSort);
    bool Map = TestingMapDQS(dqs, FMapDQS, DeQueueSegmentMap);
    bool Where = TestingWhereDQS(dqs, FWhereDQS, DeQueueSegmentWhere);
    bool Reduce = TestingReduceDQS(dqs, FReduceDQS, neutral, DeQueueSegmentReduce);
    bool Concat = TestingConcatDQS(dqs, newDeQueueSegmentConcat, DeQueueSegmentConcat);
    bool SubSequence = TestingGetSubSequenceDQS(dqs, 1, 1, DeQueueSegmentSubSequence);
    bool FindSubSequence = TestingFindSubSequenceDQS(dqs, DeQueueSegmentFindSubSequence, BoolDeQueueSegmentFindSubSequence);
    bool Together = TestingTogetherDQS(dqs, newDeQueueSegmentTogether, DeQueueSegmentTogether);
    if (Sort * Map * Where * Reduce * Concat * SubSequence * FindSubSequence * Together){
        std::cout << "Everithing is correct with DeQueueSegment!!!\n\n";
    }
}
