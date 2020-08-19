#include <iostream>
using namespace std;

int f(int x) {
    return x - (x + 2) / 3;
}

int main() {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << endl;
    return 0;
}
