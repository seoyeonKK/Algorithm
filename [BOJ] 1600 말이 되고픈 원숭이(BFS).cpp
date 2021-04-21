#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

// 정점 : {x, y, z(말처럼 이동한 횟수)}
int a[200][200];
int d[200][200][31];
// 0 ~ 3 idx 까지는 인접 이동, 4~11 idx는 말처럼 이동
int dx[] = {0, 0, 1, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, -1, 0, 0, 1, 2, 2, 1, -1, -2, -2, -1};
// 말처럼 이동했을 때 cost = 1로 초기화
int cost[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

int main() {
    int l, n, m;
    cin >> l >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(d, -1, sizeof(d));
    queue<tuple<int, int, int>> q;
    d[0][0][0] = 0;
    q.push({0, 0, 0});

    while(!q.empty()) {
        int x, y, c;
        tie(x, y, c) = q.front();
        q.pop();

        for (int k = 0; k < 12; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nc = c + cost[k];

            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 장애물, 말처럼 이동 횟수, 방문한 적 있는지 체크
            if (a[nx][ny] == 1 || nc > l || d[nx][ny][nc] != -1) continue;

            d[nx][ny][nc] = d[x][y][c] + 1;
            q.push({nx, ny, nc});
        }
    }

    int ans = -1;
    for (int i = 0; i <= l; i++) {
        if (d[n-1][m-1][i] == -1) continue;
        if (ans == -1 || ans > d[n-1][m-1][i]) {
            ans = d[n-1][m-1][i];
        }
    }

    cout << ans << endl;

    return 0;
}
