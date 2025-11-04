#ifndef selection_sort_h
#define selection_sort_h

#include <vector>
#include <utility>

namespace sorting {

template<typename T>
void selectionSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            std::swap(arr[minIndex], arr[i]);
        }
    }
}

}

#endif

