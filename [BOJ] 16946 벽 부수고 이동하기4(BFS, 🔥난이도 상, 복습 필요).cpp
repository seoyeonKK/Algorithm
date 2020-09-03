#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
bool check[1001][1001];
int group[1001][1001];
vector<int> group_size;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int sx, int sy) {
    int g = group_size.size();
    queue<pair<int,int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    group[sx][sy] = g;
    int cnt = 1;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
                if (arr[nx][ny] == 0 && !check[nx][ny]) {
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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = s[j-1] - '0'; // char to int
            check[i][j] = false;
            group[i][j] = -1;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0 && !check[i][j]) {
                bfs(i, j);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 0) {
                cout << 0;
            }
            else {
                set<int> near;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x > 0 && x <= N && y > 0 && y <= M) {
                        if (arr[x][y] == 0) {
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
}

