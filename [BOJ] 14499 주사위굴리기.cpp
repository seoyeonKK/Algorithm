#include <iostream>
#include <queue>
#define MAX_SIZE 21
using namespace std;

int N, M, K;
int x, y;
int map[MAX_SIZE][MAX_SIZE];
int dice[7] = {0, };

// 동 서 북 남
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void change_dice(int idx){
    int tmp_dice[7];

    for(int i = 1; i <= 6; i++){
        tmp_dice[i] = dice[i];
    }

    if(idx == 1){ // 동
        dice[1] = tmp_dice[6];
        dice[3] = tmp_dice[5];
        dice[5] = tmp_dice[1];
        dice[6] = tmp_dice[3];
    }
    else if(idx == 2){ // 서
        dice[1] = tmp_dice[5];
        dice[3] = tmp_dice[6];
        dice[5] = tmp_dice[3];
        dice[6] = tmp_dice[1];
    }
    else if(idx == 3){ // 북
        dice[1] = tmp_dice[2];
        dice[2] = tmp_dice[3];
        dice[3] = tmp_dice[4];
        dice[4] = tmp_dice[1];
    }
    else { // 남
        dice[1] = tmp_dice[4];
        dice[2] = tmp_dice[1];
        dice[3] = tmp_dice[2];
        dice[4] = tmp_dice[3];
    }
}

void copy_dice(int x, int y, int idx) {
    if(map[x][y] == 0)
        map[x][y] = dice[idx];
    else{
        dice[idx] = map[x][y];
        map[x][y] = 0;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int k;

        /*
         * 1 : 동쪽
         * 2 : 서쪽
         * 3 : 북쪽
         * 4 : 남쪽
         */
        cin >> k;

        x += dx[k];
        y += dy[k];

        if(x < 0 || x >= N || y < 0 || y >= M) {
            x -= dx[k];
            y -= dy[k];
            continue;
        }

        /*
         * 주사위 Index
         * 위 : 1
         * 앞 : 2
         * 바닥 : 3
         * 뒤 : 4
         * 오른쪽 : 5
         * 왼쪽 : 6
         */
        if(k == 1){ // 바뀌는 면 : 오른쪽
            copy_dice(x, y, 5);
        }
        else if (k == 2){ // 바뀌는 면 : 왼쪽
            copy_dice(x, y, 6);
        }
        else if (k == 3){ // 바뀌는 면 : 뒤
            copy_dice(x, y, 4);
        }
        else if (k == 4){ // 바뀌는 면 : 앞
            copy_dice(x, y, 2);
        }

        change_dice(k);

        cout << dice[1] << endl;
    }

    return 0;
}
