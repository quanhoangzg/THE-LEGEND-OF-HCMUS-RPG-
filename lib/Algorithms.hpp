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

/* Quick sort:
- Vietnamese: Sắp xếp nhanh.
- Range: [left, right].
- Time complexity: O(n log n) (best case), O(n^2) (worst case).
- Space complexity: O(log n) (best case), O(n) (worst case).
- Stability: No.
- In-place: Yes. */

template <typename T, typename Comp = std::less<T>>
int partition(T arr[], int left, int right, const Comp &cmp = Comp())
{
    int i = left - 1, j = right + 1;
    T pivot = arr[left];
    while (true)
    {
        do
        {
            i++;
        } while (cmp(arr[i], pivot));
        do
        {
            j--;
        } while (cmp(pivot, arr[j]));
        if (i >= j)
            break;
        mySwap(arr[i], arr[j]);
    }
    return j; // quan trọng.
}

template <typename T, typename Comp = std::less<T>>
void quickSort(T arr[], int left, int right, const Comp &cmp = Comp())
{
    if (left < right)
    {
        int pivot = partition(arr, left, right, cmp);
        quickSort(arr, left, pivot, cmp);      // chú ý.
        quickSort(arr, pivot + 1, right, cmp); // chú ý.
    }
}

template <typename T, typename Comp = std::less<T>>
void quickSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    quickSort(arr, 0, sizeArr - 1, cmp);
}

/* Heap sort:
- Vietnamese: Sắp xếp đống.
- Range: [0, sizeArr - 1].
- Time complexity: O(n log n) (best case), O(n log n) (worst case).
- Space complexity: O(1) (worst case).
- Stability: No.
- In-place: Yes. */

template <typename T, typename Comp = std::less<T>>
void heapify(T arr[], int sizeArr, int node, const Comp &cmp = Comp())
{
    while (2 * node + 1 < sizeArr)
    {
        int best = node, left = 2 * node + 1, right = 2 * node + 2;
        if (left < sizeArr && cmp(arr[best], arr[left]))
            best = left;
        if (right < sizeArr && cmp(arr[best], arr[right]))
            best = right;
        if (best == node)
            break;
        mySwap(arr[node], arr[best]);
        node = best;
    }
}

template <typename T, typename Comp = std::less<T>>
void heapSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    for (int i = sizeArr / 2 - 1; i >= 0; i--)
        heapify(arr, sizeArr, i, cmp);
    for (int i = sizeArr - 1; i > 0; i--)
    {
        mySwap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

/* Merge sort:
- Vietnamese: Sắp xếp trộn.
- Range: [left, right].
- Time complexity: O(n log n) (best case), O(n log n) (worst case).
- Space complexity: O(n) (worst case).
- Stability: Yes.
- In-place: No. */

template <typename T, typename Comp = std::less<T>>
void merge(T arr[], T temp[], int left, int mid, int right, const Comp &cmp = Comp())
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (cmp(arr[j], arr[i]))
            temp[k++] = arr[j++];
        else
            temp[k++] = arr[i++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (int t = left; t <= right; t++)
        arr[t] = temp[t];
}

template <typename T, typename Comp = std::less<T>>
void mergeSort(T arr[], T temp[], int left, int right, const Comp &cmp = Comp())
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, temp, left, mid, cmp);      // chú ý.
    mergeSort(arr, temp, mid + 1, right, cmp); // chú ý.
    merge(arr, temp, left, mid, right, cmp);   // chú ý.
}

template <typename T, typename Comp = std::less<T>>
void mergeSort(T arr[], int sizeArr, const Comp &cmp = Comp())
{
    T *temp = new T[sizeArr];
    mergeSort(arr, temp, 0, sizeArr - 1, cmp);
    delete[] temp;
}

#endif // ALGORITHMS_HPP