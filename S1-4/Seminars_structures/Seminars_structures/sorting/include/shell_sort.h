#ifndef shell_sort_h
#define shell_sort_h

#include <vector>

namespace sorting {

template<typename T>
void shellSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j;
            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            arr[j] = temp;
        }
    }
}

}

#endif

