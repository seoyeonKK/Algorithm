#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <cstring>
using namespace std;

int a[1000][1000];
int check[1000][1000];
int group[1000][1000];
vector<int> group_size;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;

void bfs(int sx, int sy) {
    int g = group_size.size(); // 새로운 그룹 생길 때마다 사이즈 증가
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    group[sx][sy] = g;
    int cnt = 1;
    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (a[nx][ny] == 0 && !check[nx][ny]) {
                    q.push({nx, ny});
                    check[nx][ny] = true;
                    group[nx][ny] = g;
                    cnt += 1;
                }
            }
        }
    }
    group_size.push_back(cnt);
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            a[i][j] = s[j] - '0'; // char to int
            check[i][j] = false;
            group[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0 && !check[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == 0) {
                cout << 0;
            }
            else {
                set<int> near;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < N && y >= 0 && y < M) {
                        if (a[x][y] == 0) {
                            near.insert(group[x][y]);
                        }
                    }
                }
                int ans = 1;
                for (int g : near) {
                    ans += group_size[g];
                }
                cout << ans%10;
            }
        }
        cout << endl;
    }

    return 0;
}
