#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

struct User {
    string id;
    string login;
    string passHash;
    string accessLvl;
};

// Оголошення функцій для роботи з користувачами
void addUser(User*& users, int &userCount);
void outp(const User* users, int userCount);
string genID(int userCount);

#endif //USER_H
