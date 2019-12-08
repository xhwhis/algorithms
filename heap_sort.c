#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {\
    __typeof(a) __tmp = (a);\
    (a) = (b);\
    (b) = __tmp;\
}

void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int tmp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[tmp] < arr[l]) tmp = l;
        if (r <= n && arr[tmp] < arr[r]) tmp = r;
        if (tmp == ind) break;
        swap(arr[ind], arr[tmp]);
        ind = tmp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr--;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf ("arr(%d) = [", n);
    for (int i = 0; i < n; i++) {
        i && printf (" ");
        printf ("%d", arr[i]);
    }
    printf ("]\n");
    return ;
}

int main() {
    srand(time(0));
    int *arr = (int *)malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, 20);
    heap_sort(arr, 20);
    output(arr, 20);
    free(arr);
    return 0;
}
