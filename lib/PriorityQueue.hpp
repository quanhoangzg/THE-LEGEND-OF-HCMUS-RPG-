#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

template <typename T>
struct PriorityQueue {
    T* heap = nullptr;
    int count = 0;
    int capacity = 0;
};

// --- Các hàm cốt lõi ---
template <typename T> void insert(PriorityQueue<T>& pq, const T& item);
template <typename T> T extract(PriorityQueue<T>& pq);
template <typename T> T peek(const PriorityQueue<T>& pq);
template <typename T> bool empty(const PriorityQueue<T>& pq);
template <typename T> int size(const PriorityQueue<T>& pq);
template <typename T> void initPQ(PriorityQueue<T>& pq, int cap);
template <typename T> void clear(PriorityQueue<T>& pq);

#endif // PRIORITY_QUEUE_HPP