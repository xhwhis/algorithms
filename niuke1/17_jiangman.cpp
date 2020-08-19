#include <iostream>
using namespace std;

int arr[10005];

int update(int *arr, int n) {
    if (n == 1) {
        int ret = arr[0];
        arr[0] = 0;
        return ret;
    }
    int mid = n / 2;
    int cnt = (n - 1) / 2;
    int val1 = update(arr, cnt);
    int val2 = update(arr + cnt + 1, cnt);
    int val3 = arr[mid];
    arr[mid] = val1 + val2;
    return val1 + val2 + val3;
}

int main() {
    int a, n;
    while (~scanf("%d", &a)) arr[n++] = a;
    update(arr + n / 2, n / 2);
    for (int i = n / 2; i < n; i++) {
        cout << arr[i];
        i + 1 == n || cout << " ";
    }
    cout << endl;
    return 0;
}
