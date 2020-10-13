#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int a[20][20];
bool check[20][20];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs() {
    memset(check, false, sizeof(check));
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 2 && !check[i][j]) {
                bool dead = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                check[i][j] = true;
                int cur = 0;
                while(!q.empty()) {
                    cur += 1;
                    int x, y;
                    tie(x,y) = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (a[nx][ny] == 0) {
                                dead = false;
                            }
                            else if (a[nx][ny] == 2 && !check[nx][ny]) {
                                q.push({nx, ny});
                                check[nx][ny] = true;
                            }
                        }
                    }
                }
                if (dead) {
                    ans += cur;
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < M; y1++) {
            if (a[x1][y1] != 0) continue;
            for (int x2 = 0; x2 < N; x2++) {
                for (int y2 = 0; y2 < M; y2++) {
                    if (x1==x2 && y1==y2) continue;
                    if (a[x2][y2] != 0) continue;
                    a[x1][y1] = 1;
                    a[x2][y2] = 1;
                    int cur = bfs();
                    if (cur > ans) ans = cur;
                    a[x1][y1] = 0;
                    a[x2][y2] = 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
