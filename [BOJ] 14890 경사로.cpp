#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

int N, L;
int map[MAX][MAX];
int visited[MAX][MAX];
int ans = 0;
bool flag = 0;

// 행
void row() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {

            flag = 0;

            // 내리막 길일 때
            if (1 == map[i][j] - map[i][j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i][j + k + 1] || (j + k + 1 >= N) || (map[i][j + k + 1] != map[i][j + 1])) {
                        flag = 1; // 경사로를 놓지 못합니다.
                        break;
                    }

                    // 경사로를 둡니다. 
                    visited[i][j + 1] = 1;
                    visited[i][j + k + 1] = 1;
                }
            }
            
            // 오르막 길일 때
            else if (-1 == map[i][j] - map[i][j + 1]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i][j - k] || (j - k < 0) || (map[i][j - k] != map[i][j])) {
                        flag = 1; // 경사로를 놓지 못합니다.
                        break;
                    }

                    // 경사로를 둡니다.
                    visited[i][j] = 1;
                    visited[i][j - k] = 1;
                }
            }
            
            // 경사가 2이상 차이날 때
            else if (map[i][j] != map[i][j + 1]) {
                flag = 1;
                break;
            }

            // 경사로를 두지 못하는 경우 for문 탈출
            if (flag) break;
        }

        // 한 행이 끝날 때마다 visited 초기화
        memset(visited[i], 0, sizeof(int) * N);

        // 경사로를 둔 경우 ans++
        if (!flag) ans++;
    }
}

// 열
void column() {

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N-1; i++) {

            flag = 0;

            // 내리막 길일 때
            if (1 == map[i][j] - map[i + 1][j]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i + k + 1][j] || (i + k + 1 >= N) || (map[i + k + 1][j] != map[i + 1][j])) {
                        flag = 1;
                        break;
                    }

                    // 경사로를 둡니다.
                    visited[i + 1][j] = 1;
                    visited[i + k + 1][j] = 1;
                }
            }
            
            // 오르막 길일 때
            else if (-1 == map[i][j] - map[i + 1][j]) {
                for (int k = 0; k < L; k++) {
                    if (visited[i - k][j] || (i - k < 0) || (map[i - k][j] != map[i][j])) {
                        flag = 1;
                        break;
                    }

                    // 경사로를 둡니다.
                    visited[i][j] = 1;
                    visited[i - k][j] = 1;
                }
            }
            
            // 경사가 2이상 차이날 때
            else if (map[i][j] != map[i + 1][j]) {
                flag = 1;
                break;
            }

            // 경사로를 두지 못하는 경우 for문 탈출
            if (flag) break;
        }

        // 한 열이 끝날 때마다 visited 초기화 (column이기 때문에 memset을 해당 방식으로 대체)
        for (int k = 0; k < N; k++) visited[k][j] = 0;

        // 경사로를 둔 경우 ans++
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
