//
//  functions.cpp
//  LR2
//
//  Реализация общих функций обработки строк
//

#include "functions.h"
#include <cstring>
#include <cctype>

// Функция для удаления всех символов, кроме букв и цифр
char* removeNonAlphanumeric(const char* str) {
    if (!str) return nullptr;
    
    size_t len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (!result) return nullptr;
    
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    
    return result;
}

// Функция для переворота строки
char* reverseString(const char* str) {
    if (!str) return nullptr;
    
    size_t len = strlen(str);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    if (!result) return nullptr;
    
    for (size_t i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    
    return result;
}

// Функция для удвоения каждого третьего символа
char* doubleEveryThird(const char* str) {
    if (!str) return nullptr;
    
    size_t len = strlen(str);
    size_t maxSize = len + (len / 3) + 1;
    char* result = (char*)malloc(maxSize * sizeof(char));
    if (!result) return nullptr;
    
    size_t j = 0;
    for (size_t i = 0; i < len; i++) {
        result[j++] = str[i];
        // Удваиваем каждый третий символ (индексы 2, 5, 8, ...)
        if ((i + 1) % 3 == 0) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    
    return result;
}

