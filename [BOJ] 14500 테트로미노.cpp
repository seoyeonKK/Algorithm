#include <iostream>
#include <algorithm>
#define MAX_SIZE 500
using namespace std;

int N, M;
int map[MAX_SIZE][MAX_SIZE] = {0, };
bool visited[MAX_SIZE][MAX_SIZE] = {0, };
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int MAX;

bool inRange(int x, int y) {
    if (x < 0 || x >= N || y < 0  || y >= M)
        return false;
    else
        return true;
}

void move(int x, int y, int count, int sum) {

    if (count == 4) {
        MAX = max(MAX, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inRange(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            move(nx, ny, count+1,  sum + map[nx][ny]);
            visited[nx][ny] = 0;
        }
    }

}

void specialShape(int x, int y) {
    for (int i = 0; i < 4; i++){
        int sum = map[x][y];
        bool flag = true;

        for (int j = 0; j < 3; j++) {
            int nx = x + dx[(i+j) % 4];
            int ny = y + dy[(i+j) % 4];

            if (inRange(nx, ny)) {
                sum += map[nx][ny];
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            MAX = max(MAX, sum);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N*M; i++) {
        int x = i / N;
        int y = i % M;

        visited[x][y] = 1;

        move(x, y, 1, map[x][y]);
        specialShape(x, y);

        visited[x][y] = 0;

    }

    cout << MAX;

    return 0;
}
