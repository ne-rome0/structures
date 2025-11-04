//
//  program1.cpp
//  LR2
//
//  Программа 1: Использование malloc и free
//

#include "program1.h"
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

// Метод 1: Ввод строки с помощью malloc и free (по одному символу)
// Для 1-го символа: malloc(1), для 2-го: malloc(2), переписываем 1-й и добавляем 2-й
static char* inputStringMethod1() {
    std::cout << "\nВвод строки методом 1 (malloc/free):\n";
    std::cout << "Введите строку (Enter для завершения): ";
    
    char* str = nullptr;
    size_t currentSize = 0;
    char ch;
    
    // Ввод первого символа - захватываем память для 1 символа
    ch = std::cin.get();
    if (ch != '\n') {
        currentSize = 1;
        // Выделяем память для 1 символа + '\0' для корректной строки
        str = (char*)malloc((currentSize + 1) * sizeof(char));
        if (!str) {
            std::cerr << "Ошибка выделения памяти!\n";
            return nullptr;
        }
        str[0] = ch;
        str[1] = '\0';
        
        // Ввод остальных символов
        while ((ch = std::cin.get()) != '\n') {
            // Захватываем память для (currentSize + 1) символов
            // Т.е. если было 1, теперь будет 2; если было 2, теперь будет 3 и т.д.
            size_t newSize = currentSize + 1;
            char* newStr = (char*)malloc((newSize + 1) * sizeof(char));
            if (!newStr) {
                std::cerr << "Ошибка выделения памяти!\n";
                free(str);
                return nullptr;
            }
            
            // Самостоятельно переписываем введенные символы
            for (size_t i = 0; i < currentSize; i++) {
                newStr[i] = str[i];
            }
            
            // Добавляем новый символ
            newStr[currentSize] = ch;
            newStr[newSize] = '\0';
            
            // Освобождаем память, захваченную ранее
            free(str);
            
            // Обновляем указатели
            str = newStr;
            currentSize = newSize;
        }
    } else {
        // Пустая строка
        str = (char*)malloc(1 * sizeof(char));
        if (!str) {
            std::cerr << "Ошибка выделения памяти!\n";
            return nullptr;
        }
        str[0] = '\0';
    }
    
    return str;
}

// Запуск программы 1
void runProgram1() {
    std::cout << "\n========================================\n";
    std::cout << "ПРОГРАММА 1: Использование malloc и free\n";
    std::cout << "========================================\n";
    
    char* str = inputStringMethod1();
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

