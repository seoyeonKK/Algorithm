#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];
int main() {
    cin >> N;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    memset(dist, -1, sizeof(dist));

    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while(!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (dist[nx][ny] == -1) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }

    cout << dist[ex][ey] << endl;

    return 0;
}
