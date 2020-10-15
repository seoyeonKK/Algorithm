#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int d[500][500];
char s[500][501];
int n, m;

int go(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 1; // 탈출 하는 경우
    if (d[x][y] != -1) return d[x][y]; // 탈출 못하는 경우
    d[x][y] = 0; // 지나간 자리 체크
    if (s[x][y] == 'U') {
        d[x][y] = go(x-1, y);
    }
    else if (s[x][y] == 'R') {
        d[x][y] = go(x, y+1);
    }
    else if (s[x][y] == 'L') {
        d[x][y] = go(x, y-1);
    }
    else {
        d[x][y] = go(x+1, y);
    }

    return d[x][y];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            d[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == -1) {
                go(i, j);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 1) {
                ans += 1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
