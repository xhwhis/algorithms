#include <iostream>
#include <algorithm>
using namespace std;
#define max_n 1000000

struct Data {
    int x, y;
} arr[max_n + 5];
int val[max_n + 5];
int len[max_n + 5], ans;

bool cmp(const Data &a, const Data &b) {
    if (a.x - b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++) {
        val[i] = arr[i].y;
    }
    len[0] = -1;
    ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(len, len + ans + 1, val[i]) - len;
        ans = max(ans, pos);
        len[pos] = val[i];
    }
    cout << ans << endl;
    return 0;
}
