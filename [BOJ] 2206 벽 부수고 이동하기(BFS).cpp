#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int dist[1001][1001][2];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = s[j-1] - '0'; // char to int
        }
    }

    queue<tuple<int, int, int>> q;
    dist[1][1][0] = 1;
    q.push({1, 1, 0});

    while(!q.empty()) {
        int x, y, z; // x : row, y : col, z : 벽을 부순 횟수
        tie(x, y, z) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx > 0 && nx <= N && ny > 0 && ny <= M) {
                // 빈칸인 경우
                if (arr[nx][ny] == 0 && dist[nx][ny][z] == 0) {
                    dist[nx][ny][z] = dist[x][y][z] + 1;
                    q.push({nx, ny, z});
                }
                // 벽인 경우
                if (z == 0 && arr[nx][ny] == 1 && dist[nx][ny][z+1] == 0) {
                    dist[nx][ny][z+1] = dist[x][y][z] + 1;
                    q.push({nx, ny, z+1});
                }
            }
        }
    }

    // 1) 벽을 부수지 않고 가보고, 2) 벽을 부숴서도 가봤다면 둘 중에 작은 값을 출력
    if (dist[N][M][0] != 0 && dist[N][M][1] != 0) {
        cout << min(dist[N][M][0], dist[N][M][1]);
    }
    // 벽을 부수지 않고만 가봤다면
    else if (dist[N][M][0] != 0) {
        cout << dist[N][M][0] << endl;
    }
    // 벽을 부수고만 가봤다면
    else if (dist[N][M][1] != 0) {
        cout << dist[N][M][1];
    }
    // 방법이 없으면
    else {
        cout << -1 << endl;
    }
}
