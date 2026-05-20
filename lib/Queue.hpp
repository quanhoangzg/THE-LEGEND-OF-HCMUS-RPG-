#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
struct Queue {
    T* data = nullptr;
    int frontIndex = 0;
    int rearIndex = -1;
    int count = 0;
    int capacity = 0;
};

// --- Các hàm cốt lõi ---
template <typename T> void enqueue(Queue<T>& q, const T& item);
template <typename T> T dequeue(Queue<T>& q);
template <typename T> T front(const Queue<T>& q);
template <typename T> bool empty(const Queue<T>& q);
template <typename T> int size(const Queue<T>& q);
template <typename T> void initQueue(Queue<T>& q, int cap);
template <typename T> void clear(Queue<T>& q);

#endif // QUEUE_HPP