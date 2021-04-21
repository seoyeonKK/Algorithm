#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int check[100][100];
int n;
bool can(bool blind, char from, char to) {
    // 같으면 이동
    if (from == to) return true;
    // 적록색약이면 이동
    if (blind) {
        if (from == 'R' && to == 'G') return true;
        if (from == 'G' && to == 'R') return true;
    }
    return false;
}

int go(vector<string> &map, bool blind = false) {
    int ans = 0;
    memset(check, false, sizeof(check)); // 꼭 여기서 초기화! (일반인, blind 경우 모두를 구해야 하기 때문)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == false) {
                ans += 1; // 새로운 영역
                queue<pair<int, int>> q;
                q.push({i, j});
                check[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                            if (check[nx][ny]) continue;
                            if (can(blind, map[x][y], map[nx][ny])) {
                                check[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    vector<string> map(n);
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    cout << go(map) << " " << go(map, true) << endl;

    return 0;
}
