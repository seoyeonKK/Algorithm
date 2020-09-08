#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool check[8][8][9];
int dx[] = {0, 0, 1, 1, 1, -1, -1 ,-1, 0};
int dy[] = {1, -1, 0, -1, 1, 0, -1 ,1, 0};
queue<tuple<int, int, int>> q;
vector<string> arr;
bool ans = false;

void bfs() {
    int x, y, t;
    while(!q.empty()) {
        tie(x, y, t) = q.front();
        q.pop();
        if (x == 0 && y == 7) {
            ans = true;
            break;
        }
        for (int k = 0; k < 9; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nt = min(t+1, 8); // 8초가 지난 후에는 8로 고정

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
                if (nx-t >= 0 && arr[nx-t][ny] == '#') continue; // 이동하려는 칸이 벽이면
                if (nx-t-1 >= 0 && arr[nx-t-1][ny] == '#') continue; // 이동하려는 칸이 1초 후 벽이면
                if (!check[nx][ny][nt]) {
                    check[nx][ny][nt] = true;
                    q.push({nx, ny, nt});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        arr.push_back(s);
    }

    check[7][0][0] = true;
    q.push({7, 0, 0});

    bfs();

    cout << (ans ? 1 : 0) << endl;

    return 0;
}
