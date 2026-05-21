#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <functional> // Chứa std::less<T> mặc định.

/* --- CÁC THUẬT TOÁN TÌM KIẾM --- */

/* Linear search (Sequential search):
- Vietnamese: Tìm kiếm tuyến tính (Tìm kiếm tuần tự).
- Range: [left, right].
- Time complexity: O(n).
- Space complexity: O(1).
- Return: index of the first occurrence of value in array (if found); otherwise, return -1. */

template <typename T>
int linearSearch(T arr[], int left, int right, const T &value)
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

/* Binary search:
- Vietnamese: Tìm kiếm nhị phân.
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return: index of value in array (if found); otherwise, return -1. */

template <typename T, typename Comp = std::less<T>>
int binarySearch(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
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
int binarySearch(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return binarySearch(arr, 0, sizeArr - 1, value, cmp);
}

/* Binary search first occurrence:
- Vietnamese: Tìm kiếm nhị phân phần tử xuất hiện đầu tiên.
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return: index of the first occurrence of value in array (if found); otherwise, return -1. */

template <typename T, typename Comp = std::less<T>>
int binarySearchFirst(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
{
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
        {
            index = mid;     // lưu vị trí hợp lệ hiện tại.
            right = mid - 1; // tiếp tục tìm bên trái.
        }
        else if (cmp(arr[mid], value))
            left = mid + 1;
        else // cmp(value, arr[mid])
            right = mid - 1;
    }
    return index;
}

template <typename T, typename Comp = std::less<T>>
int binarySearchFirst(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return binarySearchFirst(arr, 0, sizeArr - 1, value, cmp);
}

/* Binary search last occurrence:
- Vietnamese: Tìm kiếm nhị phân phần tử xuất hiện cuối cùng.
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return: index of the last occurrence of value in array (if found); otherwise, return -1. */

template <typename T, typename Comp = std::less<T>>
int binarySearchLast(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
{
    int index = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
        {
            index = mid;    // lưu vị trí hợp lệ hiện tại.
            left = mid + 1; // tiếp tục tìm bên phải.
        }
        else if (cmp(arr[mid], value))
            left = mid + 1;
        else // cmp(value, arr[mid])
            right = mid - 1;
    }
    return index;
}

template <typename T, typename Comp = std::less<T>>
int binarySearchLast(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return binarySearchLast(arr, 0, sizeArr - 1, value, cmp);
}

/* Lower_bound(value):
- Vietnamese: Tìm kiếm nhị phân vị trí đầu tiên KHÔNG đứng trước value,
tức là: "key !< value" <=> "key >= value".
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return:
+ Index of the first element that is NOT less than value according to comparator (if found).
+ Otherwise, return right + 1. */

template <typename T, typename Comp = std::less<T>>
int lowerBound(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
{
    int index = right + 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (!cmp(arr[mid], value))
        {
            index = mid;     // lưu vị trí hợp lệ hiện tại.
            right = mid - 1; // tiếp tục tìm bên trái.
        }
        else // cmp(arr[mid], value)
            left = mid + 1;
    }
    return index;
}

template <typename T, typename Comp = std::less<T>>
int lowerBound(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return lowerBound(arr, 0, sizeArr - 1, value, cmp);
}

/* Upper_bound(value):
- Vietnamese: Tìm kiếm nhị phân vị trí đầu tiên value đứng trước nó,
tức là: "value < key" <=> "key > value".
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return:
+ Index of the first element greater than value according to comparator (if found).
+ Otherwise, return right + 1. */

template <typename T, typename Comp = std::less<T>>
int upperBound(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
{
    int index = right + 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (cmp(value, arr[mid]))
        {
            index = mid;     // lưu vị trí hợp lệ hiện tại.
            right = mid - 1; // tiếp tục tìm bên trái.
        }
        else // !cmp(value, arr[mid])
            left = mid + 1;
    }
    return index;
}

template <typename T, typename Comp = std::less<T>>
int upperBound(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return upperBound(arr, 0, sizeArr - 1, value, cmp);
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