#include "user.h"
#include "hash.h"
#include <iomanip>

using namespace std;
string genID(int userCount) {
    basic_string<char> id = "ID";
    int num = userCount + 1;

    // Формуємо число у форматі XXXX (додаємо нулі, якщо треба)
    if (num < 10) id += "000" + to_string(num);
    else if (num < 100) id += "00" + to_string(num);
    else if (num < 1000) id += "0" + to_string(num);
    else id += to_string(num);

    return id;
}

void addUser(User*& users, int &userCount) {
    User newUser;

    cout << "Введіть логін користувача: "<< "\033[1;35m";
    cin >> newUser.login;
    cout << "\033[0m";

    // Якщо логін закінчується на "_", то ставимо admin, інакше user
    if (newUser.login.back() == '_') {
        newUser.login.pop_back(); // Видаляємо "_" символ
        newUser.accessLvl = "admin";
    } else if (newUser.login == "guest") {
        newUser.accessLvl = "guest";
    } else {
        newUser.accessLvl = "user";
    }

    cout << "Введіть пароль користувача: "<< "\033[1;35m";
    string password;
    cin >> password;
    cout << "\033[0m";

    // Хешуємо пароль
    newUser.passHash = pHash(password);

    // Генеруємо ID (формат: ХХХХ)
    newUser.id = genID(userCount);

    User* newUsers = new User[userCount + 1];
    for (int i = 0; i < userCount; i++) {
        newUsers[i] = users[i];
    }
    newUsers[userCount] = newUser;
    delete[] users;
    users = newUsers;
    userCount++;

    cout << "\t\033[1;32m" << "Користувач доданий успішно!\n" << "\033[0m";
}

void outp(const User* users, int userCount) {
    cout << "\033[1;33m+----------+----------------+------------------+-----------------+\033[0m\n";
    cout << "\033[1;33m|    ID    |   Хеш-пароля   |      Логін       |  Рівень доступу |\033[1;33m\n";
    cout << "\033[1;33m+----------+----------------+------------------+-----------------+\033[0m\n";

    for (int i = 0; i < userCount; ++i) {
        cout << "\033[1;33m| "
             << setw(7) << users[i].id << "  | "
             << setw(14) << users[i].passHash << " | "
             << setw(16) << users[i].login << " | "
             << setw(15) << users[i].accessLvl << " |\033[0m\n";
    }

    cout << "\033[1;33m+----------+----------------+------------------+-----------------+\033[0m\n";

}