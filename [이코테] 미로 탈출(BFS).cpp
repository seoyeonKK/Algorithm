#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int map[201][201];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위 체크 
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽이면 continue
            if (map[nx][ny] == 0) continue;
            // 처음 방문하는 곳일 때만 탐색 
            if (map[nx][ny] == 1) {
                map[nx][ny] = map[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << map[n-1][m-1] << endl;

    return 0;
}
