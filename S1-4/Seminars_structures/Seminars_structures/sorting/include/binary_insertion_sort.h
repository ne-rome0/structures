#ifndef binary_insertion_sort_h
#define binary_insertion_sort_h

#include <vector>
#include <algorithm>

namespace sorting {

template<typename T>
int binarySearch(const std::vector<T>& arr, T item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item) {
            return mid + 1;
        } else if (arr[mid] > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

template<typename T>
void binaryInsertionSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        int pos = binarySearch(arr, key, 0, j);
        
        while (j >= pos) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

}

#endif

