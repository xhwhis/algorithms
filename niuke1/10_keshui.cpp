#include <iostream>
using namespace std;

int val[100005] = {0};
int val2[100005] = {0};

int main() {
    int n, k, ans = 0, ans1 = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        if (t == 1) {
            ans += val[i];
        } else {
            val2[i] = val[i];
        }
        val2[i] += val2[i - 1];
    }
    for (int i = k; i <= n; i++) {
        ans1 = max(ans1, val2[i] - val2[i - k]);
    }
    cout << ans1 + ans << endl;
    return 0;
}
