#include <iostream>
#include <algorithm>
using namespace std;
 
int a[105];
int ans_x[1005];
int ans_y[1005];

int getMax(int n) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (a[ret] < a[i]) ret = i;
    }
    return ret;
}
 
int getMin(int n) {
    int ret = 0;
    for (int i = 1; i < n; i++) {
        if (a[ret] > a[i]) ret = i;
    }
    return ret;
}

int main() {
    int n, k, m = 0, s = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (k--) {
        int ind1 = getMax(n);
        int ind2 = getMin(n);
        if (a[ind1] - a[ind2] <= 1) break;
        a[ind1] -= 1;
        a[ind2] += 1;
        ans_x[m] = ind1 + 1;
        ans_y[m] = ind2 + 1;
        m += 1;
    }
    s = a[getMax(n)] - a[getMin(n)];
    cout << s << " " << m << endl;
    for (int i = 0; i < m; i++) {
        cout << ans_x[i] << " " << ans_y[i] << endl;
    }
    return 0;
}
