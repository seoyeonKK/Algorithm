#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

// (1) 얼음이 언제 녹는지 체크 BFS
// (2) 두 백조가 만날 수 있는지 체크 BFS
string a[1500];
bool wcheck[1500][1500];
bool scheck[1500][1500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;
    queue<pair<int, int>> swan; // 오늘 백조
    queue<pair<int, int>> nswan; // 담날 백조
    queue<pair<int, int>> water; // 오늘 물
    queue<pair<int, int>> nwater; // 담날 물

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            // 백조 입력
            if (a[i][j] == 'L') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                }
                else {
                    ex = i;
                    ey = j;
                }
                a[i][j] = '.'; // 백조 있는 곳도 물이니까 . 으로 표시
            }
            // 물 큐에 삽입
            if (a[i][j] == '.') {
                water.push({i, j});
                wcheck[i][j] = true;
            }
        }
    }
    // 첫번째 백조 삽입
    swan.push({sx, sy});
    scheck[sx][sy] = true;

    // 물 녹는 거 BFS
    for (int i = 0; ; i++) {
        while(!water.empty()) {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            a[x][y] = '.';

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (wcheck[nx][ny]) continue;
                // 옆에도 물이면 큐에 삽입
                if (a[nx][ny] == '.') {
                    water.push({nx, ny});
                    wcheck[nx][ny] = true;
                }
                // 빙판이면 담날에 물로 변함. 담날 물 큐에 삽입
                else {
                    nwater.push({nx, ny});
                    wcheck[nx][ny] = true;
                }
            }
        }

        // 백조 이동하는 BFS
        while(!swan.empty()) {
            int x = swan.front().first;
            int y = swan.front().second;
            swan.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (scheck[nx][ny]) continue;
                // 백조 옆에 물이면 이동 가능
                if (a[nx][ny] == '.') {
                    swan.push({nx, ny});
                    scheck[nx][ny] = true;
                }
                // 백조 옆에 빙하면 담날 이동 가능. 담날 백조 큐에 삽입
                else {
                    nswan.push({nx, ny});
                    scheck[nx][ny] = true;
                }
            }
        }

        // 만났으면 출력
        if (scheck[ex][ey]) {
            cout << i << endl;
            break;
        }

        // 다음날 큐랑 바꿔주고
        water = nwater;
        swan = nswan;
        // 다음날 큐에는 새로운 큐 선언
        nwater = queue<pair<int, int>>();
        nswan = queue<pair<int, int>>();
    }

    return 0;
}
