//
//  program2.cpp
//  LR2
//
//  Программа 2: Использование calloc, realloc и free
//

#include "program2.h"
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

// Метод 2: Ввод строки с помощью calloc, realloc и free (порциями)
static char* inputStringMethod2() {
    std::cout << "\nВвод строки методом 2 (calloc/realloc/free):\n";
    std::cout << "Введите строку (Enter для завершения): ";
    
    const size_t CHUNK_SIZE = 5; // Размер порции (не более 5)
    size_t allocatedSize = CHUNK_SIZE;
    size_t currentSize = 0;
    
    // Выделяем начальную память с помощью calloc
    char* str = (char*)calloc(allocatedSize + 1, sizeof(char)); // +1 для '\0'
    if (!str) {
        std::cerr << "Ошибка выделения памяти!\n";
        return nullptr;
    }
    
    char ch;
    while ((ch = std::cin.get()) != '\n') {
        // Если памяти недостаточно, увеличиваем её с помощью realloc
        if (currentSize >= allocatedSize) {
            allocatedSize += CHUNK_SIZE;
            char* newStr = (char*)realloc(str, (allocatedSize + 1) * sizeof(char));
            if (!newStr) {
                std::cerr << "Ошибка перевыделения памяти!\n";
                free(str);
                return nullptr;
            }
            str = newStr;
            // Обнуляем новую память
            memset(str + currentSize, 0, (allocatedSize - currentSize + 1) * sizeof(char));
        }
        
        str[currentSize++] = ch;
    }
    str[currentSize] = '\0';
    
    // Оптимизируем память: освобождаем лишнюю
    if (currentSize < allocatedSize) {
        char* optimized = (char*)realloc(str, (currentSize + 1) * sizeof(char));
        if (optimized) {
            str = optimized;
        }
    }
    
    return str;
}

// Запуск программы 2
void runProgram2() {
    std::cout << "\n========================================\n";
    std::cout << "ПРОГРАММА 2: Использование calloc, realloc и free\n";
    std::cout << "========================================\n";
    
    char* str = inputStringMethod2();
    if (!str) {
        std::cerr << "Ошибка ввода строки!\n";
        return;
    }
    
    std::cout << "\nИсходная строка: \"" << str << "\"\n";
    
    // Шаг 1: Удаляем все символы, кроме букв и цифр
    char* step1 = removeNonAlphanumeric(str);
    std::cout << "После удаления небуквенных/нецифровых символов: \"" << step1 << "\"\n";
    
    // Шаг 2: Переворачиваем строку
    char* step2 = reverseString(step1);
    std::cout << "После переворота: \"" << step2 << "\"\n";
    
    // Шаг 3: Удваиваем каждый третий символ
    char* result = doubleEveryThird(step2);
    std::cout << "После удвоения каждого третьего символа: \"" << result << "\"\n";
    
    // Освобождаем память
    free(str);
    free(step1);
    free(step2);
    free(result);
}

