#ifndef optimized_bubble_sort_h
#define optimized_bubble_sort_h

#include <vector>
#include <utility>

namespace sorting {

template<typename T>
void optimizedBubbleSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

}

#endif

