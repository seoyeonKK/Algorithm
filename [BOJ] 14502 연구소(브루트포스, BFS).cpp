#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[10][10];
int b[10][10];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

// 안전역역의 크기를 구하는 함수
int bfs() {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // map 복사
            b[i][j] = map[i][j];
            // 바이러스 삽입
            if (b[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                // 바이러스 주위로 확산
                if (b[nx][ny] == 0) {
                    b[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 안전영역 크기 구하기
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 0) {
                cnt += 1;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;

    // 빈 곳에 벽 놓을 (x1,y1) (x2, y2) (x3, y3) 선정
    for (int x1 = 0; x1 < n; x1++) {
        for (int y1 = 0; y1 < m; y1++) {
            if (map[x1][y1] != 0) continue;
            for (int x2 = 0; x2 < n; x2++) {
                for (int y2 = 0; y2 < m; y2++) {
                    if (map[x2][y2] != 0) continue;
                    for (int x3 = 0; x3 < n; x3++) {
                        for (int y3 = 0; y3 < m; y3++) {
                            if (map[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            map[x1][y1] = 1;
                            map[x2][y2] = 1;
                            map[x3][y3] = 1;

                            // 벽 두고나서 안전영역 구하기
                            int cur = bfs();
                            if (ans < cur) ans = cur;

                            // 벽 취소하기
                            map[x1][y1] = 0;
                            map[x2][y2] = 0;
                            map[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
