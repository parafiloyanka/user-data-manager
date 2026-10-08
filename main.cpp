#include "utilit.h"

using namespace std;

int main() {
    //language();
    welcome();

    User* users = nullptr;
    int userCount = 0;
    menu(users, userCount);

    delete[] users;
    return 0;
}