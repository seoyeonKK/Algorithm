#include <iostream>
#include <vector>
#define MAX 100
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
SharkMap map[MAX][MAX];
vector<Shark> shark;

int copySharkMap () {
    map[MAX][MAX] = {-1, -1, -1, -1 };

    for (int i = 0; i < shark.size(); i++) {
        int r = shark[i].r;
        int c = shark[i].c;
        int s = shark[i].speed;
        int d = shark[i].dir;
        int z = shark[i].size;

        if (map[r][c].idx != -1) {
            if (z > map[r][c].size) {
                shark.erase(shark.begin() + map[r][c].idx );
            }
            else {
                shark.erase(shark.begin() + i );
                continue;
            }
        }
        map[r][c] = { i, s, d, z };
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >>  s >> d >> z;

        shark.push_back({ r, c, s, d, z });
    }
}

