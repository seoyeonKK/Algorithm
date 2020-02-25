#include <iostream>
#define MAX 50
using namespace std;

int N, M;
int X, Y, D;
int map[MAX][MAX] = {0, };
int visit[MAX][MAX] = {0, };
int result = 0;

// 북 동 남 서
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inRange(int nx, int ny) {
    return (nx >= 0 || ny >= 0 || nx < N || ny < M);
}

void cleaning(int x, int y, int d, int count) {
    int nx, ny, nd;

    while(1) {

        // 4번 다 회전한 경우
        if (count == 4) {
            nd = (d + 2) % 4;
            x += dx[nd];
            y += dy[nd];
            if (!inRange(x, y) || map[x][y] == 1) return;

            count = 0;
            continue;
        }

        d = (d + 3) % 4;
        nx = x + dx[d];
        ny = y + dy[d];

        // 청소할 수 있는 경우
        if (inRange(nx, ny) && map[nx][ny] == 0 && visit[nx][ny] == 0) {
            visit[nx][ny] = 1; // 현재 위치를 청소
            result++;
            x = nx;
            y = ny;
            count = 0;
        }
        else {
            count++;
        }

    }

}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> X >> Y >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    if (map[X][Y] == 0) {
        visit[X][Y] = 1;
        result++;
    }

    cleaning(X, Y, D, 0);

    cout << result;

    return 0;
}
