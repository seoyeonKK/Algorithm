#include <iostream>
#include <vector>
using namespace std;

int N, M;
string arr[20];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inRange(int x, int y) {
    return !(x < 0 || x >= N || y < 0 || y >= M); // 범위 내에 있으면 true, 없으면 false 리턴
}

int move (int cnt, int x1, int y1, int x2, int y2) {
    if (cnt == 11) return -1;
    if (!inRange(x1, y1) && !inRange(x2, y2)) return -1;
    if (!inRange(x1, y1) || !inRange(x2, y2)) return cnt;

    int ans = -1; // 가능하지않다면 -1을 출력해야되기 때문에 -1로 초기화

    for (int i = 0; i < 4; i++) {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];

        if (inRange(nx1, ny1) && arr[nx1][ny1] == '#') {
            nx1 = x1;
            ny1 = y1;
        }
        if (inRange(nx2, ny2) && arr[nx2][ny2] == '#') {
            nx2 = x2;
            ny2 = y2;
        }

        int temp = move(cnt+1, nx1, ny1, nx2, ny2);
        if (temp == -1) continue;
        if (ans == -1 || ans > temp) { // 1) 처음 temp값을 업데이트할 때, 2) ans보다 최솟값일 때 
            ans = temp;
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int x1, x2, y1, y2;
    x1 = x2 = y1 = y2 = -1;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'o') {
                if (x1 == -1) {
                    x1 = i;
                    y1 = j;
                }
                else {
                    x2 = i;
                    y2 = j;
                }
                arr[i][j] = '.';
            }
        }
    }

    cout << move(0, x1, y1, x2, y2) << endl;

    return 0;
}
