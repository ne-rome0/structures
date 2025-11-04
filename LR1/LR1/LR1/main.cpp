#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>

bool isLetterOrDigit(unsigned char c) {
    return std::isalnum(c) || c >= 0x80;
}

void variant1() {
    const int SIZE = 1000;
    char str[SIZE];
    
    std::cout << "\n=== Вариант 1: Строка массив ===" << std::endl;
    std::cout << "Введите строку: ";
    std::cin.ignore();
    std::cin.getline(str, SIZE);
    
    // Фильтрация
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isLetterOrDigit((unsigned char)str[i])) {
            str[len++] = str[i];
        }
    }
    str[len] = '\0';
    
    // Переворот
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
    
    // Удвоение каждого третьего символа
    int count = 0;
    for (int i = 2; i < len; i += 3) {
        count++;
    }
    
    int newLen = len + count;
    char temp[SIZE];
    
    int pos = 0;
    for (int i = 0; i < len; i++) {
        temp[pos++] = str[i];
        if (i % 3 == 2) {
            temp[pos++] = str[i];
        }
    }
    temp[newLen] = '\0';
    
    for (int i = 0; i <= newLen; i++) {
        str[i] = temp[i];
    }
    
    std::cout << "Результат: " << str << std::endl;
}

void variant2() {
    const int SIZE = 1000;
    char* str = new char[SIZE];
    
    std::cout << "\n=== Вариант 2: Строка Си ===" << std::endl;
    std::cout << "Введите строку: ";
    std::cin.ignore();
    std::cin.getline(str, SIZE);
    
    // Фильтрация
    char* p = str;
    char* q = str;
    
    while (*p != '\0') {
        if (isLetterOrDigit((unsigned char)*p)) {
            *q++ = *p++;
        } else {
            p++;
        }
    }
    *q = '\0';
    
    int len = (int)strlen(str);
    
    // Переворот
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
    
    // Удвоение каждого третьего символа
    int count = 0;
    for (int i = 2; i < len; i += 3) {
        count++;
    }
    
    int newLen = len + count;
    char temp[SIZE];
    
    int pos = 0;
    for (int i = 0; i < len; i++) {
        temp[pos++] = str[i];
        if (i % 3 == 2) {
            temp[pos++] = str[i];
        }
    }
    temp[newLen] = '\0';
    
    for (int i = 0; i <= newLen; i++) {
        str[i] = temp[i];
    }
    
    std::cout << "Результат: " << str << std::endl;
    delete[] str;
}

void variant3() {
    std::cout << "\n=== Вариант 3: Строка в файле ===" << std::endl;
    
    // Пути для поиска input.txt в Xcode
    const char* inputFiles[] = {
        "input.txt",                    // Текущая рабочая директория
        "LR1/input.txt",                // Подпапка LR1
        "LR1/LR1/input.txt",           // Подпапка LR1/LR1
        "../input.txt",                 // Родительская директория
        "../LR1/input.txt"              // Родительская/LR1
    };
    const char* outputFile = "output.txt";
    const int SIZE = 1000;
    char str[SIZE];
    
    std::ifstream fin;
    bool opened = false;
    std::string foundPath;
    
    std::cout << "Поиск файла input.txt..." << std::endl;
    
    for (int i = 0; i < 5; i++) {
        fin.open(inputFiles[i], std::ios::in);
        if (fin.is_open() && fin.good()) {
            foundPath = inputFiles[i];
            opened = true;
            std::cout << "✓ Файл найден: " << foundPath << std::endl;
            break;
        }
        fin.clear();
        fin.close();
    }
    
    if (!opened) {
        std::cout << "\nОшибка: не удалось открыть файл input.txt" << std::endl;
        std::cout << "Проверены следующие пути:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "  - " << inputFiles[i] << std::endl;
        }
        std::cout << "\nСоздайте файл input.txt в одной из этих папок." << std::endl;
        std::cout << "В Xcode можно установить рабочую директорию в настройках схемы (Scheme)." << std::endl;
        return;
    }
    
    fin.getline(str, SIZE);
    fin.close();
    
    std::cout << "Исходная строка из файла: " << str << std::endl;
    
    // Фильтрация
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isLetterOrDigit((unsigned char)str[i])) {
            str[len++] = str[i];
        }
    }
    str[len] = '\0';
    
    // Переворот
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
    
    // Удвоение каждого третьего символа
    int count = 0;
    for (int i = 2; i < len; i += 3) {
        count++;
    }
    
    int newLen = len + count;
    char temp[SIZE];
    
    int pos = 0;
    for (int i = 0; i < len; i++) {
        temp[pos++] = str[i];
        if (i % 3 == 2) {
            temp[pos++] = str[i];
        }
    }
    temp[newLen] = '\0';
    
    for (int i = 0; i <= newLen; i++) {
        str[i] = temp[i];
    }
    
    std::ofstream fout(outputFile);
    if (!fout.is_open()) {
        std::cout << "Ошибка: не удалось создать файл " << outputFile << std::endl;
        return;
    }
    
    fout << str;
    fout.close();
    
    std::cout << "Результат записан в файл: " << outputFile << std::endl;
    std::cout << "Результат: " << str << std::endl;
}

int main() {
    int choice;
    
    while (true) {
        std::cout << "\n=== Лабораторная работа №1 ===" << std::endl;
        std::cout << "Обработка строки символов" << std::endl << std::endl;
        std::cout << "Выберите вариант:" << std::endl;
        std::cout << "1 - Строка массив" << std::endl;
        std::cout << "2 - Строка Си" << std::endl;
        std::cout << "3 - Строка в файле" << std::endl;
        std::cout << "0 - Выход" << std::endl;
        std::cout << "Ваш выбор: ";
        
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                variant1();
                break;
            case 2:
                variant2();
                break;
            case 3:
                variant3();
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                return 0;
            default:
                std::cout << "Неверный выбор!" << std::endl;
                break;
        }
    }
    
    return 0;
}