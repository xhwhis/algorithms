#include <iostream>
#include <algorithm>
using namespace std;

struct Data {
    int h, m;
} clocks[105];

bool cmp(const Data &a, const Data &b) {
    if (a.h - b.h) return a.h < b.h;
    return a.m < b.m;
}

int main() {
    int n, a, b, x;
    cin >> n;
    for (int i = 0; i < n; i++) { 
        cin >> clocks[i].h >> clocks[i].m;
    }
    sort(clocks, clocks + n, cmp);
    cin >> x >> a >> b;
    b -= x;
    while (b < 0) b += 60, a -= 1;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (clocks[i].h < a) {
            ans = i;
        }
        if (clocks[i].h == a && clocks[i].m <= b) {
            ans = i;
        }
    }
    cout << clocks[ans].h << " " << clocks[ans].m << endl;
    return 0;
}
