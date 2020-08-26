#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

int R, C;
char arr[MAX][MAX] = {};
bool alphaVisited[26] = { false, };
int dx[] = { 1, 0, 0, -1 }; // 동 북 남 서
int dy[] = { 0, 1, -1, 0 };
int maxValue;

void dfs(int x, int y, int max) {
    if (max > maxValue) maxValue = max;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !alphaVisited[arr[nx][ny] - 65]) {
            alphaVisited[arr[nx][ny] - 65] = true;
            dfs(nx, ny, max + 1);
            alphaVisited[arr[nx][ny] - 65] = false; // 백트래킹
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    maxValue = 1;
    alphaVisited[arr[0][0] - 65] = true;
    dfs(0, 0, maxValue);

    cout << maxValue << endl;
    
    return 0;
}
