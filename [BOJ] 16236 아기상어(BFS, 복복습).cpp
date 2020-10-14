#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

tuple<int, int, int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int, int, int>> ans;
    vector<vector<int>> dist(n, vector<int> (n, -1));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0; // 시작점 거리 0


    while(!q.empty()) {
        tie(x, y) = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1) {
                bool ok = false;
                bool eat = false;

                if (a[nx][ny] == 0) {
                    ok = true;
                }
                else if (a[nx][ny] < size) {
                    ok = eat = true;
                }
                else if (a[nx][ny] == size) {
                    ok = true;
                }

                if (ok) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }

                if (eat) {
                    ans.push_back({dist[nx][ny], nx, ny});
                }
            }
        }
    }
    if (ans.empty()) {
        return {-1, -1, -1};
    }
    
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    int N;
    int x, y;
    cin >> N;
    vector<vector<int>> a(N, vector<int> (N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];

            if (a[i][j] == 9) {
                x = i;
                y = j;
                a[i][j] = 0;
            }
        }
    }

    int ans = 0;
    int size = 2;
    int exp = 0;

    while(1) {
        int nx, ny, dist;
        tie(dist, nx, ny) = bfs(a, x, y, size);
        if (dist == -1) break;

        a[nx][ny] = 0; // 먹었으면 물고기 없어짐
        ans += dist;
        exp += 1;

        if (exp == size) {
            exp = 0;
            size += 1;
        }

        tie(x, y) = {nx, ny}; // 상어 이동

    }
    
    cout << ans << endl;
    
    return 0;
}
