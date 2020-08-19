#include <iostream>
using namespace std;

typedef struct Data {
    int height, num;
} towers[105];

bool cmp(Data a, Data b) {
    return a.height < b.height;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> towers[i].height;
        towers[i].num = i + 1;
    }
    sort(towers, towers + n, cmp);
    while (k--) {
        
    }
    return 0;
}
