#include <iostream>
#include <queue>
using namespace std;

int n, m;
string a[250];
bool check[250][250];
int d[250*250][2]; // 각 영역에 양과 늑대가 몇 마리 있는지
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void bfs(int sx, int sy, int cnt) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 양 or 늑대이면 갯수증가 시키기
        if (a[x][y] == 'v') {
            d[cnt][0] += 1;
        }
        else if (a[x][y] == 'o') {
            d[cnt][1] += 1;
        }

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 체크
            if (a[nx][ny] == '#') continue;  // 벽이면 이동X
            if (check[nx][ny]) continue; // 이미 방문했으면 이동X

            q.push({nx, ny});
            check[nx][ny] = true;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = 0; // 영역 번호
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#' && check[i][j] == false) {
                cnt += 1; // 영역 번호 증가
                bfs(i, j, cnt); // bfs탐색 시작
            }
        }
    }
    int v = 0;
    int o = 0;
    for (int i = 1; i <= cnt; i++) {
        if (d[i][0] >= d[i][1]) {
            v += d[i][0];
        }
        else {
            o += d[i][1];
        }
    }

    cout << o << " " << v << endl;
    return 0;
}
