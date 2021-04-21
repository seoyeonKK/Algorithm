#include <iostream>
#include <queue>
using namespace std;

// 정점 : (A, B)
int sum = 0;
int check[1501][1501];

void dfs(int x, int y) {
    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = {x, y, sum-x-y};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                int b[3] = {x, y, sum-x-y};
                b[i] += a[i];
                b[j] -= a[i];
                dfs(b[0], b[1]);
            }
        }
    }
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    sum = x + y + z;

    if ((sum%3) != 0) {
        cout << 0 << endl;
        return 0;
    }

    dfs(x, y);

    // a,b가 sum/3이라면, 나머지 하나도 자동으로 sum/3이므로
    if (check[sum/3][sum/3]) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
