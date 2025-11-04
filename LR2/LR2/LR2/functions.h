//
//  functions.h
//  LR2
//
//  Общие функции обработки строк
//

#ifndef functions_h
#define functions_h

#include <cstdlib>

// Функция для удаления всех символов, кроме букв и цифр
char* removeNonAlphanumeric(const char* str);

// Функция для переворота строки
char* reverseString(const char* str);

// Функция для удвоения каждого третьего символа
char* doubleEveryThird(const char* str);

#endif /* functions_h */

