#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <functional> // Chứa std::less<T> mặc định.

/* --- CÁC THUẬT TOÁN TÌM KIẾM --- */

// Linear search.
template <typename T>
int linearSearch(T arr[], int left, int right, const T &value) // Range: [left, right].
{
    for (int i = left; i <= right; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

template <typename T>
int linearSearch(T arr[], int sizeArr, const T &value)
{
    return linearSearch(arr, 0, sizeArr - 1, value);
}

// Binary search.
template <typename T, typename Comp = std::less<T>>
int binarySearch(T arr[], int left, int right, const T &value, Comp cmp = Comp()) // Range: [left, right].
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid;
        else if (cmp(arr[mid], value))
            left = mid + 1;
        else // cmp(value, arr[mid])
            right = mid - 1;
    }
    return -1;
}

template <typename T, typename Comp = std::less<T>>
int binarySearch(T arr[], int sizeArr, const T &value, Comp cmp = Comp())
{
    return binarySearch(arr, 0, sizeArr - 1, value, cmp);
}

/* --- CÁC THUẬT TOÁN SẮP XẾP --- */
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

#endif // ALGORITHMS_HPP