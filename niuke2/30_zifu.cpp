#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == str[i + 1]) {
            cnt++;
        } else {
            printf ("%d%c", cnt, str[i]);
            cnt = 1;
        }
    }
    return 0;
}
