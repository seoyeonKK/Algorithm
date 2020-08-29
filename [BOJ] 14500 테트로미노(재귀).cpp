#include <iostream>
#include <vector>
using namespace std;

int N, M;
int arr[500][500];
int ans = 0;
bool check[500][500];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void go (int x, int y, int sum, int cnt) {
    if (cnt == 4) {
        if (ans < sum) ans = sum;
        return;
    }

    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (check[x][y]) return;
    check[x][y] = true;

    for (int i = 0; i < 4; i++) {
        go(x + dx[i], y + dy[i], sum + arr[x][y], cnt + 1);
    }
    check[x][y] = false;
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            go(i, j, 0, 0);
            if (j + 2 < M) {
                int temp = arr[i][j] + arr[i][j+1] + arr[i][j+2];
                if (i - 1 >= 0) {
                    int temp2 = temp + arr[i-1][j+1];
                    if (ans < temp2) ans = temp2;
                }
                if (i + 1 < N) {
                    int temp2 = temp + arr[i+1][j+1];
                    if (ans < temp2) ans = temp2;
                }
            }

            if (i + 2 < N) {
                int temp = arr[i][j] + arr[i+1][j] + arr[i+2][j];
                if (j - 1 >= 0) {
                    int temp2 = temp + arr[i+1][j-1];
                    if (ans < temp2) ans = temp2;
                }
                if (j + 1 < M) {
                    int temp2 = temp + arr[i+1][j+1];
                    if (ans < temp2) ans = temp2;
                }
            }

        }
    }

    cout << ans << endl;

    return 0;
}
