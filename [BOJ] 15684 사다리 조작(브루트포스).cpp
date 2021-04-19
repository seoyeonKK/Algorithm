#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int garo[100][100];
int w, m, h;

// 사다리 타기 함수(출구 column을 반환)
int start(int c) {
    int r = 1;
    while(r <= h) {
        // 가로선이 시작되는 경우
        if (garo[r][c] == 1) {
            // 우측으로 이동
            c += 1;
        }
        // 가로선이 끝나는 경우
        else if (garo[r][c] == 2) {
            // 좌측으로 이동
            c -= 1;
        }
        r += 1;
    }
    return c;
}

// i번째 결과가 i인지 확인하는 함수
bool go() {
    for (int i = 1; i <= w; i++) {
        int res = start(i);
        if (res != i) return false; // i번째가 i로 끝나지 않는 경우
    }
    return true; // i번째가 i로 끝나는 경우
}

int main() {
    cin >> w >> m >> h;
    while (m--) {
        int x, y;
        cin >> x >> y;
        garo[x][y] = 1;
        garo[x][y+1] = 2;
    }

    // 가로선을 둘 수 있는 후보가 되는 위치
    vector<pair<int, int>> a;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w-1; j++) {
            if (garo[i][j] != 0) continue;
            if (garo[i][j+1] != 0) continue;
            a.push_back({i, j});
        }
    }

    // 사다리를 추가 안해도 되는 경우 return 0
    int ans = -1;
    if (go()) {
        cout << 0 << endl;
        return 0;
    }

    int len = a.size();

    // 1번째 가로선 추가하기
    for (int i = 0; i < len; i++) {
        int x1 = a[i].first;
        int y1 = a[i].second;
        if (garo[x1][y1] != 0 || garo[x1][y1+1] != 0) continue;
        garo[x1][y1] = 1;
        garo[x1][y1+1] = 2;
        if (go()) {
            if (ans == -1 || ans > 1) {
                ans = 1;
            }
        }
        // 2번째 가로선 추가하기
        for (int j = i+1; j < len; j++) {
            int x2 = a[j].first;
            int y2 = a[j].second;
            if (garo[x2][y2] != 0 || garo[x2][y2+1] != 0) continue;
            garo[x2][y2] = 1;
            garo[x2][y2+1] = 2;
            if (go()) {
                if (ans == -1 || ans > 2) {
                    ans = 2;
                }
            }
            // 3번째 가로선 추가하기
            for (int k = j+1; k < len; k++) {
                int x3 = a[k].first;
                int y3 = a[k].second;
                if (garo[x3][y3] != 0 || garo[x3][y3+1] != 0) continue;
                garo[x3][y3] = 1;
                garo[x3][y3+1] = 2;
                if (go()) {
                    if (ans == -1 || ans > 3) {
                        ans = 3;
                    }
                }
                // 3번째 가로선 지우기
                garo[x3][y3] = 0;
                garo[x3][y3+1] = 0;
            }
            // 2번째 가로선 지우기
            garo[x2][y2] = 0;
            garo[x2][y2+1] = 0;
        }
        // 1번째 가로선 지우기
        garo[x1][y1] = 0;
        garo[x1][y1+1] = 0;
    }

    cout << ans << endl;

    return 0;
}
