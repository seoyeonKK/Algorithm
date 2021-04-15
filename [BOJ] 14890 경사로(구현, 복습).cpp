#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int N, L;

bool go(vector<int> &a) {
    vector<bool> check(N, false);

    for (int i = 1; i < N; i++) {
        // 인접한 칸의 높이가 다르면, 경사로를 둔다.
        if (a[i-1] != a[i]) {
            int diff = a[i] - a[i-1];
            if (diff < 0) diff = -diff; // 절댓값으로 변환

            // 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
            if (diff != 1) {
                return false;
            }
            // 오른쪽이 더 높은 경우
            if (a[i-1] < a[i]) {
                for (int j = 1; j <= L; j++) {
                    // 경사로가 범위를 벗어나는 경우
                    if (i-j < 0) {
                        return false;
                    }
                    // 낮은 지점의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    if (a[i-1] != a[i-j]) {
                        return false;
                    }
                    // 경사로를 놓은 곳에 중복으로 놓는 경우
                    if (check[i-j]) {
                        return false;
                    }
                    check[i-j] = true;
                }
            }
            // 왼쪽이 더 높은 경우
            else {
                for (int j = 0; j < L; j++) {
                    // 경사로가 범위를 벗어나는 경우
                    if (i+j >= N) {
                        return false;
                    }
                    // 낮은 지점의 높이가 모두 같지 않거나, L개가 연속되지 않은 경우
                    if (a[i] != a[i+j]) {
                        return false;
                    }
                    // 경사로를 놓은 곳에 중복으로 놓는 경우
                    if (check[i+j]) {
                        return false;
                    }
                    check[i+j] = true;
                }
            }
        }
    }
    return true;
}


int main () {
    cin >> N >> L;
    vector<vector<int>> map(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        vector<int> row;
        for (int j = 0; j < N; j++) {
            row.push_back(map[i][j]);
        }
        if (go(row)) cnt += 1;
    }

    for (int j = 0; j < N; j++) {
        vector<int> column;
        for (int i = 0; i < N; i++) {
            column.push_back(map[i][j]);
        }
        if (go(column)) cnt += 1;
    }

    cout << cnt << endl;

    return 0;
}
