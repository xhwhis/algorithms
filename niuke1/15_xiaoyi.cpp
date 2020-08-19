#include <iostream>
#include <cmath>
using namespace std;
typedef long long lint;

double log_C(lint n, lint m) {
    if (m < 0) return -1;
    double p = 0;
    lint i = n - m + 1, j = 2;
    while (i <= n) p += log10(i), i++;
    while (j <= m) p -= log10(j), j++;
    return p;
}

lint C(lint n, lint m) {
    if (m < 0) return 0;
    lint p = 1, i = n - m + 1, j = 2;
    while (i <= n) {
        p *= i, i++;
        if (j <= m && p % j == 0) p /= j, j++;
    }
    return p;
}

int main() {
    lint n, m, k;
    string ans = "";
    cin >> n >> m >> k;
    double log_k = log10(k);
    for (int i = 0, I = n + m; i < I; i++) {
        if (log_C(n + m - 1, n - 1) - 0.5 > log_k) {
            ans += 'a';
            n -= 1;
            continue;
        }
        if (C(n + m - 1, n - 1) >= k) {
            ans += 'a';
            n -= 1;
        } else {
            ans += 'z';
            k -= C(n + m - 1, n - 1);
            m -= 1;
        }
    }
    if (k != 1) cout << "-1" << endl; 
    else cout << ans << endl;
    return 0;
}
