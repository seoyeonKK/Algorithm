#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;

    int sx, sy, ex, ey;
    sx = sy = ex = ey = -1;

    vector<string> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'C') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                }
                else {
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    int x, y;
    queue<pair<int, int>> q;
    vector<vector<int>> d(N, vector<int> (M, -1));
    d[sx][sy] = 0;
    q.push({sx, sy});
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            while(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (arr[nx][ny] == '*') break;
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
                nx = nx + dx[k];
                ny = ny + dy[k];
            }
        }
    }

    cout << d[ex][ey]-1 << endl; // 거울 갯수 = 선분 갯수 - 1

    return 0;
}
