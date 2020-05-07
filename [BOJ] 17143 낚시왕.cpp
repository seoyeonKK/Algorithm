#include <iostream>
#include <vector>
#define MAX 101
using namespace std;


struct Shark {
    int r, c;
    int speed, dir, size;
    Shark(){};
    Shark(int a, int b, int c, int d, int e) : r(a), c(b), speed(c), dir(d), size(e) {};
};

struct SharkMap {
    int idx;
    int speed, dir, size;
    SharkMap(){};
    SharkMap(int a, int b, int c, int d) : idx(a), speed(b), dir(c), size(d) {};
};

int R, C, M;
int answer = 0;

vector<Shark> shark;
SharkMap map[MAX][MAX] = {};
SharkMap copyMap[MAX][MAX] = {};
bool visited[MAX][MAX] = {false, };

void copySharkMap () {

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            copyMap[i][j] = { 0, 0, 0, 0 };
        }
    }

    for (int i = 0; i < shark.size(); i++) {
        int r = shark[i].r;
        int c = shark[i].c;
        int s = shark[i].speed;
        int d = shark[i].dir;
        int z = shark[i].size;

        if (visited[r][c]) {
            if (z > copyMap[r][c].size) {
                for (int j = 0; j < shark.size(); j++) {
                    if (copyMap[r][c].size == shark[j].size) {
                        shark.erase(shark.begin() + j);
                    }
                }
                i--;
            }
            else {
                for (int j = 0; j < shark.size(); j++) {
                    if (z == shark[j].size) {
                        shark.erase(shark.begin() + j);
                    }
                }
                i--;
                continue;
            }
        }
        copyMap[r][c] = { i, s, d, z };
        visited[r][c] = true;
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            map[i][j].idx = copyMap[i][j].idx;
            map[i][j].size = copyMap[i][j].size;
            map[i][j].dir = copyMap[i][j].dir;
            map[i][j].speed = copyMap[i][j].speed;
            visited[i][j] = false;
        }
    }
}

int verticalMove(int y, int &dir) {
    while (y < 1 || y > R) {
        if (y < 1) {
            y = 2 - y;
            dir = 2;
        }
        if (y > R) {
            y = R - (y - R);
            dir = 1;
        }
    }
    return y;
}

int horizontalMove(int x, int &dir) {
    while (x < 1 || x > C) {
        if (x < 1) {
            x = 2 - x;
            dir = 3;
        }
        if (x > C) {
            x = C - (x - C);
            dir = 4;
        }
    }
    return x;
}

void fishing(int idx) {
    for (int i = 1; i <= R; i++) {
        if (map[i][idx].dir > 0) {
            answer += map[i][idx].size;
            for (int j = 0; j < shark.size(); j++) {
                if (map[i][idx].size == shark[j].size) {
                    shark.erase(shark.begin() + j);
                }
            }
            map[i][idx] = { 0, 0, 0, 0 };
            break;
        }
    }
}

void move () {
    for (int i = 2; i <= C; i++) {
        for (int j = 0; j < shark.size(); j++) {
            if (shark[j].dir == 1) {
                int y;
                y = shark[j].r - shark[j].speed;
                shark[j].r = verticalMove(y, shark[j].dir);
            }
            else if (shark[j].dir == 2) {
                int y;
                y = shark[j].r + shark[j].speed;
                shark[j].r = verticalMove(y, shark[j].dir);
            }
            else if (shark[j].dir == 3) {
                int x;
                x = shark[j].c + shark[j].speed;
                shark[j].c = horizontalMove(x, shark[j].dir);
            }
            else if (shark[j].dir == 4) {
                int x;
                x = shark[j].c - shark[j].speed;
                shark[j].c = horizontalMove(x, shark[j].dir);
            }
        }
        copySharkMap();
        fishing(i);
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    if (M == 0) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        shark.push_back({ r, c, s, d, z });
    }

    copySharkMap();
    fishing(1);
    move();

    cout << answer;

    return 0;
}
