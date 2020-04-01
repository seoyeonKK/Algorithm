#include <iostream>
#include <vector>
#include <queue>
#define MAX 50
using namespace std;

// 동 북 서 남
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

//반시계 방향 인덱스
int ccw[4] = { 2, 0, 3, 1 };
//시계 방향 인덱스
int cw[4] = { 2, 1, 3, 0 };

int R, C, T;
int cleanerX = -1, cleanerX2 = -1, cleanerY = -1, cleanerY2 = -1;
int map[MAX][MAX];


void BFS() {
    for (int t = 0; t < T; t++) {
        //현재 배열을 복사한 뒤
        int copyMap[MAX][MAX] = {0,};
        queue<pair<int, int>> q;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 미세먼지 위치
                if (map[i][j] >= 1) {
                    q.push({i, j});
                }

                copyMap[i][j] = map[i][j];
            }
        }

        //미세먼지 확산
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            int temp = copyMap[y][x] / 5;

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                // 미세먼지 확산 업데이트
                if (0 <= ny && ny < R && 0 <= nx && nx < C) {
                    // 공기청정기 있는 곳이 아니면
                    if (copyMap[ny][nx] >= 0) {
                        map[ny][nx] += temp;
                        map[y][x] -= temp;
                    }
                }
            }
        }

        // 미세먼지가 확산된 배열을 복사하고
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                copyMap[i][j] = map[i][j];
            }
        }

        // 공기청정기 윗쪽 반시계방향 이동
        int y = cleanerY;
        int x = cleanerX + 1;
        map[y][x] = 0;

        for (int i = 0; i < 4; i++) {
            while (1) {
                int ny = y + dy[ccw[i]];
                int nx = x + dx[ccw[i]];

                // 공기청정기 위치면 탈출
                if (ny == cleanerY && nx == cleanerX)
                    break;
                if (!(0 <= ny && ny < R && 0 <= nx && nx < C))
                    break;

                map[ny][nx] = copyMap[y][x];
                y = ny;
                x = nx;
            }
        }

        // 공기청정기 아랫쪽 시계방향 이동
        y = cleanerY2;
        x = cleanerX2 + 1;
        map[y][x] = 0;

        for (int i = 0; i < 4; i++) {
            while (1) {
                int ny = y + dy[cw[i]];
                int nx = x + dx[cw[i]];

                // 공기청정기 위치면 탈출
                if (ny == cleanerY2 && nx == cleanerX2)
                    break;
                if (!(0 <= ny && ny < R && 0 <= nx && nx < C))
                    break;

                map[ny][nx] = copyMap[y][x];
                y = ny;
                x = nx;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];

            // 공기청정기 위치
            if (map[i][j] == -1) {
                if (cleanerY == -1) {
                    cleanerX = j;
                    cleanerY = i;
                }
                else {
                    cleanerX2 = j;
                    cleanerY2 = i;
                }
            }
        }
    }

    BFS();

    int result = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] >= 1) {
                result += map[i][j];
            }
        }
    }

    cout << result;

    return 0;
}
