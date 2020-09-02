#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10][10];
int copy_arr[10][10];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (copy_arr[nx][ny] == 0) {
                copy_arr[nx][ny] = 2;
                dfs(nx, ny);
            }
        }
    }
}

int go() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copy_arr[i][j] = arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copy_arr[i][j] == 2) {
                dfs(i, j);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copy_arr[i][j] == 0) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for(int x1 = 0; x1  < N; x1++) {
        for (int y1 = 0; y1 < M; y1++) {
            if (arr[x1][y1] != 0) continue;
            for (int x2 = 0; x2 < N; x2++) {
                for (int y2 = 0; y2 < M; y2++) {
                    if (arr[x2][y2] != 0) continue;
                    for (int x3 = 0; x3 < N; x3++) {
                        for (int y3 = 0; y3 < M; y3++) {
                            if (arr[x3][y3] != 0) continue;
                            if (x1 == x2 && y1 == y2) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            if (x3 == x1 && y3 == y1) continue;
                            arr[x1][y1] = 1;
                            arr[x2][y2] = 1;
                            arr[x3][y3] = 1;
                            int cur = go();
                            if (cur > ans) ans = cur;
                            arr[x1][y1] = 0;
                            arr[x2][y2] = 0;
                            arr[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
