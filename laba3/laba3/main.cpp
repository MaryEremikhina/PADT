//
//  main.cpp
//  laba3
//
//  Created by Maria Eremikhina on 10.04.2025.
//

#include <iostream>
#include <algorithm>
#include <tuple>

#include "ArraySequence.cpp"
#include "Sequence.cpp"
#include "ListSequence.cpp"
#include "Queue.cpp" // ПРОВЕРКИ НАПИСАНЫ
#include "PriorityQueue.cpp" // ПРОВЕРКИ НАПИСАНЫ
#include "Stack.cpp" // ПРОВЕРКИ НАПИСАНЫ
#include "DeQueue.cpp" // ПРОВЕРКИ НАПИСАНЫ
#include "DeQueueSegment.cpp" // ПРОВЕРКИ НАПИСАНЫ

#include "TestingQueue.cpp"
#include "TestingStack.cpp"
#include "TestingDeQueue.cpp"
#include "TestingPriorityQueue.cpp"
#include "TestingDeQueueSegment.cpp"

int main() {
//    list.Append(7);
//    for (int i = 0; i < list.GetLength(); i++){
//        for (int j = 0; j < list.Get(i).GetLength(); j++){
//            std::cout << list.Get(i).Get(j) << " ";
//        }
//        std::cout << std::endl;
//    }
//    Sequence<NodeDeQueueSegment<int>>* SortedList = list.Sort();
//    for (int i = 0; i < SortedList->GetLength(); i++){
//        for (int j = 0; j < SortedList->Get(i).GetLength(); j++){
//            std::cout << SortedList->Get(i).Get(j) << " ";
//        }
//        std::cout << std::endl;
//    }
    
    
    
    
    
    int listQ[6] = {0, 1, 2, 3, 4, 5};
    int* ptrQ = listQ;
    Queue<int>* queue = new Queue<int>(ptrQ, 6);
    TestingQueue(queue);
    
    int listSt[6] = {0, 1, 2, 3, 4, 5};
    int* ptrSt = listSt;
    Stack<int>* stack = new Stack<int>(ptrSt, 6);
    TestingStack(stack);
    
    int listDQ[6] = {5, 4, 3, 2, 1, 0};
    int* ptrDQ = listDQ;
    DeQueue<int>* dequeue = new DeQueue<int>(ptrDQ, 6);
    TestingDeQueue(dequeue);
    
    NodePriorityQueue<int> listPQ[6] = {NodePriorityQueue<int>(5, 5), NodePriorityQueue<int>(4, 4), NodePriorityQueue<int>(3, 3), NodePriorityQueue<int>(2, 2), NodePriorityQueue<int>(1, 1), NodePriorityQueue<int>(0, 0)};
    NodePriorityQueue<int>* ptrPQ = listPQ;
    PriorityQueue<int>* priorityqueue = new PriorityQueue<int>(ptrPQ, 6);
    TestingPriorityQueue(priorityqueue);
    
    int listDQS1[3] = {0, 2, 4};
    int* ptrDQS1 = listDQS1;
    NodeDeQueueSegment<int> node1 = NodeDeQueueSegment<int>(ptrDQS1, 3);
    int listDQS2[3] = {1, 3, 5};
    int* ptrDQS2 = listDQS2;
    NodeDeQueueSegment<int> node2 = NodeDeQueueSegment<int>(ptrDQS2, 3);
    NodeDeQueueSegment<int> listik[2] = {node1, node2};
    NodeDeQueueSegment<int>* ptrlistik= listik;
    DeQueueSegment<int>* list = new DeQueueSegment<int>(ptrlistik, 2);
    TestingDeQueueSegment(list);
    
    
//    DeQueue<int> d1;
//    d1.Append(11);
//    d1.Append(33);
//    d1.Append(5);
//    d1.Append(-9);
//    d1.Append(-6);
//    d1.Append(14);
//    
//    DeQueue<int>* d2 = new DeQueue<int>();
//    for (int index = 0; index < 5; index++){
//        d2->Append(index);
//    }
//    Sequence<int>* res = d1.Sort();
//    Sequence<int>* res = d1.GetSubsequence(1, 3);
//    bool res = d1.FindSubSequence(d2);
//    std::cout << res << std::endl;
//    Sequence<int>* res = d1.Together(d2);
//    for (int index = 0; index < res->GetLength(); index++){
//        std::cout << res->Get(index) << " ";
//    }
    
    
    
    
    
//    Stack<int> st1;
//    for (int index = 0; index < 11; index++){
//        st1.Append(index);
//    }
//    
//    Stack<int>* st2 = new Stack<int>();
//    for (int index = 6; index < 14; index++){
//        st2->Append(index);
//    }
//    bool res = st1.FindSubSequence(st2);
//    std::cout << res << std::endl;
//    for (int index = 0; index < res->GetLength(); index++){
//        std::cout << res->Get(index) << " ";
//    }
    
    
    
    
    
//    PriorityQueue<int> prq1;
//    for (int index = 0; index < 10; index++){
//        NodePriorityQueue<int> node(index, index);
//        prq1.Append(node);
//    }
//    
//    for (int index = 0; index < prq1.GetLength(); index++){
//        std::cout << prq1[index].GetValue() << " " << prq1[index].GetPriority() << std::endl;
//    }

//    PriorityQueue<std::tuple<int, int>>* prq2 = new PriorityQueue<std::tuple<int, int>>();
//    for (int index = 0; index < 4; index++){
//        std::tuple<int, int> t(index, index);
//        prq2->Append(t);
//    }
//    
//    bool res1 = prq1.FindSubSequence(prq2);
//    std::cout << res1 << std::endl;
//    
//    Sequence<std::tuple<int, int>>* flag = prq1.Together(prq2);
//    for (int index = 0; index < flag->GetLength(); index++){
//        std::cout << std::get<0>(flag->Get(index)) << ", " << std::get<1>(flag->Get(index)) << std::endl;
//    }
//    
//    std::tuple<Sequence<std::tuple<int, int>>*, Sequence<std::tuple<int, int>>*>* t = prq1.Divide(F);
//    for (int index = 0; index < std::get<0>(*t)->GetLength(); index++){
//        std::cout << std::get<0>(std::get<0>(*t)->Get(index)) << ", " << std::get<1>(std::get<0>(*t)->Get(index)) << std::endl;
//    }
//    
//    bool flag = prq1.FindSubSequence(prq2);
//    std::cout << flag << std::endl;
//    Sequence<std::tuple<int, int>>* newprq = prq1.DelEnd();
//    for (int index = 0; index < newprq->GetLength(); index++){
//        std::cout << std::get<0>(newprq->Get(index)) << ", " << std::get<1>(newprq->Get(index)) << std::endl;
//    }

    
    
    
    
    
//    ListSequence<int> ls1;
//    ls1.Append(0);
//    ls1.Append(1);
//    ls1.Append(2);
//    ls1.Append(3);
//    ls1.Append(4);
//    ls1.Append(5);
//    Sequence<int>* res = ls1.GetSubsequence(1, 3);
//    ListSequence<int>* ls2 = new ListSequence<int>();
//    ls2->Append(3);
//    ls2->Append(4);
//    ls2->Append(5);
//    Sequence<int>* res = ls1.Concat(ls2);
//    Sequence<int>* res = ls1.Map(F);
//    int res = ls1.Reduce(F, 0);
//    std::cout << res;
//    Sequence<int>* res = ls1.Where(F);
//    Sequence<Sequence<int>*>* res5 = ls1.FlatMap<int>(F);
//        for (int index = 0; index < res5->GetLength(); index++){
//            std::cout << res5->Get(index)->Get(0) << " " << res5->Get(index)->Get(1) << std::endl;
//        }
//    ListSequence<int> seq1;
//    seq1.Append(1);
//    seq1.Append(2);
//    
//    ListSequence<int> seq2;
//    seq2.Append(10);
//    seq2.Append(20);
//    
//    Sequence<std::tuple<int, int>>* zipped = seq1.Zip(&seq2);
//    
//    std::tuple<Sequence<int>*, Sequence<int>*>* tt = seq1.UnZip(zipped);
//    for (int index = 0; index < std::get<0>(*tt)->GetLength(); index++){
//        std::cout << std::get<0>(*tt)->Get(index) << " ";
//    }

//    for (int i = 0; i < zipped->GetLength(); ++i) {
//        auto [a, b] = zipped->Get(i);
//        std::cout << a << ", " << b << std::endl;
//    }
//    ArraySequence<int> as1;
//    as1.Append(0);
//    as1.Append(1);
//    as1.Append(2);
//    as1.Append(3);
//    as1.Append(4);
//    as1.Append(5);
//    Sequence<int>* res = as1.GetSubsequence(1, 3);
//    Sequence<int>* r = as1.Concat(res);
//    Sequence<int>* res1 = as1.Skip(3);
//    Sequence<int>* res2 = as1.Map(F);
//    int res3 = as1.Reduce(F, 0);
//    std::cout << res3;
//    Sequence<int>* res4 = as1.Where(F);
//    Sequence<Sequence<int>*>* res5 = as1.FlatMap(F);
//    Sequence<Sequence<int>*>* res5 = as1.FlatMap<int>(F);
//    for (int index = 0; index < res5->GetLength(); index++){
//        std::cout << res5->Get(index)->Get(0) << " " << res5->Get(index)->Get(1) << std::endl;
//    }
//    ArraySequence<int> seq1;
//    seq1.Append(1);
//    seq1.Append(2);
//
//    ArraySequence<int> seq2;
//    seq2.Append(10);
//    seq2.Append(20);
//
//    Sequence<std::tuple<int, int>>* zipped = seq1.Zip(&seq2);

//    for (int i = 0; i < zipped->GetLength(); ++i) {
//        auto [a, b] = zipped->Get(i);
//        std::cout << a << ", " << b << std::endl;
//    }
    
//    std::tuple<Sequence<int>*, Sequence<int>*>* tt = seq1.UnZip(zipped);
//    for (int index = 0; index < std::get<0>(*tt)->GetLength(); index++){
//        std::cout << std::get<0>(*tt)->Get(index) << " ";
//    }
}
