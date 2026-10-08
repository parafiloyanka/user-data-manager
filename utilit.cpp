#include "utilit.h"
#include <iostream>

using namespace std;

/*void language() {
  // SetConsoleCP(1251);
  // SetConsoleOutputCP(1251);
}*/

void welcome() {
    cout << "\033[1;35m";
    cout << "Лабораторна робота 5. Дослідження процесу створення структур та обʼєднаних даних\n";
    cout << "\033[1;36m";cout << "\033[1;35m";
    cout << "Лабораторна робота 5. Дослідження процесу створення структур та обʼєднаних даних\n";
    cout << "\033[1;36m";
    cout << "Завдання 1. Структура для зберігання даних користувача\n";
    cout << "\033[1;35m";
    cout << "Парафіло Яна. КБ-22. Варіант 1 \n";
    cout << "\033[0m";
    cout << "Завдання 1. Структура для зберігання даних користувача\n";
    cout << "\033[1;35m";
    cout << "Парафіло Яна. КБ-22. Варіант 1 \n";
    cout << "\033[0m";
}

// Функція для виведення меню
void menu(User*& users, int& userCount) {
    int choice;
    bool a = true;
    cout << "\033[1;35m";
    cout << "\n\tМеню:\n";
    cout << "1. Додати користувача\n";
    cout << "2. Вивести всіх користувачів\n";
    cout << "Інше - Вийти\n";


    do {
        cout << "Ваш вибір: " << " \033[1;36m";
        cin >> choice;
        cout << "\033[0m\n";

        switch (choice) {
            case 1:
                addUser(users, userCount);
            break;
            case 2:
                outp(users, userCount);
            break;
            default:
                a=false;
                cout << "\033[1;35m" << "\nДякую за використання програми!\n\tАлєксєєва Аліна КБ-21" << "\033[0m" << endl;
        }
    } while (a == true);
}