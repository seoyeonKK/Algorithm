#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int n, m;
int a[10][10];
int dist[10][10][20]; // {i, j, t(도착시간)}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while(!q.empty()) {
        int x, y, t;
        tie(x, y, t) = q.front();
        q.pop();

        // 아직 이동하지 못하는 오작교인 경우
        if (a[x][y] >= 2 && t%a[x][y] != 0) {
            int nt = (t+1)%a[x][y];
            if (dist[x][y][nt] == -1) {
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.push({x, y, nt});
            }
        }
        else {
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (a[x][y] >= 2 && a[nx][ny] >= 2) continue; // 연속한 오작교인 경우
                    if (a[nx][ny] >= 1) {
                        int nt = (dist[x][y][t] + 1) % a[nx][ny];
                        if (dist[nx][ny][nt] == -1) {
                            dist[nx][ny][nt] = dist[x][y][t] + 1;
                            q.push({nx, ny, nt});
                        }
                    }
                }
            }
        }
    }
    return dist[n-1][n-1][0];
}

// 오작교를 세울 수 있는지 확인하는 함수
bool can(int i, int j) {
    bool garo = false;
    if (j-1 >= 0 && a[i][j-1] == 0) garo = true;
    if (j+1 < n && a[i][j+1] == 0) garo = true;
    bool sero = false;
    if (i-1 >= 0 && a[i-1][j] == 0) sero = true;
    if (i+1 < n && a[i+1][j] == 0) sero = true;
    return !(garo&& sero);

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 && can(i, j)) {
                a[i][j] = m;
                int now = bfs();
                if (now != -1) {
                        if (ans == -1 || ans > now) {
                            ans = now;
                        }
                }
                a[i][j] = 0; // 오작교 원상태로
            }
        }
    }
    cout << ans << endl;
    return 0;
}
