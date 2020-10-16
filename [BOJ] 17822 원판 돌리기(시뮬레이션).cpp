#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

int n, m, t;

// 반시계방향 회전
void rotate(vector<int> &a) {
    int temp = a[0];
    for (int i = 1; i < m; i++) {
        a[i-1] = a[i];
    }
    a[m-1] = temp;
}

int main() {
    cin >> n >> m >> t;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int sum, cnt;
    for (int i = 0; i < t; i++) {
        int x, d, k;
        int r = 1;
        cin >> x >> d >> k;
        if (d == 0) r = m-1;

        for (int j = x; j <= n; j += x) {
            for (int l = 0; l < r * (k % m); l++) {
                rotate(a[j - 1]);
            }
        }

        vector<vector<int>> copy(a);
        bool flag = false;

        // 열 비교
        for (int j = 0; j < n; j++) {
            if (a[j][0] != 0 && (a[j][0] == a[j][m-1])) {
                copy[j][0] = 0;
                copy[j][m-1] = 0;
                flag = true;
            }
            for (int l = 1; l < m; l++) {
                if (a[j][l] != 0 && (a[j][l] == a[j][l-1])) {
                    copy[j][l] = 0;
                    copy[j][l-1] = 0;
                    flag = true;
                }
            }
        }

        // 행 비교
        for (int l = 0; l < m; l++) {
            for (int j = 1; j < n; j++) {
                if (a[j][l] != 0 && (a[j][l] == a[j-1][l])) {
                    copy[j][l] = 0;
                    copy[j-1][l] = 0;
                    flag = true;
                }
            }
        }
        a = copy;
        sum = 0;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < m; l++) {
                if (a[j][l] > 0) {
                    cnt++;
                }
                sum += a[j][l];
            }
        }
        if (!flag) {
            double avg = (double)sum / (double)(cnt);
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < m; l++) {
                    if (a[j][l] == 0) continue;
                    if (a[j][l] > avg) {
                        a[j][l] -= 1;
                    }
                    else if (a[j][l] < avg) {
                        a[j][l] += 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += a[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}
