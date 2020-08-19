#include <iostream>
using namespace std;

int main() {
    long long n, k, cnt = 0;
    cin >> n >> k;
    for (long long y = k + 1; y <= n; y++) {
        cnt += (y - k) * (n / y) + (n % y - k + 1 * (k != 0)) * (n % y >= k);
    }
    cout << cnt << endl;
    return 0;
}
