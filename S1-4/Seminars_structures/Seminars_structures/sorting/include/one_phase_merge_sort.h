#ifndef one_phase_merge_sort_h
#define one_phase_merge_sort_h

#include <vector>
#include <algorithm>

namespace sorting {

template<typename T>
void merge(std::vector<T>& arr, std::vector<T>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

template<typename T>
void onePhaseMergeSortHelper(std::vector<T>& arr, std::vector<T>& temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        onePhaseMergeSortHelper(arr, temp, left, mid);
        onePhaseMergeSortHelper(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

template<typename T>
void onePhaseMergeSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    if (n > 0) {
        std::vector<T> temp(n);
        onePhaseMergeSortHelper(arr, temp, 0, n - 1);
    }
}

}

#endif

