#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

bool check[8][8][9]; // (r, c, t초 후)
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main() {
    int n = 8;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    queue<tuple<int, int, int>> q;
    check[7][0][0] = true;
    q.push({7, 0, 0});
    bool ans = false;

    while(!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();
        if (x == 0 && y == 7) ans = true;
        for (int k = 0; k < 9; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nt = min(t+1, 8);
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (nx-t >= 0 && a[nx-t][ny] == '#') continue;
                if (nx-t-1 >= 0 && a[nx-1-t][ny] == '#') continue;
                if (!check[nx][ny][nt]) {
                    check[nx][ny][nt] = true;
                    q.push({nx, ny, nt});
                }
            }
        }
    }

    if (ans) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}
