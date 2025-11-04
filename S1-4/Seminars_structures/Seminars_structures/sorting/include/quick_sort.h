#ifndef quick_sort_h
#define quick_sort_h

#include <vector>
#include <utility>

namespace sorting {

template<typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

template<typename T>
void quickSortHelper(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

template<typename T>
void quickSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    if (n > 0) {
        quickSortHelper(arr, 0, n - 1);
    }
}

}

#endif

