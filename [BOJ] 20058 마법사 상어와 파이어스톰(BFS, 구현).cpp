#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int box_size;
int map[64][64];
int check[64][64];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans = 0;

void rotate(int cube) {
    for (int i = 0; i < box_size; i+=cube) {
        for (int j = 0; j < box_size; j+=cube) {
            int temp[64][64];
            for (int m = 0; m < cube; m++) {
                for (int n = 0; n < cube; n++) {
                    temp[n][cube-m-1] = map[i+m][j+n];
                }
            }
            for (int m = 0; m < cube; m++) {
                for (int n = 0; n < cube; n++) {
                    map[i+m][j+n] = temp[m][n];
                }
            }
        }
    }
}

void melt() {
    int temp[64][64];
    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            temp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            if (temp[i][j] <= 0) continue;
            int cnt = 0;
            if (i+1 < box_size && temp[i+1][j] > 0) cnt++;
            if (i-1 >= 0 && temp[i-1][j] > 0) cnt++;
            if (j+1 < box_size && temp[i][j+1] > 0) cnt++;
            if (j-1 >= 0 && temp[i][j-1] > 0) cnt++;

            if (cnt < 3) {
                map[i][j] -= 1;
            }
        }
    }
}

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    check[a][b] = true;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < box_size && ny < box_size) {
                if (map[nx][ny] > 0 && check[nx][ny] == false) {
                    q.push({nx, ny});
                    check[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int ice_size() {
    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            if (map[i][j] <= 0) continue;
            if (check[i][j] == true) continue;

            int result = bfs(i, j);
            ans = max(ans, result);
        }
    }
    return ans;
}

void print_box() {
    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main () {
    cin >> n >> m;

    box_size = pow(2, n);
    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            cin >> map[i][j];
        }
    }

    while(m--) {
        int x;
        cin >> x;
        int cube = pow(2, x);
        rotate(cube);
        melt();
    }
//    print_box();
    int ice = ice_size();
    int sum = 0;
    for (int i = 0; i < box_size; i++) {
        for (int j = 0; j < box_size; j++) {
            if (map[i][j] < 0) continue;
            sum += map[i][j];
        }
    }

    cout << sum << endl;
    cout << ice << endl;

    return 0;
}
