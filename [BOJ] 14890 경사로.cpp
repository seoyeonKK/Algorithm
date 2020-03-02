#include <iostream>
#define MAX 100
using namespace std;

int N, L;
int map[MAX][MAX];
int visit[MAX][MAX];
int ans = 0;

void construct() {
    bool flag = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            flag = 0;
            if (!visit[i][j]) {
                if (1 == map[i][j] - map[i][j+1]) {
                    for (int k = 1; k < L; k++) {
                        if (visit[i][j + k + 1] || (j + k + 1>= N) || (map[i][j + k + 1] != map[i][j + 1])) {
                            flag = 1;
                            break;
                        }

                        visit[i][j + 1] = 1;
                        visit[i][j + k + 1] = 1;
                    }
                }
                else if (-1 == map[i][j] - map[i][j+1]) {
                    for (int k = 1; k < L; k++) {
                        if (visit[i][j - k] || (j - k < 0) || (map[i][j - k] != map[i][j])) {
                            flag = 1;
                            break;
                        }

                        visit[i][j] = 1;
                        visit[i][j - k] = 1;
                    }
                }

                if (flag == 1) {
                    memset(visit[i], 0, sizeof(int)*N);
                    break;
                }
            }
            else {
                memset(visit[i], 0, sizeof(int)*N);
                break;
            }
        }
        if (flag == 0) {
            ans++;
        }
    }

    cout << "========" << endl;

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            flag = 0;

            if (!visit[i][j]) {
                if (1 == map[i][j] - map[i + 1][j]) {
                    for (int k = 1; k < L; k++) {
                        if (visit[i + k + 1][j] || (i + k + 1 >= N) || (map[i + k + 1][j] != map[i + 1][j])) {
                            flag = 1;
                            break;
                        }

                        visit[i + 1][j] = 1;
                        visit[i + k + 1][j] = 1;
                    }
                }
                else if (-1 == map[i][j] - map[i + 1][j]) {

                    for (int k = 1; k < L; k++) {
                        if (visit[i - k][j] || (i - k < 0) || (map[i - k][j] != map[i][j])) {
                            flag = 1;
                            break;
                        }

                        visit[i][j] = 1;
                        visit[i - k][j] = 1;
                    }
                }

                if (flag == 1) {
                    for (int k = 0; k < N; k++) visit[k][j] = 0;
                    break;
                }
            }
            else {
                for (int k = 0; k < N; k++) visit[k][j] = 0;
                break;
            }
        }

        if (flag == 0) {
            cout << j << endl;
            ans++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    construct();

    cout << ans;

    return 0;
}
