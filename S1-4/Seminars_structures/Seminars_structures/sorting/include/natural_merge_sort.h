#ifndef natural_merge_sort_h
#define natural_merge_sort_h

#include <vector>
#include <algorithm>

namespace sorting {

template<typename T>
void mergeNatural(std::vector<T>& arr, std::vector<T>& temp, int left, int mid, int right) {
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
void naturalMergeSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    if (n <= 1) return;
    
    std::vector<T> temp(n);
    
    while (true) {
        bool sorted = true;
        int start = 0;
        
        while (start < n) {
            int mid = start;
            while (mid < n - 1 && arr[mid] <= arr[mid + 1]) {
                mid++;
            }
            
            if (mid == n - 1) {
                break;
            }
            
            int end = mid + 1;
            while (end < n - 1 && arr[end] <= arr[end + 1]) {
                end++;
            }
            
            mergeNatural(arr, temp, start, mid, end);
            sorted = false;
            start = end + 1;
        }
        
        if (sorted) {
            break;
        }
    }
}

}

#endif

