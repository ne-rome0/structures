#ifndef bubble_sort_h
#define bubble_sort_h

#include <vector>
#include <utility>

namespace sorting {

template<typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

}

#endif

