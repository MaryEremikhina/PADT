////////// КОНСТРУКТОРЫ И ДЕСТРУКТОР //////////

template <typename T>
setTree<T>::setTree(const BinTree<T, T>& t){
    tree = t;
}

template <typename T>
setTree<T>::~setTree(){
    // delete tree;
}

////////// СЕТЕРЫ И ГЕТЕРЫ //////////

template <typename T>
const BinTree<T, T>& setTree<T>::GetTree() const{
    return tree;
}

////////// ОСНОВНЫЕ ПРИВАТНЫЕ ФУНКЦИИ //////////

template <typename T>
void setTree<T>::InsertAll(BinTree<T, T>& result, const BinTreeNode<T, T>* node) const {
    if (node == nullptr) return;
    InsertAll(result, node->GetLeft());
    result.Insert(node->GetKey(), node->GetValue());
    InsertAll(result, node->GetRight());
}

template <typename T>
void setTree<T>::UnionNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const {
    if (node == nullptr) return;
    UnionNode(result, node->GetLeft(), other);
    if (!other.Contains(node->GetKey()))
        result.Insert(node->GetKey(), node->GetValue());
    UnionNode(result, node->GetRight(), other);
}

template <typename T>
void setTree<T>::IntersectionNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const {
    if (node == nullptr) return;
    IntersectionNode(result, node->GetLeft(), other);
    if (other.Contains(node->GetKey()))
        result.Insert(node->GetKey(), node->GetValue());
    IntersectionNode(result, node->GetRight(), other);
}

template <typename T>
void setTree<T>::DifferenceNode(BinTree<T, T>& result, const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const {
    if (node == nullptr) return;
    DifferenceNode(result, node->GetLeft(), other);
    if (!other.Contains(node->GetKey()))
        result.Insert(node->GetKey(), node->GetValue());
    DifferenceNode(result, node->GetRight(), other);
}

template <typename T>
bool setTree<T>::IsSubsetNode(const BinTreeNode<T, T>* node, const BinTree<T, T>& other) const {
    if (node == nullptr) return true;
    if (!other.Contains(node->GetKey()))
        return false;
    return IsSubsetNode(node->GetLeft(), other) && IsSubsetNode(node->GetRight(), other);
}

////////// ОСНОВНЫЕ ФУНКЦИИ //////////

template <typename T>
setTree<T>* setTree<T>::Map(T F(T)){
    BinTree<T, T> NewTree = tree.Map(F);
    return new setTree(NewTree);
}

template <typename T>
setTree<T>* setTree<T>::Where(bool F(T)){
    BinTree<T, T> NewTree = tree.Where(F);
    return new setTree(NewTree);
}

template <typename T>
setTree<T> setTree<T>::Union(const setTree<T>& other) const {
    setTree<T> result;
    InsertAll(result.tree, tree.GetRoot());
    UnionNode(result.tree, other.GetTree().GetRoot(), tree);
    return result;
}

template <typename T>
setTree<T> setTree<T>::Intersection(const setTree<T>& other) const {
    setTree<T> result;
    IntersectionNode(result.tree, other.GetTree().GetRoot(), tree);
    return result;
}

template <typename T>
setTree<T> setTree<T>::Difference(const setTree<T>& other) const {
    setTree<T> result;
    DifferenceNode(result.tree, other.GetTree().GetRoot(), tree);
    return result;
}

template <typename T>
bool setTree<T>::IsSubset(const setTree<T>& other) const {
    return IsSubsetNode(GetTree().GetRoot(), other.tree);
}

template <typename T>
bool setTree<T>::operator==(const setTree<T>& other) const {
    return this->IsSubset(other) && other.IsSubset(*this);
}

template <typename T>
std::string setTree<T>::toString() const {
    return tree.toString();
}

template <typename T>
void setTree<T>::fromString(const std::string& data, const std::string& order){
    return tree.fromString(data, order);
}

template <typename T>
void setTree<T>::Print() const {
    tree.Print();
}

template <typename T>
void setTree<T>::Insert(const T& value){
    tree.Insert(value, value);
}

template <typename T>
bool setTree<T>::Contains(const T& value) const {
    return tree.Contains(value);
}