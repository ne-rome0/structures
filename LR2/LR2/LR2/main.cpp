//
//  main.cpp
//  LR2
//
//  Created by Роман Основин on 04.11.2025.
//
//  Главный файл - запуск всех программ
//

#include <iostream>
#include "program1.h"
#include "program2.h"
#include "program3.h"

int main(int argc, const char * argv[]) {
    int choice;
    
    do {
        std::cout << "\n========================================\n";
        std::cout << "|  ПРОГРАММЫ НА ВЫБОР:                  |\n";
        std::cout << "========================================\n";
        std::cout << "|  1. Программа 1 (malloc/free)         |\n";
        std::cout << "|  2. Программа 2 (calloc/realloc/free) |\n";
        std::cout << "|  3. Программа 3 (работа с файлами)    |\n";
        std::cout << "|  0. Выход                             |\n";
        std::cout << "========================================\n";
        std::cout << "Выберите программу: ";
        
        std::cin >> choice;
        std::cin.ignore(); // Пропускаем символ новой строки
        
        switch (choice) {
            case 1:
                runProgram1();
                break;
            case 2:
                runProgram2();
                break;
            case 3:
                runProgram3();
                break;
            case 0:
                std::cout << "\nВыход из программы.\n";
                break;
            default:
                std::cout << "\nНеверный выбор! Попробуйте снова.\n";
                break;
        }
        
        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}
