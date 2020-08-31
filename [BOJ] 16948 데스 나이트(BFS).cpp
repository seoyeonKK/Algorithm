#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int dist[200][200];

// 하나의 정점에서 이동을 하는 경우 BFS 풀
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    int r1, c1, r2, c2;
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    memset(dist, -1, sizeof(dist));
    dist[r1][c1] = 0;

    queue<pair<int,int>> q;
    q.push({r1, c1});
    bool flag = false;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (dist[nx][ny] == -1) { // 방문한 적이 없으면
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    if (nx == r2 && ny == c2) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (flag) break;
    }

    cout << dist[r2][c2] << endl;

    return 0;
}
