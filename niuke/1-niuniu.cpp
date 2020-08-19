#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

const int max_n = 100000;

struct Date {
    int d, p;
} jobs[max_n + 5];

int a[max_n + 5], ind[max_n + 5];
int ans[max_n + 5];

bool cmp1(const Date &a, const Date &b) {
    return a.d < b.d;
}

bool cmp2(const int ind1, const int ind2) {
    return a[ind1] < a[ind2];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].d >> jobs[i].p;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        ind[i] = i;
    }
    sort(jobs, jobs + n, cmp1);
    sort(ind, ind + m, cmp2);
    priority_queue<int> s;
    for (int i = 0, j = 0; i < m; i++) {
        int x = ind[i];
        while (j < n && jobs[j].d <= a[x]) {
            s.push(jobs[j++].p);
        }
        if (s.size()) ans[x] = s.top();
        else ans[x] = 0;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
