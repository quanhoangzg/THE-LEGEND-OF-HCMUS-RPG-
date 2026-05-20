#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
struct Stack {
    T* data = nullptr;
    int topIndex = -1;
    int capacity = 0;
};

// --- Các hàm cốt lõi ---
template <typename T> void push(Stack<T>& s, const T& item);
template <typename T> T pop(Stack<T>& s);
template <typename T> T top(const Stack<T>& s);
template <typename T> bool empty(const Stack<T>& s);
template <typename T> int size(const Stack<T>& s);
template <typename T> void initStack(Stack<T>& s, int cap); // Hàm phụ trợ để cấp phát bộ nhớ
template <typename T> void clear(Stack<T>& s);

#endif // STACK_HPP