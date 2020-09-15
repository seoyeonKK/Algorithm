#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {0,0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool can(bool blind, int from, int to) {
    if (from == to) return true;
    if (blind) {
        if (from == 'R' && to == 'G') return true;
        if (from == 'G' && to == 'R') return true;
    }
    return false;
}

int go(vector<string> &v, bool blind = false) {
    int n = v.size();
    vector<vector<bool>> check(n, vector<bool>(n, false));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!check[i][j]) { // 다른 영역일 때
                ans += 1;
                check[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (check[nx][ny]) continue;
                            if (can(blind, v[x][y], v[nx][ny])) { // 같은 영역
                                check[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << go(v) << " " << go(v, true) << endl; // 적록색약 아닐 때, 적록색약 일 때 
    return 0;
}
