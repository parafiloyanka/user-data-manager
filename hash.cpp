#include "hash.h"
#include <sstream>
#include <iomanip>

using namespace std;

string pHash(const string& password) {
    string hash = "";
    unsigned int result = 0;

    for (char c : password) {
        result ^= (c * 7);  // XOR операція для комбінування байтів
    }
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << result;
        hash += ss.str();
    return hash;
}