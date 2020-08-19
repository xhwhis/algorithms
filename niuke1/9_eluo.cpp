#include <iostream>
#include <algorithm>
using namespace std;

int num[1005] = {0};

int main() {
    int n, m;
    cin >> n >> m;
    int c;
    for (int i = 0; i < m; i++) {
        cin >> c;
        num[c - 1]++;
    }
    sort(num, num + n);
    cout << num[0] << endl;
    return 0;
}
