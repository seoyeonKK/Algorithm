#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
using namespace std;
int arr[1000][1000];
int dist[1000][1000][11][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<tuple<int, int, int, int>> q;
int N, M, L;

void bfs() {
    while (!q.empty()) {
        int x, y, z, night;
        tie(x,y,z, night) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (arr[nx][ny] == 0 && dist[nx][ny][z][1-night] == 0) {
                dist[nx][ny][z][1-night] = dist[x][y][z][night] + 1;
                q.push({ nx, ny, z, 1-night });
            }
            if (night == 0 && z+1 <= L && arr[nx][ny] == 1 && dist[nx][ny][z+1][1-night] == 0) {
                dist[nx][ny][z+1][1-night] = dist[x][y][z][night] + 1;
                q.push({ nx, ny, z+1, 1-night });
            }
        }
        if (dist[x][y][z][1-night] == 0) {
            dist[x][y][z][1-night] = dist[x][y][z][night] + 1;
            q.push({x, y, z, 1-night });
        }
    }
}

int main() {
    cin >> N >> M >> L;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    dist[0][0][0][0] = 1;
    q.push(make_tuple(0,0,0,0));
    bfs();

    int ans = -1;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i <= L; i++) {
            if (dist[N-1][M-1][i][j] == 0) continue;
            if (ans == -1) {
                ans = dist[N-1][M-1][i][j];
            } else if (ans > dist[N-1][M-1][i][j]) {
                ans = dist[N-1][M-1][i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
