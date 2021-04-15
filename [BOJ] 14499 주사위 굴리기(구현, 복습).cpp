#include <iostream>
#include <vector>
using namespace std;

// 동 서 북 남
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int map[20][20];
int dice[7] = {0,}; // 주사위에 적힌 수

/*
동쪽 = {1,2,3,4,5,6} -> {4,2,1,6,5,3}
서쪽 = {1,2,3,4,5,6} -> {3,2,6,1,5,4}
북쪽 = {1,2,3,4,5,6} -> {5,1,3,4,6,2}
남쪽 = {1,2,3,4,5,6} -> {2,6,3,4,1,5}
*/

int main () {
    int n, m, x, y, cnt;
    cin >> n >> m >> x >> y >> cnt;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    while(cnt--) {
        int cmd;
        cin >> cmd;
        cmd -= 1;

        int nx, ny;
        nx = x + dx[cmd];
        ny = y + dy[cmd];

        // 범위 나가면 무시
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        // 동쪽 이동
        if (cmd == 0) {
            int temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
        }
        // 서쪽 이동
        else if (cmd == 1) {
            int temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
        }
        // 북쪽 이동
        else if (cmd == 2) {
            int temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        }
        // 남쪽 이동
        else if (cmd == 3) {
            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
        }

        // 지도가 0이면 주사위 밑면으로 복사
        if (map[nx][ny] == 0) {
            map[nx][ny] = dice[5];
        }
        // 지도가 0이 아니면 주사위 밑면을 복사 
        else {
            dice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[0] << endl;

        x = nx;
        y = ny;
    }

    return 0;
}
