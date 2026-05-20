#ifndef AVL_HPP
#define AVL_HPP

template <typename T>
struct AVLNode {
    T data;
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    int height = 1;
};

template <typename T>
struct AVL {
    AVLNode<T>* root = nullptr;
};

// --- Các hàm thao tác cốt lõi ---
template <typename T> void insert(AVL<T>& tree, const T& value);
template <typename T> void remove(AVL<T>& tree, const T& value);
template <typename T> AVLNode<T>* search(const AVL<T>& tree, const T& value);

// --- Các hàm hỗ trợ tự cân bằng (Thành viên A sẽ tự gọi bên trong hàm insert/remove) ---
template <typename T> int getHeight(AVLNode<T>* node);
template <typename T> int getBalance(AVLNode<T>* node);
template <typename T> AVLNode<T>* rotateRight(AVLNode<T>* y);
template <typename T> AVLNode<T>* rotateLeft(AVLNode<T>* x);

template <typename T> void clear(AVL<T>& tree);

#endif // AVL_HPP