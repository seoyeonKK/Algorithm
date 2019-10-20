#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Cell {

    int x;
    int y;
    int time;
    Cell(int a, int b, int c) : x(a), y(b), time(c) {};
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int map[700][700];
int ans = 0;
int n, m, k;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        memset(map,0,sizeof(map));
        ans = 0;

        cin >> n >> m >> k;

        queue<Cell> q[11];

        for(int i=350; i<n+350; i++){
            for(int j=350; j<m+350; j++){
                cin >> map[i][j];
                if(map[i][j])
                    q[ map[i][j] ].push( Cell(i, j, map[i][j]*2) );
            }
        }

        while(k--) {
            for (int i = 10; i >= 1; i--) {
                int size = (int) q[i].size();

                for (int j = 0; j < size; j++) {
                    int x = q[i].front().x;
                    int y = q[i].front().y;
                    int time = q[i].front().time;
                    q[i].pop();

                    time--;

                    if (map[x][y] > time) { // 활성화 상태가 되면
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (map[nx][ny] == 0) {
                                map[nx][ny] = map[x][y];
                                q[i].push(Cell(nx, ny, map[nx][ny] * 2));
                            }
                        } // end of for k
                    } // end of if

                    if (time > 0) { // 죽지 않았다면
                        q[i].push(Cell(x, y, time));
                    }
                }
            }
        }

        for(int i=1; i<11; i++) {
            ans += q[i].size();
        }
        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}
