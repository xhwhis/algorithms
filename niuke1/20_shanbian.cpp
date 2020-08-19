#include <iostream>
#include <set>
using namespace std;
#define max_n 100000
struct Node { 
    int val, flag;
    int l, r;
} l[max_n + 5];
int n, m, head;

void del(int p) {
    if (p == 0) return ;
    l[p].flag = 1;
    l[l[p].l].r = l[p].r;
    l[l[p].r].l = l[p].l;
    l[p].l = l[p].r = 0;
    return ;
}

typedef pair<int, int> PII;

inline int sign(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    l[0].r = 1, l[0].l = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i].val;
        l[i].l = i - 1;
        l[i].r = (i + 1) * (i < n);
    }
    set<PII> s;
    int p = l[0].r, cnt = 0, sum = 0;
    while (p) {
        while (l[p].r && sign(l[p].val) * sign(l[l[p].r].val) >= 0) {
            l[p].val += l[l[p].r].val;
            del(l[p].r);
        }
        s.insert(PII(abs(l[p].val), p));
        if (l[p].val > 0) cnt += 1, sum += l[p].val;
        p = l[p].r;
    }
    while (cnt > m) {
        int ind = s.begin()->second;
        s.erase(s.begin());
        if (l[ind].flag) continue;
        if ((l[ind].r && l[ind].l) || l[ind].val > 0) {
            sum -= abs(l[ind].val);
            cnt -= 1;
            l[ind].val += l[l[ind].l].val;
            l[ind].val += l[l[ind].r].val;
            del(l[ind].l); del(l[ind].r);
            s.insert(PII(abs(l[ind].val), ind));
        } else {
            del(ind);
        }
    }
    cout << sum << endl;
    return 0;
}
