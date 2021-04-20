#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 50
using namespace std;

int map[MAX][MAX];
int arrive[MAX][MAX];

void pipe(int n, int m, int x, int y, int dir, int time, queue<pair<int, int>> &q) {
    if (dir == 0) {
        if (x-1 >= 0 && arrive[x-1][y] == -1) {
            if (map[x-1][y] == 1 || map[x-1][y] == 2 || map[x-1][y] == 5 || map[x-1][y] == 6) {
                arrive[x - 1][y] = time;
                q.push({x - 1, y});
            }
        }
    }
    else if (dir == 1) {
        if (y+1 < m && arrive[x][y+1] == -1) {
            if (map[x][y+1] == 1 || map[x][y+1] == 3 || map[x][y+1] == 6 || map[x][y+1] == 7) {
                arrive[x][y + 1] = time;
                q.push({x, y + 1});
            }
        }
    }
    else if (dir == 2) {
        if (x+1 < n && arrive[x+1][y] == -1) {
            if (map[x+1][y] == 1 || map[x+1][y] == 2 || map[x+1][y] == 4 || map[x+1][y] == 7) {
                arrive[x + 1][y] = time;
                q.push({x + 1, y});
            }
        }
    }
    else if (dir == 3) {
        if (y-1 >= 0 && arrive[x][y-1] == -1) {
            if (map[x][y-1] == 1 || map[x][y-1] == 3 || map[x][y-1] == 4 || map[x][y-1] == 5) {
                arrive[x][y - 1] = time;
                q.push({x, y - 1});
            }
        }
    }
}


int main(int argc, char** argv) {
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case) {
        int n, m, r, c, l;
        memset(map, 0, sizeof(map));
        memset(arrive, -1, sizeof(arrive));

        cin >> n >> m >> r >> c >> l;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }

        queue<pair<int, int>> q;
        q.push({r, c});
        arrive[r][c] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (map[x][y] == 0 || arrive[x][y] == -1) continue;
            if (arrive[x][y] >= l) break;

            if (map[x][y] == 1) {
                pipe(n, m, x, y, 0, arrive[x][y]+1, q);
                pipe(n, m, x, y, 1, arrive[x][y]+1, q);
                pipe(n, m, x, y, 2, arrive[x][y]+1, q);
                pipe(n, m, x, y, 3, arrive[x][y]+1, q);
            }
            else if (map[x][y] == 2) {
                pipe(n, m, x, y, 0, arrive[x][y]+1, q);
                pipe(n, m, x, y, 2, arrive[x][y]+1, q);
            }
            else if (map[x][y] == 3) {
                pipe(n, m, x, y, 1, arrive[x][y]+1, q);
                pipe(n, m, x, y, 3, arrive[x][y]+1, q);
            }
            else if (map[x][y] == 4) {
                pipe(n, m, x, y, 0, arrive[x][y]+1, q);
                pipe(n, m, x, y, 1, arrive[x][y]+1, q);

            }
            else if (map[x][y] == 5) {
                pipe(n, m, x, y, 1, arrive[x][y]+1, q);
                pipe(n, m, x, y, 2, arrive[x][y]+1, q);

            }
            else if (map[x][y] == 6) {
                pipe(n, m, x, y, 2, arrive[x][y]+1, q);
                pipe(n, m, x, y, 3, arrive[x][y]+1, q);

            }
            else if (map[x][y] == 7) {
                pipe(n, m, x, y, 0, arrive[x][y]+1, q);
                pipe(n, m, x, y, 3, arrive[x][y]+1, q);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
//                cout << arrive[i][j] << " ";
                if (0 <= arrive[i][j] && arrive[i][j] <= l) {
                    cnt += 1;
                }
            }
//            cout << endl;
        }

        cout << "#" << test_case << " ";
        cout << cnt << endl;

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
