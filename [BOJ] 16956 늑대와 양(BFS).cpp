#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
string map[500];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    bool isSheep = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'S') {
                // S 상하좌우에 늑대가 있다면 0 출력
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // 범위 체크
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    // 늑대가 있음
                    if (map[nx][ny] == 'W')
                        isSheep = true;
                }
            }
        }
    if (isSheep)
        cout << 0 << endl;
    else {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'S') {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        // 범위 체크
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        // 울타리 설치
                        if (map[nx][ny] == '.')
                            map[nx][ny] = 'D';
                    }
                }
            }

        for (int i = 0; i < n; ++i)
            cout << map[i] << endl;
    }
    
    return 0;
}
