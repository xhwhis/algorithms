#include <iostream>
#include <cstring>
using namespace std;

int len;

int get_num(char *str) {
    int num = 0;
    len = 0;
    while (str[len] >= '0' && str[len] <= '9') {
        num = num * 10 + str[len++] - '0';
    }
    return num;
}

int main() {
    char str[1005];
    cin >> str;
    int ans = 0;
    int i = 0;
    while (i < strlen(str)) {
        if (str[0] == '-') {
            ans -= get_num(str + 1);
            i += len + 1;
        } else {
            ans += get_num(str);
            i += len;
        }
        if (str[i] == '+') {
            ans += get_num(str + i);
            i += len + 1;
        } else {
            ans -= get_num(str + i);
            i += len + 1;
        }
    }
    cout << ans;
    return 0;
}
