#include <iostream>
#include <sstream>
#include <string>

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::InserT(BinTreeNode<T, D>* root, BinTreeNode<T, D>* node) {
    return Insert(root, node);
}
////////// КОНСТРУКТОРЫ И ДЕСТРУКТОР //////////

template<typename T, typename D>
BinTree<T, D>::BinTree() {
    root = nullptr;
}

template<typename T, typename D>
BinTree<T, D>::BinTree(BinTreeNode<T, D>* r) {
    root = r;
}

template<typename T, typename D>
BinTree<T, D>::BinTree(T value, D key) {
    root = new BinTreeNode(value, key);
}

template<typename T, typename D>
BinTree<T, D>::~BinTree() {
    Clear();
}


////////// СЕТЕРЫ И ГЕТЕРЫ //////////

template<typename T, typename D>
BinTreeNode<T, D>*& BinTree<T, D>::GetRoot() {
    return root;
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::GetRoot() const {
    return root;
}

template<typename T, typename D>
void BinTree<T, D>::SetRoot(BinTreeNode<T, D> *r) {
    root = r;
}

////////// ОСНОВНЫЕ ФУНКЦИИ //////////

template<typename T, typename D>
void BinTree<T, D>::Insert(const D& key, const T& value) {
    BinTreeNode<T, D>* node = new BinTreeNode<T, D>(value, key);
    root = Insert(root, node);
}

template<typename T, typename D>
void BinTree<T, D>::Erase(const D& key) {
    root = Erase(root, key);
}

template<typename T, typename D>
const T* BinTree<T, D>::Find(const D& key) {
    const BinTreeNode<T, D>* node = this->Find(root, key);
    return node ? &(node->GetValue()) : nullptr;
}

template<typename T, typename D>
bool BinTree<T, D>::Contains(const D& key) const {
    return this->Find(root, key) != nullptr;
}

template<typename T, typename D>
void BinTree<T, D>::Print() const {
    PrintNode(root, 0);
}

template<typename T, typename D>
void BinTree<T, D>::Clear() {
    if (root != nullptr) {
        root->GetLeft()->Clear();
        root->GetRight()->Clear();
        delete root;
    }
}

////////// ОСНОВНЫЕ ПРИВАТНЫЕ ФУНКЦИИ //////////

template<typename T, typename D>
void BinTree<T, D>::Split(BinTreeNode<T, D>* ro, const D& key,
                          BinTreeNode<T, D>*& l, BinTreeNode<T, D>*& r) {
    if (ro == nullptr) {
        l = nullptr;
        r = nullptr;
    } else if (key < ro->GetKey()) {
        BinTreeNode<T, D>* tempLeft = nullptr;
        Split(ro->GetLeft(), key, l, tempLeft);
        ro->SetLeft(tempLeft);
        r = ro;
    } else {
        BinTreeNode<T, D>* tempRight = nullptr;
        Split(ro->GetRight(), key, tempRight, r);
        ro->SetRight(tempRight);
        l = ro;
    }
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::Merge(BinTreeNode<T, D>* left, BinTreeNode<T, D>* right) {
    if ((left == nullptr) || (right == nullptr))
        return left ? left : right;

    if (left->GetPriority() > right->GetPriority()) {
        left->SetRight(Merge(left->GetRight(), right));
        return left;
    } else {
        right->SetLeft(Merge(left, right->GetLeft()));
        return right;
    }
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::Insert(BinTreeNode<T, D>* root, BinTreeNode<T, D>* node) {
    if (root == nullptr)
        return node;

    if (node->GetPriority() > root->GetPriority()) {
        BinTreeNode<T, D>* left = nullptr;
        BinTreeNode<T, D>* right = nullptr;
        Split(root, node->GetKey(), left, right);
        node->SetLeft(left);
        node->SetRight(right);
        return node;
    }

    if (node->GetKey() < root->GetKey())
        root->SetLeft(Insert(root->GetLeft(), node));
    else
        root->SetRight(Insert(root->GetRight(), node));

    return root;
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::Erase(BinTreeNode<T, D>* root, const D& key) {
    if (root == nullptr) return nullptr;
    if (root->GetKey() == key) {
        BinTreeNode<T, D>* res = Merge(root->GetLeft(), root->GetRight());
        delete root;
        return res;
    }
    if (key < root->GetKey())
        root->SetLeft(Erase(root->GetLeft(), key));
    else
        root->SetRight(Erase(root->GetRight(), key));
    return root;
}

template<typename T, typename D>
const BinTreeNode<T, D>* BinTree<T, D>::Find(const BinTreeNode<T, D>* root, const D& key) const {
    if (root == nullptr) return nullptr;
    if (key == root->GetKey()) return root;
    if (key < root->GetKey()) return Find(root->GetLeft(), key);
    return Find(root->GetRight(), key);
}

template<typename T, typename D>
void BinTree<T, D>::PrintNode(const BinTreeNode<T, D>* node, int depth) const { // ЛКП
    if (node == nullptr) return;
    PrintNode(node->GetLeft(), depth + 1);
    std::cout << std::string(depth * 4, ' ') << node->GetKey() << " (" << node->GetValue() << ")\n";
    PrintNode(node->GetRight(), depth + 1);
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::MapNode(BinTreeNode<T, D>* node, T F(T)) {
    if (!node) return nullptr;

    T newValue = F(node->GetValue());
    BinTreeNode<T, D>* newNode = new BinTreeNode<T, D>(newValue, node->GetKey());
    newNode->SetPriority(node->GetPriority());

    newNode->SetLeft(MapNode(node->GetLeft(), F));
    newNode->SetRight(MapNode(node->GetRight(), F));

    if (newNode->GetLeft())
        newNode->GetLeft()->SetParent(newNode);
    if (newNode->GetRight())
        newNode->GetRight()->SetParent(newNode);

    return newNode;
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::WhereNode(BinTreeNode<T, D>* node, bool F(T)) {
    if (node == nullptr) return nullptr;

    BinTreeNode<T, D>* left = WhereNode(node->GetLeft(), F);
    BinTreeNode<T, D>* right = WhereNode(node->GetRight(), F);

    if (F(node->GetValue())) {
        BinTreeNode<T, D>* newNode = new BinTreeNode<T, D>(node->GetValue(), node->GetKey());
        newNode->SetPriority(node->GetPriority());
        newNode->SetLeft(left);
        newNode->SetRight(right);
        if (left) left->SetParent(newNode);
        if (right) right->SetParent(newNode);
        return newNode;
    } else {
        return Merge(left, right);
    }
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::CloneSubtree(BinTreeNode<T, D>* node) {
    if (node == nullptr) return nullptr;
    BinTreeNode<T, D> newNode = new BinTreeNode<T, D>(node->GetValue());
    newNode->SetKey(node->GetKey());
    newNode->SetPriority(node->GetPriority());
    newNode->SetLeft(cloneSubtree(node->GetLeft()));
    newNode->SetRight(cloneSubtree(node->GetRight()));
    return newNode;
}

template<typename T, typename D>
void BinTree<T, D>::toStringNode(BinTreeNode<T, D>* node, std::ostringstream& oss, const std::string& order) const {
    if (node == nullptr) {
        oss << "# ";
        return;
    }

    // if (order == "КЛП") {
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    //     toStringNode(node->GetLeft(), oss);
    //     toStringNode(node->GetRight(), oss);
    // } else if (order == "КПЛ") {
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    //     toStringNode(node->GetRight(), oss);
    //     toStringNode(node->GetLeft(), oss);
    // } else if (order == "ЛПК") {
    //     toStringNode(node->GetLeft(), oss);
    //     toStringNode(node->GetRight(), oss);
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    // } else if (order == "ЛКП") {
    //     toStringNode(node->GetLeft(), oss);
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    //     toStringNode(node->GetRight(), oss);
    // } else if (order == "ПЛК") {
    //     toStringNode(node->GetRight(), oss);
    //     toStringNode(node->GetLeft(), oss);
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    // } else if (order == "ПКЛ") {
    //     toStringNode(node->GetRight(), oss);
    //     oss << node->GetKey() << ":" << node->GetValue() << " ";
    //     toStringNode(node->GetLeft(), oss);
    // }
    oss << node->GetKey() << ":" << node->GetValue() << " ";
    toStringNode(node->GetLeft(), oss);
    toStringNode(node->GetRight(), oss);
}

template<typename Type>
Type fromStringValue(const std::string& s) {
    std::istringstream iss(s);
    Type val;
    iss >> val;
    return val;
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::fromStringNode(std::istringstream& iss, const std::string& order) {
    std::string val;
    if (!(iss >> val) || val == "#") return nullptr;
    size_t colonPos = val.find(':');
    if (colonPos == std::string::npos) return nullptr;
    D key = fromStringValue<D>(val.substr(0, colonPos));
    T value = fromStringValue<T>(val.substr(colonPos + 1));
    BinTreeNode<T, D>* node = new BinTreeNode<T, D>(value, key);
    if (order == "КЛП") {
        node->SetLeft(fromStringNode(iss, order));
        node->SetRight(fromStringNode(iss, order));
    } else if (order == "КПЛ") {
        node->SetRight(fromStringNode(iss, order));
        node->SetLeft(fromStringNode(iss, order));
    } else if (order == "ЛПК") {
        node->SetLeft(fromStringNode(iss, order));
        node->SetRight(fromStringNode(iss, order));
    } else if (order == "ЛКП") {
        node->SetLeft(fromStringNode(iss, order));
        node->SetRight(fromStringNode(iss, order));
    } else if (order == "ПЛК") {
        node->SetRight(fromStringNode(iss, order));
        node->SetLeft(fromStringNode(iss, order));
    } else if (order == "ПКЛ") {
        node->SetRight(fromStringNode(iss, order));
        node->SetLeft(fromStringNode(iss, order));
    }
    return node;
}

////////// ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ //////////

template<typename T, typename D>
BinTree<T, D>* BinTree<T, D>::Map(T F(T)) {
    BinTree<T, D>* newTree = new BinTree<T, D>();
    newTree->SetRoot(MapNode(this->root, F));
    return newTree;
}

template<typename T, typename D>
BinTree<T, D>* BinTree<T, D>::Where(bool F(T)) {
    BinTree<T, D>* newTree = new BinTree<T, D>();
    newTree->GetRoot() = WhereNode(this->root, F);
    return newTree;
}

template<typename T, typename D>
BinTree<T, D>* BinTree<T, D>::MergeWith(const BinTree<T, D>& other) {
    BinTree<T, D>* result = new BinTree<T, D>();
    result->GetRoot() = Merge(root, other.GetRoot());
    return result;
}

template<typename T, typename D>
BinTree<T, D>* BinTree<T, D>::ExtractSubtree(const D& key) {
    BinTreeNode<T, D>* node = find(root, key);
    BinTree<T, D>* result = new BinTree<T, D>();
    result->SetRoot(cloneSubtree(node));
    return result;
}

template<typename T, typename D>
bool BinTree<T, D>::ContainsSubtree(BinTreeNode<T, D>* main, BinTreeNode<T, D>* sub) {
    if (main == nullptr) return false;
    if (AreEqual(main, sub))
        return true;
    return ContainsSubtree(main->GetLeft(), sub) ||
           ContainsSubtree(main->GetRight(), sub);
}

template<typename T, typename D>
std::string BinTree<T, D>::toString() const {
    std::ostringstream oss;
    toStringNode(root, oss);
    return oss.str();
}

template<typename T, typename D>
void BinTree<T, D>::fromString(const std::string& data, const std::string& order) {
    std::istringstream iss(data);
    root = fromStringNode(iss, order);
}

template<typename T, typename D>
BinTreeNode<T, D>* BinTree<T, D>::FindNodeByPath(const std::string& path) { // английские буквы из-за перевода в char
    BinTreeNode<T, D>* current = root;
    for (char c : path) {
        if (current == nullptr)
            return nullptr;

        if (c == 'L' || c == 'l') {
            current = current->GetLeft();
        } else if (c == 'R' || c == 'r') {
            current = current->GetRight();
        } else {
            return nullptr;
        }
    }
    return current;
}