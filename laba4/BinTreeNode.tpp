#include <random>

std::mt19937_64 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

////////// КОНСТРУКТОРЫ //////////

template<typename T, typename D>
BinTreeNode<T, D>::BinTreeNode(const T& data, const D& k) {
    key = k;
    value = data;
    priority = rnd();
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template<typename T, typename D>
BinTreeNode<T, D>::BinTreeNode(const T data, BinTreeNode<T, D>* p) {
    key = data;
    value = data;
    priority = rnd();
    left = nullptr;
    right = nullptr;
    parent = p;
}

template<typename T, typename D>
BinTreeNode<T, D>::BinTreeNode(const T data, const D k,
    BinTreeNode<T, D> *r, BinTreeNode<T, D> *l, BinTreeNode<T, D> *p) {
    key = k;
    value = data;
    priority = rnd();
    left = l;
    right = r;
    parent = p;
}

////////// СЕТЕРЫ И ГЕТЕРЫ //////////

template<typename T, typename D>
const T& BinTreeNode<T, D>::GetValue() const {
    return value;
}

template<typename T, typename D>
const D& BinTreeNode<T, D>::GetKey() const {
    return key;
}

template<typename T, typename D>
const BinTreeNode<T, D>* BinTreeNode<T, D>::GetLeft() const {
    return left;
}

template<typename T, typename D>
BinTreeNode<T, D>*& BinTreeNode<T, D>::GetLeft() {
    return left;
}

template<typename T, typename D>
const BinTreeNode<T, D>* BinTreeNode<T, D>::GetRight() const {
    return right;
}

template<typename T, typename D>
BinTreeNode<T, D>*& BinTreeNode<T, D>::GetRight() {
    return right;
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTreeNode<T, D>::GetParent() {
    return parent;
}

template<typename T, typename D>
int BinTreeNode<T, D>::GetPriority() const {
    return priority;
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetValue(const T& v) {
    value = v;
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetKey(const D& k) {
    key = k;
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetLeft(BinTreeNode* node) {
    left = node;
    if (node) node->SetParent(this);
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetRight(BinTreeNode* node) {
    right = node;
    if (node) node->SetParent(this);
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetParent(BinTreeNode* node) {
    parent = node;
}

template<typename T, typename D>
void BinTreeNode<T, D>::SetPriority(int pr) {
    priority = pr;
}

////////// ОСНОВНЫЕ ФУНКЦИИ //////////

template<typename T, typename D>
void BinTreeNode<T, D>::Swap(BinTreeNode<T, D> *node) {
    std::swap(key, node->GetKey());
    std::swap(value, node->GetValue());
    std::swap(priority, node->GetPriority());
}

template<typename T, typename D>
void BinTreeNode<T, D>::Clear() {
    if (left != nullptr) {
        left->Clear();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->Clear();
        delete right;
        right = nullptr;
    }
}

template<typename T, typename D>
bool BinTreeNode<T, D>::AreEqual(BinTreeNode<T, D>* a, BinTreeNode<T, D>* b) {
    if ((a == nullptr) && (b == nullptr)) return true;
    if ((a == nullptr) || (b == nullptr)) return false;

    if (a->GetKey() != b->GetKey() ||
        a->GetValue() != b->GetValue() ||
        a->GetPriority() != b->GetPriority()) return false;

    return AreEqual(a->GetLeft(), b->GetLeft()) &&
           AreEqual(a->GetRight(), b->GetRight());
}