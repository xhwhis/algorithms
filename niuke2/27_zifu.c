#include <stdio.h>
#include <string.h>

char str1[1005], str2[1005];

int main() {
    while (~scanf ("%s %s", str1, str2)) {
        printf ("%d\n", (strstr(str1, str2) || strstr(str2, str1)) ? 1 : 0);
    }
    return 0;
}
