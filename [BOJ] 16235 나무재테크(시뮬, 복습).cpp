#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10][10]; // 추가되는 양분
int d[10][10]; // 이미 저장된 양분
int p[10][10]; // 추가된 나무 갯수
vector<int> tree[10][10];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int ans = 0;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            d[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x-1][y-1].push_back(age);
    }

    // K년 동안 시뮬레이션
    while(K--) {
        memset(p, 0, sizeof(p));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                vector<int> temp;
                sort(tree[i][j].begin(), tree[i][j].end()); // 한 칸에 여러 개의 나무가 있을 경우 어린애부터
                int dead = 0; // 나무가 죽으면 추가되는 양분
                for (int x : tree[i][j]) {
                    if (x <= d[i][j]) {
                        d[i][j] -= x;
                        temp.push_back(x + 1); // 나이 1 증가
                        if ((x + 1) % 5 == 0) {
                            for (int k = 0; k < 8; k++) {
                                int nx = i + dx[k];
                                int ny = j + dy[k];
                                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                                    p[nx][ny] += 1;
                                }
                            }
                        }
                    } else { // 자신의 나이보다 양분이 부족한 애들은 죽는다.
                        dead += x / 2;
                    }
                }
                tree[i][j] = temp;
                d[i][j] += dead; // 죽은 양분 추가
                d[i][j] += a[i][j]; // 겨울
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < p[i][j]; k++) {
                    tree[i][j].push_back(1);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += (int)tree[i][j].size();
        }
    }
    
    cout << ans << endl;
    return 0;
}
