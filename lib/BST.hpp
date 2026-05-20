#ifndef BST_HPP
#define BST_HPP

template <typename T>
struct BSTNode {
    T data;
    BSTNode* left = nullptr;
    BSTNode* right = nullptr;
};

template <typename T>
struct BST {
    BSTNode<T>* root = nullptr;
};

// --- Các hàm thao tác ---
template <typename T> void insert(BST<T>& tree, const T& value);
template <typename T> void remove(BST<T>& tree, const T& value);
template <typename T> BSTNode<T>* search(const BST<T>& tree, const T& value);

// --- Các hàm duyệt cây ---
template <typename T> void preOrder(BSTNode<T>* node);
template <typename T> void inOrder(BSTNode<T>* node);
template <typename T> void postOrder(BSTNode<T>* node);

template <typename T> void clear(BST<T>& tree);

#endif // BST_HPP