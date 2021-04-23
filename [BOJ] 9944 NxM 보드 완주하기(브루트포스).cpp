#include <iostream>
using namespace std;

char a[33][33];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

bool inRange(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int go(int x, int y, int cnt) {
    int ans = -1;
    if (cnt == 0) return 0;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        while(inRange(nx, ny) && a[nx][ny] == '.') {
            a[nx][ny] = '#';
            cnt -= 1;
            nx += dx[k];
            ny += dy[k];
        }
        nx -= dx[k];
        ny -= dy[k];

        // 이동할 수 있는 경우 nx, ny 탐색
        if (!(x == nx && y == ny)) {
            int temp = go(nx, ny, cnt);
            if (temp != -1) {
                if (ans == -1 || ans > temp+1) {
                    ans = temp+1;
                }
            }
        }

        // 원상태로 복구
        while(!(x == nx && y == ny)) {
            a[nx][ny] = '.';
            cnt += 1;
            nx -= dx[k];
            ny -= dy[k];
        }
    }
    return ans;
}

int main() {
    int tc = 1;
    while(cin >> n >> m) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    cnt += 1; // 방문해야 하는 칸 갯수
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '.') {
                    a[i][j] = '#'; // 공이 있다
                    int temp = go(i, j, cnt - 1);
                    if (temp != -1) {
                        if (ans == -1 || ans > temp) {
                            ans = temp;
                        }
                    }
                    a[i][j] = '.';
                }
            }
        }
        cout << "Case " << tc << ": " << ans << endl;
        tc++;
    }

    return 0;
}
