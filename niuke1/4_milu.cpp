#include <iostream>
using namespace std;
char dir[4] = {'N', 'E', 'S', 'W'};

int main() {
    int k = 0, n;
    string str;
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'R') k = (k + 1) % 4;
        else k = (k + 3) % 4;
    }
    cout << dir[k] << endl;
    return 0;
}
