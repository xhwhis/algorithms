#include <stdio.h>

int cnt[26] = {0};

int main() {
    char ch;
    while (~scanf ("%c", &ch) && ch != '\n') {
        cnt[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) printf("%c%d", i + 'a', cnt[i]);
    }
    return 0;
}
