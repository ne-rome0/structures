#include <iostream>
#include <vector>
#include <iomanip>
#include "sorting/include/insertion_sort.h"
#include "sorting/include/selection_sort.h"
#include "sorting/include/exchange_sort.h"
#include "sorting/include/bubble_sort.h"
#include "sorting/include/optimized_bubble_sort.h"
#include "sorting/include/binary_insertion_sort.h"
#include "sorting/include/shaker_sort.h"
#include "sorting/include/shell_sort.h"
#include "sorting/include/quick_sort.h"
#include "sorting/include/two_phase_merge_sort.h"
#include "sorting/include/one_phase_merge_sort.h"
#include "sorting/include/natural_merge_sort.h"

template<typename T>
void printVector(const std::vector<T>& arr, const std::string& label) {
    std::cout << label << ": ";
    if (arr.empty()) {
        std::cout << "(пустой)";
    } else {
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i];
            if (i < arr.size() - 1) {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
}

template<typename T>
bool isSorted(const std::vector<T>& arr) {
    if (arr.empty() || arr.size() == 1) {
        return true;
    }
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Вспомогательная функция для тестирования алгоритма сортировки
template<typename SortFunc>
void testSortAlgorithm(const std::string& algorithmName, SortFunc sortFunc) {
    std::cout << algorithmName << "\n";
    std::cout << "========================================\n\n";
    
    // Тест 1: Нормальные данные (целые числа)
    std::cout << "Тест 1: Нормальные данные (целые числа)\n";
    std::cout << "----------------------------------------\n";
    std::vector<int> normalData = {64, 34, 25, 12, 22, 11, 90};
    printVector(normalData, "До сортировки");
    std::vector<int> normalCopy = normalData;
    sortFunc(normalCopy);
    printVector(normalCopy, "После сортировки");
    std::cout << "Результат: " << (isSorted(normalCopy) ? "✓ Массив отсортирован" : "✗ Ошибка") << "\n\n";
    
    // Тест 2: Вещественные числа
    std::cout << "Тест 2: Вещественные числа\n";
    std::cout << "----------------------------------------\n";
    std::vector<double> doubleData = {64.5, 34.2, 25.8, 12.1, 22.9, 11.7, 90.3};
    printVector(doubleData, "До сортировки");
    std::vector<double> doubleCopy = doubleData;
    sortFunc(doubleCopy);
    printVector(doubleCopy, "После сортировки");
    std::cout << "Результат: " << (isSorted(doubleCopy) ? "✓ Массив отсортирован" : "✗ Ошибка") << "\n\n";
    
    // Тест 3: Критический случай - массив с повторяющимися элементами
    std::cout << "Тест 3: Критический случай (повторяющиеся элементы)\n";
    std::cout << "----------------------------------------\n";
    std::vector<int> criticalData = {3, 1, 3, 2, 2, 1, 5, 5, 1};
    printVector(criticalData, "До сортировки");
    std::vector<int> criticalCopy = criticalData;
    sortFunc(criticalCopy);
    printVector(criticalCopy, "После сортировки");
    std::cout << "Результат: " << (isSorted(criticalCopy) ? "✓ Массив отсортирован" : "✗ Ошибка") << "\n\n";
    
    std::cout << std::endl;
}

int main() {
    std::cout << "========================================\n";
    std::cout << "  Демонстрация алгоритмов сортировки\n";
    std::cout << "  Каждый алгоритм тестируется тремя типами данных:\n";
    std::cout << "  1. Нормальные данные (целые числа)\n";
    std::cout << "  2. Вещественные числа\n";
    std::cout << "  3. Критический случай (повторяющиеся элементы)\n";
    std::cout << "========================================\n\n";
    
    // Тестирование всех алгоритмов сортировки
    testSortAlgorithm("1. СОРТИРОВКА ВСТАВКАМИ (Insertion Sort)", 
                      [](auto& arr) { sorting::insertionSort(arr); });
    
    testSortAlgorithm("2. СОРТИРОВКА ВЫБОРОМ (Selection Sort)", 
                      [](auto& arr) { sorting::selectionSort(arr); });
    
    testSortAlgorithm("3. СОРТИРОВКА ОБМЕНОМ (Exchange Sort)", 
                      [](auto& arr) { sorting::exchangeSort(arr); });
    
    testSortAlgorithm("4. СОРТИРОВКА ПУЗЫРЬКОМ (Bubble Sort)", 
                      [](auto& arr) { sorting::bubbleSort(arr); });
    
    testSortAlgorithm("5. УЛУЧШЕННАЯ СОРТИРОВКА ПУЗЫРЬКОМ (Optimized Bubble Sort)", 
                      [](auto& arr) { sorting::optimizedBubbleSort(arr); });
    
    testSortAlgorithm("6. СОРТИРОВКА ВСТАВКАМИ С БИНАРНЫМ ПОИСКОМ (Binary Insertion Sort)", 
                      [](auto& arr) { sorting::binaryInsertionSort(arr); });
    
    testSortAlgorithm("7. СОРТИРОВКА ШЕЙКЕРОМ (Shaker Sort)", 
                      [](auto& arr) { sorting::shakerSort(arr); });
    
    testSortAlgorithm("8. МЕТОД ШЕЛЛА (Shell Sort)", 
                      [](auto& arr) { sorting::shellSort(arr); });
    
    testSortAlgorithm("9. БЫСТРАЯ СОРТИРОВКА (Quick Sort)", 
                      [](auto& arr) { sorting::quickSort(arr); });
    
    testSortAlgorithm("10. ДВУХФАЗНАЯ СОРТИРОВКА СЛИЯНИЕМ (Two Phase Merge Sort)", 
                      [](auto& arr) { sorting::twoPhaseMergeSort(arr); });
    
    testSortAlgorithm("11. ОДНОФАЗНАЯ СОРТИРОВКА СЛИЯНИЕМ (One Phase Merge Sort)", 
                      [](auto& arr) { sorting::onePhaseMergeSort(arr); });
    
    testSortAlgorithm("12. ЕСТЕСТВЕННАЯ СОРТИРОВКА СЛИЯНИЕМ (Natural Merge Sort)", 
                      [](auto& arr) { sorting::naturalMergeSort(arr); });
    
    // Дополнительные тесты граничных случаев
    std::cout << "========================================\n";
    std::cout << "  Дополнительные тесты граничных случаев\n";
    std::cout << "========================================\n\n";
    
    std::cout << "Тест с пустым массивом:\n";
    std::vector<int> emptyArray = {};
    std::cout << "Размер до: " << emptyArray.size() << "\n";
    sorting::insertionSort(emptyArray);
    std::cout << "Размер после: " << emptyArray.size() << "\n";
    std::cout << "Результат: " << (emptyArray.empty() ? "✓ Корректно обработан" : "✗ Ошибка") << "\n\n";
    
    std::cout << "Тест с массивом из одного элемента:\n";
    std::vector<int> singleElement = {42};
    printVector(singleElement, "До");
    sorting::insertionSort(singleElement);
    printVector(singleElement, "После");
    std::cout << "Результат: " << (singleElement.size() == 1 && singleElement[0] == 42 ? "✓ Корректно обработан" : "✗ Ошибка") << "\n\n";
    
    std::cout << "Тест с массивом в обратном порядке:\n";
    std::vector<int> reverseArray = {5, 4, 3, 2, 1};
    printVector(reverseArray, "До");
    sorting::insertionSort(reverseArray);
    printVector(reverseArray, "После");
    std::cout << "Результат: " << (isSorted(reverseArray) ? "✓ Массив отсортирован" : "✗ Ошибка") << "\n\n";
    
    std::cout << "Тест с уже отсортированным массивом:\n";
    std::vector<int> sortedArray = {1, 2, 3, 4, 5};
    printVector(sortedArray, "До");
    sorting::optimizedBubbleSort(sortedArray);
    printVector(sortedArray, "После");
    std::cout << "Результат: " << (isSorted(sortedArray) ? "✓ Массив отсортирован" : "✗ Ошибка") << "\n\n";
    
    std::cout << "========================================\n";
    std::cout << "  Все алгоритмы сортировки протестированы!\n";
    std::cout << "========================================\n";
    
    return 0;
}
