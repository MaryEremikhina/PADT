#pragma once

template <typename T, typename D>
class BinTreeNode {
public:
    BinTreeNode(const T& data, const D& k);
    BinTreeNode(const T data, BinTreeNode<T, D>* p);
    BinTreeNode(const T data, const D k, BinTreeNode<T, D>* r, BinTreeNode<T, D>* l, BinTreeNode<T, D>* p = nullptr);
    ~BinTreeNode() = default;

    const T& GetValue() const;
    const D& GetKey() const;
    const BinTreeNode* GetLeft() const;
    BinTreeNode<T, D>*& GetLeft();
    const BinTreeNode* GetRight() const;
    BinTreeNode<T, D>*& GetRight();
    BinTreeNode* GetParent();
    int GetPriority() const;

    void SetValue(const T& v);
    void SetKey(const D& k);
    void SetLeft(BinTreeNode* node);
    void SetRight(BinTreeNode* node);
    void SetParent(BinTreeNode* node);
    void SetPriority(int p);

    void Swap(BinTreeNode<T, D>* node);
    bool AreEqual(BinTreeNode<T, D>* a, BinTreeNode<T, D>* b);
    void Clear();
private:
    D key; // значение для сравнения (приоритет)
    T value;
    BinTreeNode<T, D>* left; // указатель на левый лист
    BinTreeNode<T, D>* right; // указатель на правый лист
    BinTreeNode<T, D>* parent; // указатель на родителя
    int priority; // приоритет Node
};

#include "BinTreeNode.tpp"