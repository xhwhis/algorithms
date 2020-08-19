#include <iostream>
using namespace std;
string str;

void solve() {
    int n, cnt = 0;
    cin >> n >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '.') continue;
        str[i] = 'X';
        if (i + 1 < str.size()) str[i + 1] = 'X';
        if (i + 2 < str.size()) str[i + 2] = 'X';
        cnt += 1;
    }
    cout << cnt << endl;
    return ;
}

int main() {
    int tcase;
    cin >> tcase;
    while (tcase--) solve();
    return 0;
}
