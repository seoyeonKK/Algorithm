#include <iostream>
using namespace std;

bool a[201][201];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = true;
    }

    int ans = 0;
    // 조합 고르기
    for (int i = 1; i <= n-2; i++) {
        for (int j = i+1; j <= n-1; j++) {
            for (int k = j+1; k <= n; k++) {
                if (a[i][j] || a[j][k] || a[k][i]) continue;
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
