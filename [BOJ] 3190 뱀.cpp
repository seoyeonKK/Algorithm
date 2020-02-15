#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

struct Snake {
    int x;
    int y;
    int direct;
    Snake(int a, int b, int c) : x(a), y(b), direct(c) {};
};

int map[MAX][MAX] = {-1, };
int visit[MAX][MAX] = {0, };
int N, K, L;
int timer = 1;
queue<pair<int, char>> rotation;
queue<Snake> q;

int move() {
    int s;
    char d;
    int nx = 1;
    int ny = 1;

    while (1) {
        Snake snake = q.front();

        s = rotation.front().first;
        d = rotation.front().second;

        // 매초 이동
        if (snake.direct == 0) {
            nx++;
        } else if (snake.direct == 1) {
            ny++;
        } else if (snake.direct == 2) {
            nx--;
        } else if (snake.direct == 3) {
            ny--;
        }

        if (nx > N || nx < 1 || ny > N || ny < 1) break;
        if (visit[nx][ny] == 1) break;

        if (map[nx][ny] == 0) {
            visit[snake.x][snake.y] = 0;
            q.pop();
        }

        visit[nx][ny] = 1;

        // s초이면 방향 전환
        if (timer == s) {
            rotation.pop();
            if (d == 'D') {
                q.push(Snake(nx, ny, (snake.direct + 1) % 4));
            } else if (d == 'L') {
                q.push(Snake(nx, ny, (snake.direct + 3) % 4));
            }
        }
        else {
            q.push(Snake(nx, ny, snake.direct));
        }

        timer++;
    }

    return timer;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);


    /*
     * Input
     */
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int ax, ay;
        cin >> ax >> ay;
        map[ax][ay] = 1; // 사과 위치 = 1
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int seconds;
        char direction;
        cin >> seconds >> direction;
        rotation.push({seconds, direction});
    }

    q.push( Snake(1, 1, 0) );

    cout << move() << endl;

    return 0;
}
