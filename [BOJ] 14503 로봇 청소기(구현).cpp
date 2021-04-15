#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int map[MAX][MAX];

int main () {
    int n, m;
    int x, y, d;
    cin >> n >> m;
    cin >> x >> y >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(1) {
        if (map[x][y] == 0) {
            // 1) 현재 위치 청소
            map[x][y] = -1;
        }
        // 2-3, 2-4) 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        if (map[x+1][y] != 0 && map[x-1][y] != 0 && map[x][y-1] != 0 && map[x][y+1] != 0) {
            if (map[x - dx[d]][y - dy[d]] == 1) break;
            else {
                // 2-3) 바라보는 방향을 유지한 채로 한 칸 후지하고 2번으로 돌아감.
                x -= dx[d];
                y -= dy[d];
            }
        }
        else {
            // 2-1) 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸 전진하고 1번으로 돌아감
            // 2-2) 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전 후 2번으로 돌아
            d = (d+3)%4;
            if (map[x+dx[d]][y+dy[d]] == 0) {
                x += dx[d];
                y += dy[d];
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == -1)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
