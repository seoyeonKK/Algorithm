#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, L, R;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool bfs(vector<vector<int> > &a, int L, int R) {
    int n = a.size();
    vector<vector<bool>> check(N, vector<bool> (N, false)); // 방문 여부
    bool ok = false; // 인구이동 발생 체크

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!check[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j}); // 방문
                check[i][j] = true;

                queue<pair<int, int>> visit;
                visit.push({i, j}); // 방문 기록 -> q는 pop해서 없기 떄문에 따로 이중기록.
                int sum = a[i][j]; // 인구의 합

                while(!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            if (check[nx][ny]) continue;

                            int diff = a[x][y] - a[nx][ny];
                            if (diff < 0) diff = -diff;

                            if (L <= diff && R >= diff) {
                                q.push({nx, ny});
                                visit.push({nx, ny});
                                check[nx][ny] = true;
                                ok = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int val = sum / visit.size();
                while(!visit.empty()) {
                    int x, y;
                    tie(x, y) = visit.front();
                    visit.pop();
                    a[x][y] = val;
                }
            }
        }
    }
    return ok;
}

int main() {
    cin >> N >> L >> R;
    vector<vector<int>> a(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    while(1) {
        if (bfs(a, L, R)) {  // 인구 이동이 발생했으면
            ans += 1;
        }
        else
            break;
    }

    cout << ans << endl;

    return 0;
}
