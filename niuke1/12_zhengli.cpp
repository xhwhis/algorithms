#include <iostream>
#include <algorithm>
using namespace std;

int a[4], b[4], x[4], y[4];
int a1[4], b1[4];

void rotate(int &tx, int &ty, int k) {
    if (k == 0) return ;
    swap(tx, ty);
    tx = -tx;
    rotate(tx, ty, k - 1);
    return ;
}

#define S(a) ((a) * (a))
int len(int i, int j) {
    return S(a1[i] - a1[j]) + S(b1[i] - b1[j]);
}

bool cmp(int a, int b) {
    return len(0, a) < len(0, b);
}

void solve() {
    for (int i = 0; i < 4; i++) {
        cin >> a[i] >> b[i] >> x[i] >> y[i];
    }
    int ans = 25;
    for (int i = 0, I = (1 << 8); i < I; i++) {
        int cnt = 0; 
        for (int j = 0; j < 4; j++) {
            a[j] -= x[j], b[j] -= y[j];
            a1[j] = a[j], b1[j] = b[j];
            rotate(a1[j], b1[j], (i >> (2 * j)) % 4);
            a[j] += x[j], b[j] += y[j];
            a1[j] += x[j], b1[j] += y[j];
            cnt += (i >> (2 * j)) % 4;
        }
        int ind[3] = {1, 2, 3};
        sort(ind, ind + 3, cmp);
        if (len(0, ind[0]) != len(0, ind[1])) continue;
        if (len(0, ind[0]) == len(0, ind[2])) continue;
        int val1 = (a1[ind[0]] - a1[0]) * (a1[ind[1]] - a1[0]);
        int val2 = (b1[ind[0]] - b1[0]) * (b1[ind[1]] - b1[0]);
        if (val1 + val2 != 0) continue;
        if (len(ind[2], ind[0]) != len(ind[2], ind[0])) continue;
        if (len(ind[2], ind[0]) != len(0, ind[0])) continue;
        ans = min(ans, cnt);
    }
    if (ans == 25) cout << -1 << endl;
    else cout << ans << endl;
    return ;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve();
    }
    return 0;
}
