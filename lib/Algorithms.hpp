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

/* Count_occurrence(value):
- Vietnamese: Đếm số lần xuất hiện của value trong mảng.
- Condition: array must be sorted according to comparator
(mảng được sắp xếp, hay mảng là một dãy đơn điệu theo comparator).
- Range: [left, right].
- Time complexity: O(log n).
- Space complexity: O(1).
- Return:
+ Number of occurrences of value in array.
+ If value does not exist in array, return 0. */

template <typename T, typename Comp = std::less<T>>
int countOccurrence(T arr[], int left, int right, const T &value, const Comp &cmp = Comp())
{
    int first = binarySearchFirst(arr, left, right, value, cmp);
    if (first == -1)
        return 0;
    int last = binarySearchLast(arr, left, right, value, cmp);
    return last - first + 1;
}

template <typename T, typename Comp = std::less<T>>
int countOccurrence(T arr[], int sizeArr, const T &value, const Comp &cmp = Comp())
{
    return countOccurrence(arr, 0, sizeArr - 1, value, cmp);
}

/* --- CÁC THUẬT TOÁN SẮP XẾP --- */

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

/* Selection sort:
- Vietnamese: Sắp xếp chọn.
- Range: [left, right].
- Time complexity: O(n^2) (best case), O(n^2) (worst case).
- Space complexity: O(1) (worst case).
- Stability: No.
- In-place: Yes. */

template <typename T, typename Comp = std::less<T>>
void selectionSort(T arr[], int left, int right, const Comp &cmp = Comp())
{
    for (int i = left; i <= right; i++)
    {
        int selected = i;
        for (int j = i + 1; j <= right; j++)
        {
            if (cmp(arr[j], arr[selected]))
                selected = j;
        }
        if (selected != i)
            mySwap(arr[i], arr[selected]);
    }
}

template <typename T, typename Comp = std::less<T>>
void selectionSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    selectionSort(arr, 0, sizeArr - 1, cmp);
}

/* Insertion sort:
- Vietnamese: Sắp xếp chèn.
- Range: [left, right].
- Time complexity: O(n) (best case), O(n^2) (worst case).
- Space complexity: O(1) (worst case).
- Stability: Yes.
- In-place: Yes. */

template <typename T, typename Comp = std::less<T>>
void insertionSort(T arr[], int left, int right, const Comp &cmp = Comp())
{
    for (int i = left + 1; i <= right; i++)
    {
        T curr = arr[i];
        int j = i - 1;
        while (j >= left && cmp(curr, arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

template <typename T, typename Comp = std::less<T>>
void insertionSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    insertionSort(arr, 0, sizeArr - 1, cmp);
}

/* Bubble sort:
- Vietnamese: Sắp xếp nổi bọt.
- Range: [left, right].
- Time complexity: O(n) (best case), O(n^2) (worst case).
- Space complexity: O(1) (worst case).
- Stability: Yes.
- In-place: Yes. */

template <typename T, typename Comp = std::less<T>>
void bubbleSort(T arr[], int left, int right, const Comp &cmp = Comp())
{
    int size = right - left + 1;
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = left; j < right - i; j++)
        {
            if (cmp(arr[j + 1], arr[j]))
            {
                mySwap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

template <typename T, typename Comp = std::less<T>>
void bubbleSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    bubbleSort(arr, 0, sizeArr - 1, cmp);
}

#endif // ALGORITHMS_HPP