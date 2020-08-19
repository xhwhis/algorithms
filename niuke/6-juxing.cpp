#include <iostream>
#include <map>
using namespace std;

struct Data {
    int x1, y1, x2, y2;
} arr[55];
map<int, int> indx, indy;

bool check(int k, int x, int y) {
    if (x < arr[k].x1 || x > arr[k].x2) return false;
    if (y < arr[k].y1 || y > arr[k].y2) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].x1;
    for (int i = 0; i < n; i++) cin >> arr[i].y1;
    for (int i = 0; i < n; i++) cin >> arr[i].x2;
    for (int i = 0; i < n; i++) cin >> arr[i].y2;
    for (int i = 0; i < n; i++) {
        arr[i].x1 += 1, arr[i].y1 += 1;
        indx[arr[i].x1] = indx[arr[i].x2] = 0;
        indy[arr[i].y1] = indy[arr[i].y2] = 0;
    }
    int cntx = 0, cnty = 0;
    for (auto iter = indx.begin(); iter != indx.end(); iter++) {
        iter->second = (++cntx);
    }
    for (auto iter = indy.begin(); iter != indy.end(); iter++) {
        iter->second = (++cnty);
    }
    for (int i = 0; i < n; i++) {
        arr[i].x1 = indx[arr[i].x1];
        arr[i].y1 = indy[arr[i].y1];
        arr[i].x2 = indx[arr[i].x2];
        arr[i].y2 = indy[arr[i].y2];
    }
    int ans = 0;
    for (int i = 1; i <= cntx; i++) {
        for (int j = 1; j <= cnty; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (check(k, i, j)) cnt += 1;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}
