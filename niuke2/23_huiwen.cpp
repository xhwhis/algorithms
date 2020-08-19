#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
int f[1005][1005] = {0};

int main() {
    cin >> str1;
    str2 = str1;
    reverse(str1.begin(), str1.end());
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (str1[i - 1] == str2[j - 1]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    cout << f[str1.size()][str1.size()] << endl;
    return 0;
}
