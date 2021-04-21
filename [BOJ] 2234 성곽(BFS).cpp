#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n, m;
int a[50][50]; // 벽의 정보
int d[50][50]; // 방의 번호
int room[50*50]; // i번에 몇 개 방

// 서 북 동 남
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int bfs(int x, int y, int rooms) {
    queue<pair<int, int>> q;
    q.push({x, y});
    d[x][y] = rooms;
    int cnt = 0; // 전체 방의 개수

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        cnt += 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            // 범위 체크
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문 여부 체크
            if (d[nx][ny] != 0) continue;
            // 벽 위치 비트연산자로 체크
            if (a[x][y] & (1 << k)) continue;
            q.push({nx, ny});
            d[nx][ny] = rooms;
        }
    }
    return cnt;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == 0) {
                rooms += 1; // 새로운 방이면 방 번호 증가
                room[rooms] = bfs(i, j, rooms); // 같은 rooms 그룹에 몇 개의 방이 있는지 저장
            }
        }
    }

    // 1. 이 성에 있는 방의 개수 출력
    cout << rooms << endl;

    // 2. 가장 넓은 방의 넓이 출력
    int ans = 0;
    for (int i = 1; i <= rooms; i++) {
        if (ans < room[i]) {
            ans = room[i];
        }
    }
    cout << ans << endl;

    // 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i;
            int y = j;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                // 범위 체크
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                // 같은 방인지 체크
                if (d[nx][ny] == d[x][y]) continue;
                if (a[x][y] & (1 << k)) {
                    if (ans < room[d[x][y]] + room[d[nx][ny]]) {
                        ans = room[d[x][y]] + room[d[nx][ny]];
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
