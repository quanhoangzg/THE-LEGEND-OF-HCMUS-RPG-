#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct LinkedList {
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int count = 0;
};

// --- Các hàm thao tác ---
template <typename T> void insertFront(LinkedList<T>& list, const T& value);
template <typename T> void insertBack(LinkedList<T>& list, const T& value);
template <typename T> void insertAt(LinkedList<T>& list, int index, const T& value);
template <typename T> void removeValue(LinkedList<T>& list, const T& value);
template <typename T> void removeAt(LinkedList<T>& list, int index);
template <typename T> Node<T>* find(LinkedList<T>& list, const T& value);
template <typename T> int size(const LinkedList<T>& list);
template <typename T> void clear(LinkedList<T>& list);

// Hàm duyệt in danh sách (từ đầu hoặc cuối, hỗ trợ bằng đệ quy nếu cần)
template <typename T> void traverse(const LinkedList<T>& list);

#endif // LINKED_LIST_HPP