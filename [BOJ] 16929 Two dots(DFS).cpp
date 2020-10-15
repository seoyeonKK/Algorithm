#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
char a[55][55];
bool check[55][55];
int dist[55][55];

bool go(int x, int y, int cnt, char color) {
    if (check[x][y]) {
        if (cnt-dist[x][y] >= 4) {
            return true;
        } else {
            return false;
        }
    }
    check[x][y] = true;
    dist[x][y] = cnt;
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (a[nx][ny] == color) {
                if (go(nx, ny, cnt+1, color)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (check[i][j]) continue;
            memset(dist,0,sizeof(dist));
            bool ok = go(i, j, 1, a[i][j]);
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
