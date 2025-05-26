#pragma once
#include "BinTreeNode.h"
#include <sstream>

template <typename T, typename D>
class BinTree {
public:
    BinTree();
    BinTree(BinTreeNode<T, D> *r);
    BinTree(T value, D key);
    ~BinTree();

    void SetRoot(BinTreeNode<T, D>* r);
    BinTreeNode<T, D>*& GetRoot();
    BinTreeNode<T, D>* GetRoot() const;

    void Insert(const D& key, const T& value);
    BinTreeNode<T, D>* InserT(BinTreeNode<T, D>* root, BinTreeNode<T, D>* node);
    const T* Find(const D& key);
    bool Contains(const D& key) const;
    void Erase(const D& key);
    void Print() const;
    void Clear();

    BinTree<T, D>* Map(T F(T));
    BinTree<T, D>* Where(bool F(T));
    BinTree<T, D>* MergeWith(const BinTree<T, D>& other);
    BinTree<T, D>* ExtractSubtree(const D& key);
    bool ContainsSubtree(BinTreeNode<T, D>* main, BinTreeNode<T, D>* sub);
    std::string toString() const;
    void fromString(const std::string& data, const std::string& order = "ЛКП");
    BinTreeNode<T, D>* FindNodeByPath(const std::string& path);
private:
    BinTreeNode<T, D>* root;

    void Split(BinTreeNode<T, D>* ro, const D& key, BinTreeNode<T, D>*& r, BinTreeNode<T, D>*& l);
    BinTreeNode<T, D>* Merge(BinTreeNode<T, D>* l, BinTreeNode<T, D>* r);
    BinTreeNode<T, D>* Insert(BinTreeNode<T, D>* root, BinTreeNode<T, D>* node);
    BinTreeNode<T, D>* Erase(BinTreeNode<T, D>* root, const D& key);
    const BinTreeNode<T, D>* Find(const BinTreeNode<T, D>* root, const D& key) const;
    void PrintNode(const BinTreeNode<T, D>* node, int depth) const;

    BinTreeNode<T, D>* MapNode(BinTreeNode<T, D>* node, T F(T));
    BinTreeNode<T, D>* WhereNode(BinTreeNode<T, D>* node, bool F(T));
    BinTreeNode<T, D>* CloneSubtree(BinTreeNode<T, D>* node);
    void toStringNode(BinTreeNode<T, D>* node, std::ostringstream& oss, const std::string& order = "ЛКП") const;
    BinTreeNode<T, D>* fromStringNode(std::istringstream& iss, const std::string& order);
};

#include "BinTree.tpp"