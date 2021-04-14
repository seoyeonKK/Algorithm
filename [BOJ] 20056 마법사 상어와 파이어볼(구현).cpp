#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#define MAX 55
using namespace std;

struct Fireball {
    int r;
    int c;
    int mass;
    int speed;
    int dir;
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int t_dir[] = {0, 2, 4, 6};
int f_dir[] = {1, 3, 5, 7};

int n, m, k;
vector<Fireball> fireball;
vector<Fireball> arr[MAX][MAX];

void move() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j].clear();
        }
    }
    for (int i = 0; i < fireball.size(); i++) {
        int r = fireball[i].r;
        int c = fireball[i].c;
        int m = fireball[i].mass;
        int s = fireball[i].speed;
        int d = fireball[i].dir;
        int move = s % n;
        int nx = r + dx[d] * move;
        int ny = c + dy[d] * move;
        if (nx > n) nx -= n;
        if (ny > n) ny -= n;
        if (nx < 1) nx += n;
        if (ny < 1) ny += n;
        arr[nx][ny].push_back({nx, ny, m, s, d});
        fireball[i].r = nx;
        fireball[i].c = ny;
    }
}

void merge() {
    vector<Fireball> temp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j].size() == 0) continue;
            if (arr[i][j].size() == 1) {
                temp.push_back(arr[i][j][0]);
                continue;
            }

            int mass_sum = 0;
            int speed_sum = 0;
            int cnt = arr[i][j].size();
            bool even = true, odd = true;

            for (int k = 0; k < arr[i][j].size(); k++) {
                mass_sum += arr[i][j][k].mass;
                speed_sum += arr[i][j][k].speed;
                if (arr[i][j][k].dir%2 == 0) odd = false;
                else even = false;
            }

            int mass = mass_sum / 5;
            int speed = speed_sum / cnt;
            if (mass == 0) continue;
            if (even || odd) {
                for (int k = 0; k < 4; k++) {
                    temp.push_back({i, j, mass, speed, t_dir[k]});
                }
            }
            else {
                for (int k = 0; k < 4; k++) {
                    temp.push_back({i, j, mass, speed, f_dir[k]});
                }
            }
        }
    }
    fireball = temp;
}

int main () {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireball.push_back({r, c, m, s, d});
        arr[r][c].push_back({r, c, m, s, d});
    }

    for (int i = 0; i < k; i++) {
        move();
        merge();
    }

    int sum = 0;
    for (int i = 0; i < fireball.size(); i++) {
        sum += fireball[i].mass;
    }

    cout << sum << endl;

    return 0;
}
