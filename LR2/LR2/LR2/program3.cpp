//
//  program3.cpp
//  LR2
//
//  Программа 3: Работа с файлами
//

#include "program3.h"
#include "functions.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

// Метод 1: Ввод строки с помощью malloc и free (по одному символу)
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
        str = (char*)malloc((currentSize + 1) * sizeof(char));
        if (!str) {
            std::cerr << "Ошибка выделения памяти!\n";
            return nullptr;
        }
        str[0] = ch;
        str[1] = '\0';
        
        // Ввод остальных символов
        while ((ch = std::cin.get()) != '\n') {
            size_t newSize = currentSize + 1;
            char* newStr = (char*)malloc((newSize + 1) * sizeof(char));
            if (!newStr) {
                std::cerr << "Ошибка выделения памяти!\n";
                free(str);
                return nullptr;
            }
            
            for (size_t i = 0; i < currentSize; i++) {
                newStr[i] = str[i];
            }
            
            newStr[currentSize] = ch;
            newStr[newSize] = '\0';
            
            free(str);
            str = newStr;
            currentSize = newSize;
        }
    } else {
        str = (char*)malloc(1 * sizeof(char));
        if (!str) {
            std::cerr << "Ошибка выделения памяти!\n";
            return nullptr;
        }
        str[0] = '\0';
    }
    
    return str;
}

// Метод 2: Ввод строки с помощью calloc, realloc и free (порциями)
static char* inputStringMethod2() {
    std::cout << "\nВвод строки методом 2 (calloc/realloc/free):\n";
    std::cout << "Введите строку (Enter для завершения): ";
    
    const size_t CHUNK_SIZE = 5;
    size_t allocatedSize = CHUNK_SIZE;
    size_t currentSize = 0;
    
    char* str = (char*)calloc(allocatedSize + 1, sizeof(char));
    if (!str) {
        std::cerr << "Ошибка выделения памяти!\n";
        return nullptr;
    }
    
    char ch;
    while ((ch = std::cin.get()) != '\n') {
        if (currentSize >= allocatedSize) {
            allocatedSize += CHUNK_SIZE;
            char* newStr = (char*)realloc(str, (allocatedSize + 1) * sizeof(char));
            if (!newStr) {
                std::cerr << "Ошибка перевыделения памяти!\n";
                free(str);
                return nullptr;
            }
            str = newStr;
            memset(str + currentSize, 0, (allocatedSize - currentSize + 1) * sizeof(char));
        }
        
        str[currentSize++] = ch;
    }
    str[currentSize] = '\0';
    
    if (currentSize < allocatedSize) {
        char* optimized = (char*)realloc(str, (currentSize + 1) * sizeof(char));
        if (optimized) {
            str = optimized;
        }
    }
    
    return str;
}

// Чтение строки из файла методом 1
static char* readStringFromFileMethod1(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения!\n";
        return nullptr;
    }
    
    char* str = nullptr;
    size_t currentSize = 0;
    char ch;
    
    if (file.get(ch)) {
        currentSize = 1;
        str = (char*)malloc(2 * sizeof(char));
        if (!str) {
            file.close();
            return nullptr;
        }
        str[0] = ch;
        str[1] = '\0';
        
        while (file.get(ch)) {
            if (ch == '\n' || ch == '\r') continue;
            
            size_t newSize = currentSize + 1;
            char* newStr = (char*)malloc((newSize + 1) * sizeof(char));
            if (!newStr) {
                free(str);
                file.close();
                return nullptr;
            }
            
            for (size_t i = 0; i < currentSize; i++) {
                newStr[i] = str[i];
            }
            
            newStr[currentSize] = ch;
            newStr[newSize] = '\0';
            
            free(str);
            str = newStr;
            currentSize = newSize;
        }
    } else {
        str = (char*)malloc(1 * sizeof(char));
        if (!str) {
            file.close();
            return nullptr;
        }
        str[0] = '\0';
    }
    
    file.close();
    return str;
}

// Чтение строки из файла методом 2
static char* readStringFromFileMethod2(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения!\n";
        return nullptr;
    }
    
    const size_t CHUNK_SIZE = 5;
    size_t allocatedSize = CHUNK_SIZE;
    size_t currentSize = 0;
    
    char* str = (char*)calloc(allocatedSize + 1, sizeof(char));
    if (!str) {
        file.close();
        return nullptr;
    }
    
    char ch;
    while (file.get(ch)) {
        if (ch == '\n' || ch == '\r') continue;
        
        if (currentSize >= allocatedSize) {
            allocatedSize += CHUNK_SIZE;
            char* newStr = (char*)realloc(str, (allocatedSize + 1) * sizeof(char));
            if (!newStr) {
                free(str);
                file.close();
                return nullptr;
            }
            str = newStr;
            memset(str + currentSize, 0, (allocatedSize - currentSize + 1) * sizeof(char));
        }
        
        str[currentSize++] = ch;
    }
    str[currentSize] = '\0';
    
    if (currentSize < allocatedSize) {
        char* optimized = (char*)realloc(str, (currentSize + 1) * sizeof(char));
        if (optimized) {
            str = optimized;
        }
    }
    
    file.close();
    return str;
}

// Запуск программы 3
void runProgram3() {
    std::cout << "\n========================================\n";
    std::cout << "ПРОГРАММА 3: Работа с файлами\n";
    std::cout << "========================================\n";
    
    // Выбор метода ввода
    int method;
    std::cout << "\nВыберите метод ввода (1 - malloc/free, 2 - calloc/realloc/free): ";
    std::cin >> method;
    std::cin.ignore(); // Пропускаем символ новой строки после ввода числа
    
    char* inputStr = nullptr;
    
    if (method == 1) {
        inputStr = inputStringMethod1();
    } else if (method == 2) {
        inputStr = inputStringMethod2();
    } else {
        std::cerr << "Неверный выбор метода!\n";
        return;
    }
    
    if (!inputStr) {
        std::cerr << "Ошибка ввода строки!\n";
        return;
    }
    
    std::cout << "\nВведенная строка: \"" << inputStr << "\"\n";
    
    // Запись исходной строки в файл
    const char* inputFilename = "input.txt";
    std::ofstream outFile(inputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        free(inputStr);
        return;
    }
    outFile << inputStr;
    outFile.close();
    std::cout << "Строка записана в файл " << inputFilename << "\n";
    
    // Освобождаем память исходной строки
    free(inputStr);
    
    // Выбор метода чтения
    std::cout << "\nВыберите метод чтения из файла (1 - malloc/free, 2 - calloc/realloc/free): ";
    std::cin >> method;
    std::cin.ignore();
    
    char* readStr = nullptr;
    
    if (method == 1) {
        readStr = readStringFromFileMethod1(inputFilename);
    } else if (method == 2) {
        readStr = readStringFromFileMethod2(inputFilename);
    } else {
        std::cerr << "Неверный выбор метода!\n";
        return;
    }
    
    if (!readStr) {
        std::cerr << "Ошибка чтения строки из файла!\n";
        return;
    }
    
    std::cout << "Прочитанная из файла строка: \"" << readStr << "\"\n\n";
    
    // Обработка строки
    std::cout << "Обработка строки:\n";
    
    // Шаг 1: Удаляем все символы, кроме букв и цифр
    char* step1 = removeNonAlphanumeric(readStr);
    std::cout << "1. После удаления небуквенных/нецифровых символов: \"" << step1 << "\"\n";
    
    // Шаг 2: Переворачиваем строку
    char* step2 = reverseString(step1);
    std::cout << "2. После переворота: \"" << step2 << "\"\n";
    
    // Шаг 3: Удваиваем каждый третий символ
    char* result = doubleEveryThird(step2);
    std::cout << "3. После удвоения каждого третьего символа: \"" << result << "\"\n";
    
    // Запись результата в файл
    const char* outputFilename = "output.txt";
    std::ofstream resultFile(outputFilename);
    if (!resultFile.is_open()) {
        std::cerr << "Ошибка открытия файла для записи результата!\n";
        free(readStr);
        free(step1);
        free(step2);
        free(result);
        return;
    }
    resultFile << result;
    resultFile.close();
    std::cout << "\nРезультат записан в файл " << outputFilename << "\n";
    
    // Освобождаем память
    free(readStr);
    free(step1);
    free(step2);
    free(result);
}

