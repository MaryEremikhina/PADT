#pragma once
#include "BinTree.h"

template <typename T>
class setTree {
public:
    setTree() = default;
    setTree(const BinTree<T, T>& tree);
    ~setTree();

    const BinTree<T, T>& GetTree() const;

    setTree<T>* Map(T F(T));
    setTree<T>* Where(bool F(T));
    void Insert(const T& value);
    bool Contains(const T& value) const;
    setTree<T> Union(const setTree<T>& other) const;
    setTree<T> Intersection(const setTree<T>& other) const;
    setTree<T> Difference(const setTree<T>& other) const;
    bool IsSubset(const setTree<T>& other) const;
    bool operator==(const setTree<T>& other) const;
    std::string toString() const;
    void fromString(const std::string& data, const std::string& order = "ЛКП");

    void Print() const;
private:
    BinTree<T, T> tree;

    void InsertAll(BinTree<T, T>& result, const BinTreeNode<T, T>* node) const;
    void UnionNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const;
    void IntersectionNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const;
    void DifferenceNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const;
    bool IsSubsetNode(const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const;
};

#include "setTree.tpp"