#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int N, L;
int map[MAX][MAX];
int visited[MAX][MAX];
int ans = 0;
bool flag = 0;

void row() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {

            flag = 0;

            if (1 == map[i][j] - map[i][j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i][j + k + 1] || (j + k + 1 >= N) || (map[i][j + k + 1] != map[i][j + 1])) {
                        flag = 1;
                        break;
                    }

                    visited[i][j + 1] = 1;
                    visited[i][j + k + 1] = 1;
                }
            }
            else if (-1 == map[i][j] - map[i][j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i][j - k] || (j - k < 0) || (map[i][j - k] != map[i][j])) {
                        flag = 1;
                        break;
                    }

                    visited[i][j] = 1;
                    visited[i][j - k] = 1;
                }
            }
            else if (map[i][j] != map[i][j + 1]) {
                flag = 1;
                break;
            }

            if (flag) break;
        }

        memset(visited[i], 0, sizeof(int) * N);

        if (!flag) ans++;
    }
}

void column() {

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N-1; i++) {

            flag = 0;

            if (1 == map[i][j] - map[i + 1][j]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i + k + 1][j] || (i + k + 1 >= N) || (map[i + k + 1][j] != map[i + 1][j])) {
                        flag = 1;
                        break;
                    }

                    visited[i + 1][j] = 1;
                    visited[i + k + 1][j] = 1;
                }
            }
            else if (-1 == map[i][j] - map[i + 1][j]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i - k][j] || (i - k < 0) || (map[i - k][j] != map[i][j])) {
                        flag = 1;
                        break;
                    }

                    visited[i][j] = 1;
                    visited[i - k][j] = 1;
                }
            }
            else if (map[i][j] != map[i + 1][j]) {
                flag = 1;
                break;
            }

            if (flag) break;
        }

        for (int k = 0; k < N; k++) visited[k][j] = 0;

        if (!flag) ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    row();
    column();

    cout << ans << endl;

    return 0;
}
