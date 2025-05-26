#include <iostream>
#include "setTree.h"

int map_func(int x) {
    return x * 2;
};

bool where_func(int x) {
    return x > 10;
}

int main() {
    std::cout << "Choose what you want to create:\n\t1. BinaryTree TREAP\n\t2. Set on TREAP\n";
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "Size of TREAP: ";
        BinTree<int, int> tree = BinTree<int, int>();
        int size;
        std::cin >> size;
        std::cout << "List of numbers: ";
        for (int i = 0; i < size; i++) {
            int tmp;
            std::cin >> tmp;
            tree.Insert(tmp, tmp);
        }
        tree.Print();
        std::cout << "What number do you want to Insert: ";
        int insert;
        std::cin >> insert;
        tree.Insert(insert, insert);
        tree.Print();
        std::cout << "What number do you want to Find: ";
        int find;
        std::cin >> find;
        std::cout << tree.Contains(find) << std::endl;
        std::cout << "What number do you want to Delete: ";
        int del;
        std::cin >> del;
        tree.Erase(del);
        tree.Print();
        std::cout << "What TREAP will be if we * 2 every vertex:\n";
        BinTree<int,int>* mappedTree = tree.Map(map_func);
        mappedTree->Print();
        std::cout << "What TREAP will be if we leave only > 10:\n";
        BinTree<int,int>* filteredTree = tree.Where(where_func);
        filteredTree->Print();

        std::string stringTree = tree.toString();
        std::cout << "TREAP as String:\n" << stringTree << "\n";
        BinTree<int,int> loadedTree;
        loadedTree.fromString(stringTree, "ЛКП");
        std::cout << "TREAP back from String:\n";
        loadedTree.Print();
    } else {
        std::cout << "Size of Set1: ";
        setTree<int> set1 = setTree<int>();
        int size1;
        std::cin >> size1;
        std::cout << "List of numbers: ";
        for (int i = 0; i < size1; i++) {
            int tmp1;
            std::cin >> tmp1;
            set1.Insert(tmp1);
        }
        std::cout << "Set1: ";
        set1.Print();

        std::cout << "Size of Set2: ";
        setTree<int> set2 = setTree<int>();
        int size2;
        std::cin >> size2;
        std::cout << "List of numbers: ";
        for (int i = 0; i < size2; i++) {
            int tmp2;
            std::cin >> tmp2;
            set2.Insert(tmp2);
        }
        std::cout << "Set2: ";
        set2.Print();

        setTree<int> set3 = set1.Union(set2);
        std::cout << "Set1 || Set2: ";
        set3.Print();
        setTree<int> set4 = set1.Intersection(set2);
        std::cout << "Set1 && Set2: ";
        set4.Print();
        std::cout << "Set1 == Set2: ";
        std::cout << (set1 == set2) << std::endl;
        std::cout << "Set4 is subSet of Set1: ";
        std::cout << set4.IsSubset(set1) << std::endl;

        setTree<int> set5 = set1.Difference(set2);
        std::cout << "Set1 <> Set2: ";
        set5.Print();
    }
    return 0;

    // setTree<int> setA;
    // setTree<int> setB;
    // setTree<int> setC;
    //
    // // Вставляем элементы в setA и setB одинаковые
    // setA.Insert(1);
    // setA.Insert(2);
    // setA.Insert(3);
    //
    // setB.Insert(3);
    // setB.Insert(1);
    // setB.Insert(2);
    //
    // // setC отличается
    // setC.Insert(1);
    // setC.Insert(2);
    // setC.Insert(4);
    //
    //
    // // Проверяем вхождение
    // assert(setA.Contains(1) == true);
    // assert(setA.Contains(4) == false);
    //
    // // Проверяем равенство
    // assert((setA==setB) == true);  // одинаковые множества
    // assert((setA == setC) == false); // разные множества
    // //
    // // // Проверка равенства множества с самим собой
    // assert((setA == setA) == true);
    // //
    // std::cout << "Все тесты пройдены успешно!\n";


    // BinTree<int, int> tree;
    // tree.Insert(10, 100);
    // tree.Insert(5, 50);
    // tree.Insert(20, 200);
    // tree.Insert(15, 150);
    // tree.Insert(25, 250);
    // std::cout << "Дерево после вставок (обход):\n";
    // tree.Print();
    //
    // int key_to_find = 15;
    // const int* found = tree.Find(key_to_find);
    // if (found != nullptr) {
    //     std::cout << "Найден узел с ключом " << key_to_find << " и значением " << found << "\n";
    // } else {
    //     std::cout << "Узел с ключом " << key_to_find << " не найден\n";
    // }
    // std::cout << "Удаляем узел с ключом 10\n";
    // tree.Erase(10);
    // tree.Print();
    //
    // // Проверяем функцию map
    // BinTree<int,int>* mappedTree = tree.Map(map_func);
    // std::cout << "Дерево после map (значения удвоены):\n";
    // mappedTree->Print();
    //
    // // Проверяем функцию where (фильтр по значению)
    // BinTree<int,int>* filteredTree = tree.Where(where_func);
    // std::cout << "Дерево после where (значения > 100):\n";
    // filteredTree->Print();
    //
    // // Проверка сохранения и загрузки из строки
    // std::string stringTree = tree.toString();
    // std::cout << "Дерево в строчку:\n" << stringTree << "\n";
    //
    // BinTree<int,int> loadedTree;
    // loadedTree.fromString(stringTree, "ЛКП");
    // std::cout << "Дерево после десериализации:\n";
    // loadedTree.Print();
    //
    // // Поиск узла по пути
    // std::string path = "RL"; // например, корень->право->лево
    // BinTreeNode<int,int>* nodeByPath = tree.FindNodeByPath(path);
    // if (nodeByPath) {
    //     std::cout << "Узел по пути \"" << path << "\": ключ = " << nodeByPath->GetKey() << "\n";
    // } else {
    //     std::cout << "Узел по пути \"" << path << "\" не найден\n";
    // }
}