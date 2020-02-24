#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[8][8];
int copyMap[8][8];
int result = 0;
vector<pair<int, int>> position;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS() {
    queue <pair <int, int>> que;

    for (int i = 0; i < position.size(); i++)
        que.push({ position[i].first, position[i].second });

    while (!que.empty()) {

        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (copyMap[nx][ny] == 0) {
                copyMap[nx][ny] = 2;
                que.push({ nx, ny });
            }
        }
    }

    int size = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (copyMap[i][j] == 0) size++;

    result = max(size, result);

    return result;
}

int wall(int cnt) {
    if (cnt >= 3) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                copyMap[i][j] = map[i][j];

        return BFS();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                wall(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 2) {
                position.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                wall(1);
                map[i][j] = 0;
            }
        }
    }

    cout << result;

    return 0;
}
