#include <stdio.h>
#define max_n 300000

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int arr[max_n + 5], val[max_n + 5], head = 1, tail = 1;

int main() {
    int n = 0;
    while (getchar() != '\n') {
        scanf ("%d", &arr[n++]);
    }
    int ans = arr[1];
    for (int i = 1; i <= n; i++) {
        if (i - val[head] > n) head++;
        ans = MAX(ans, arr[i] - arr[val[head]]);
        while (tail - head && arr[i] < arr[val[tail - 1]]) tail--;
        val[tail++] = i;
    }
    printf ("%d", ans > 0 ? ans : 0);
    return 0;
}
