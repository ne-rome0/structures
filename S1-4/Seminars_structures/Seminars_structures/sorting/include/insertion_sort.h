#ifndef insertion_sort_h
#define insertion_sort_h

#include <vector>

namespace sorting {

template<typename T>
void insertionSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

}

#endif

