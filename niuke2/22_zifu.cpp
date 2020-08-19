#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str[105];
int num[105] = {0};

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> str[i];
        for (int j = str[i].length() - 6; j <= str[i].length() - 1; j++) {
            num[i] = num[i] * 10 + str[i][j] - '0';
        }
    }
    sort(num, num + m);
    for (int i = 0; i < m; i++) {
        cout << num[i] << endl;
    }
    return 0;
}
