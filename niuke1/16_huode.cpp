#include <iostream>
#define max_n 200000
using namespace std;

long long d[max_n + 5] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int l = 0, r = n - 1;
    long long lsum = d[0], rsum = d[n - 1];
    long long ans;
    while (l < r) {
        if (lsum == rsum) ans = lsum;
        if (lsum > rsum) rsum += d[--r];
        else lsum += d[++l];
    }
    cout << ans <<endl;
    return 0;
}
