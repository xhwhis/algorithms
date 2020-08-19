#include <iostream>
#include <algorithm>
#define max_n 100000
#define max_m 100000
using namespace std;

int num[max_n + 5] = {0};
int ques[max_m + 5] = {0};

int main() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if(i) num[i] += num[i - 1];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ques[i];
    }
    for (int i = 0; i < m; i++) {
        cout << (lower_bound(num, num + n, ques[i]) - num + 1) << endl;
    }
    return 0;
}
