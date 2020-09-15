#include <iostream>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

tuple<int, int, int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int,int,int>> ans;
    vector<vector<int>> d(n, vector<int> (n, -1));
    queue<pair<int,int>> q;
    q.push({x, y});
    d[x][y] = 0;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && d[nx][ny] == -1) {
                bool ok = false;
                bool eat = false;

                if (a[nx][ny] == 0) {
                    ok = true;
                }
                else if (size == a[nx][ny]) {
                    ok = true;
                }
                else if (size > a[nx][ny]) {
                    ok = true;
                    eat = true;
                }

                if (ok) {
                    q.push({nx, ny});
                    d[nx][ny] = d[x][y] + 1;
                    if (eat) {
                        ans.push_back({d[nx][ny], nx, ny}); // 거리, x좌표, y좌표
                    }
                }
            }
        }
    }
    if (ans.empty()) return {-1, -1, -1};

    sort(ans.begin(), ans.end());
    return ans[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));
    int sx, sy; // 상어

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 9) {
                sx = i;
                sy = j;
                arr[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int size = 2; // 상어 크기
    int exp = 0; // 상어 능력치

    while(1) {
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(arr, sx, sy, size);

        if (dist == -1) break;
        arr[nx][ny] = 0;
        ans += dist;
        exp += 1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        sx = nx;
        sy = ny;
    }
    
    cout << ans << endl;

    return 0;
}
