#ifndef shaker_sort_h
#define shaker_sort_h

#include <vector>
#include <utility>

namespace sorting {

template<typename T>
void shakerSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
        right--;
        
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
            }
        }
        left++;
    }
}

}

#endif

