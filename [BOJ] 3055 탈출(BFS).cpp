#include <iostream>
#include <tuple>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int water[50][50];
int d[50][50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    vector<string> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    memset(water, -1, sizeof(water));
    queue<pair<int,int>> q;
    int sx, sy, ex, ey;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == '*') {
                q.push(make_pair(i,j));
                water[i][j] = 0;
            }
            else if (v[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            else if (v[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }

    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (water[nx][ny] != -1) continue;
            if (v[nx][ny] == 'X') continue;
            if (v[nx][ny] == 'D') continue;
            water[nx][ny] = water[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    memset(d,-1,sizeof(d));
    q.push(make_pair(sx,sy));
    d[sx][sy] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x,y) = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (d[nx][ny] != -1) continue;
            if (v[nx][ny] == 'X') continue;
            if (water[nx][ny] != -1 && d[x][y]+1 >= water[nx][ny]) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    if (d[ex][ey] == -1) {
        cout << "KAKTUS" << endl;
    }
    else {
        cout << d[ex][ey] << '\n';
    }
    return 0;
}
