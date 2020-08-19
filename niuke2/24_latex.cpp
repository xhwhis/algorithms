#include <iostream>
using namespace std;
const int max_n = 100000;

int val[max_n + 5];
int n, p, h, w;

bool check(int mid) {
    int cnt = w / mid, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += val[i] / cnt + (val[i] % cnt != 0);
    }
    return sum <= (h / mid) * p;
}

int bs(int l, int r) {
    if (l == r) return l;
    int mid = (l + r + 1) >> 1;
    if (check(mid)) return bs(mid, r);
    return bs(l, mid - 1);
}

int main() {
    while (cin >> n >> p >> h >> w) {
        for (int i = 0; i < n; i++) cin >> val[i];
        cout << bs(1, w) << " ";
    }
    return 0;
}
