#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[1001][1001];

bool dfs(int x, int y) {
    // 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x < 0 || x >= n || y < 0 || y >= m) return false;

    // 현재 노드를 아직 방문하지 않았다면(빈 곳이라면)
    if (map[x][y] == 0) {
        // 해당 노드 방문 처리
        map[x][y] = 1;
        // 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
        dfs(x-1, y);
        dfs(x, y-1);
        dfs(x+1, y);
        dfs(x, y+1);
        return true;
    }
    return false;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    // 모든 노드에 대하여 음료수 채우기
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j)) {
                result++;
            }
        }
    }

    cout << result << endl;

    return 0;
}
