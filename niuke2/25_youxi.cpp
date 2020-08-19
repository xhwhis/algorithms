#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    cout << (str.length() + 1) * 26 - str.length() << endl;
    return 0;
}
