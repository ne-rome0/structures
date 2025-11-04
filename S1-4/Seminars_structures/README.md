# Seminars_structures

Проект для демонстрации и тестирования различных алгоритмов сортировки на языке C++.

## Описание

Проект содержит реализацию 12 алгоритмов сортировки с комплексным тестированием каждого алгоритма на различных типах входных данных. Все алгоритмы реализованы как шаблонные функции в пространстве имен `sorting`, что позволяет использовать их с любыми типами данных, поддерживающими операторы сравнения.

## Структура проекта

```
Seminars_structures/
├── main.cpp                    # Главный файл с тестами
├── sorting/
│   ├── include/               # Заголовочные файлы (.h)
│   │   ├── binary_insertion_sort.h
│   │   ├── bubble_sort.h
│   │   ├── exchange_sort.h
│   │   ├── insertion_sort.h
│   │   ├── natural_merge_sort.h
│   │   ├── one_phase_merge_sort.h
│   │   ├── optimized_bubble_sort.h
│   │   ├── quick_sort.h
│   │   ├── selection_sort.h
│   │   ├── shaker_sort.h
│   │   ├── shell_sort.h
│   │   └── two_phase_merge_sort.h
│   └── src/                   # Файлы реализации (.cpp)
│       ├── binary_insertion_sort.cpp
│       ├── bubble_sort.cpp
│       ├── exchange_sort.cpp
│       ├── insertion_sort.cpp
│       ├── natural_merge_sort.cpp
│       ├── one_phase_merge_sort.cpp
│       ├── optimized_bubble_sort.cpp
│       ├── quick_sort.cpp
│       ├── selection_sort.cpp
│       ├── shaker_sort.cpp
│       ├── shell_sort.cpp
│       └── two_phase_merge_sort.cpp
└── Seminars_structures.xcodeproj/  # Проект Xcode
```

## Реализованные алгоритмы

1. **Сортировка вставками (Insertion Sort)**
2. **Сортировка выбором (Selection Sort)**
3. **Сортировка обменом (Exchange Sort)**
4. **Сортировка пузырьком (Bubble Sort)**
5. **Улучшенная сортировка пузырьком (Optimized Bubble Sort)**
6. **Сортировка вставками с бинарным поиском (Binary Insertion Sort)**
7. **Сортировка шейкером (Shaker Sort)**
8. **Метод Шелла (Shell Sort)**
9. **Быстрая сортировка (Quick Sort)**
10. **Двухфазная сортировка слиянием (Two Phase Merge Sort)**
11. **Однофазная сортировка слиянием (One Phase Merge Sort)**
12. **Естественная сортировка слиянием (Natural Merge Sort)**

## Тестирование
#### Реализовать тестирование при помощи библиотеки catch2 не получилось в связи с тем, что она криво работает на mac 
Каждый алгоритм тестируется тремя типами входных данных:

1. **Нормальные данные** - массив целых чисел в случайном порядке
2. **Вещественные числа** - массив чисел с плавающей точкой
3. **Критический случай** - массив с повторяющимися элементами
