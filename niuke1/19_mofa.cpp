#include <iostream>
using namespace std;
#define max_n 1000
#define mod_num (1000000000LL + 3)
long long f[max_n + 5];

void init() {
    f[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        for (int j = 1; j <= i; j <<= 1) {
            f[i] += f[i - j];
            f[i] %= mod_num;
        }
    }
    return ;
}

int main() {
    init();
    int m, n;
    cin >> m;
    while (m--) {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
