#include <iostream>
using namespace std;

int arr[3][100000];

int read_line_to(int k, int &n) {
    int a;
    n = 0;
    while (~scanf("%d", &a)) {
        arr[k][n++] = a;
        if (getchar() == '\n') break;
    }
    return n;
}

int solve() {
    int n, m;
    if (!read_line_to(0, n)) return 0;
    read_line_to(1, m);
    int p1 = 0, p2 = 0, t = 0;
    while (p1 < n || p2 < m) {
        if (p2 == m || (p1 < n && arr[0][p1] < arr[1][p2])) {
            arr[2][t++] = arr[0][p1++];
        } else {
            arr[2][t++] = arr[1][p2++];
        }
    }
    for (int i = 0; i < t; i++){
        i && cout << ",";
        cout << arr[2][i];
    }
    cout << endl;
    return t;
}

int main() {
    int a, k = 0;
    while (solve()) ;
    return 0;
}
