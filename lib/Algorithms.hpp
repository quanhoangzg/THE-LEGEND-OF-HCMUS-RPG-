#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <functional> // Chứa std::less<T> mặc định

// --- CÁC THUẬT TOÁN SẮP XẾP ---
template <typename T, typename Comp = std::less<T>>
void bubbleSort(T arr[], int n, Comp cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void selectionSort(T arr[], int n, Comp cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void insertionSort(T arr[], int n, Comp cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void heapSort(T arr[], int n, Comp cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void quickSort(T arr[], int lo, int hi, Comp cmp = Comp());

template <typename T, typename Comp = std::less<T>>
void mergeSort(T arr[], int n, Comp cmp = Comp());

// --- CÁC THUẬT TOÁN TÌM KIẾM ---
template <typename T>
int linearSearch(T arr[], int n, const T& key);

template <typename T>
int binarySearch(T arr[], int n, const T& key); // Yêu cầu arr[] đã được sắp xếp

#endif // ALGORITHMS_HPP