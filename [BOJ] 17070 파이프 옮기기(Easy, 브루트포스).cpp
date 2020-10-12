#include <iostream>
#include <vector>
using namespace std;

int a[17][17];
int N;

int go(int x, int y, int dir) {
    if (x == N && y == N) return 1;
    int ans = 0;
    if (dir == 0) { // - 방향일 때
        if (y+1 <= N && a[x][y+1] == 0) { // - 방향
            ans += go(x, y+1, 0);
        }
        if (x+1 <= N && y+1 <= N && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) { // \방향
            ans += go(x+1, y+1, 1);
        }
    }
    else if (dir == 1) { // \ 방향일 때
        if (y+1 <= N && a[x][y+1] == 0) { // - 방향
            ans += go(x, y+1, 0);
        }
        if (x+1 <= N && y+1 <= N && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) { // \ 방향
            ans += go(x+1, y+1, 1);
        }
        if (x+1 <= N && a[x+1][y] == 0) { // | 방향
            ans += go(x+1, y, 2);
        }
    }
    else if (dir == 2) { // | 방향
        if (x+1 <= N && y+1 <= N && a[x][y+1] == 0 && a[x+1][y] == 0 && a[x+1][y+1] == 0) { // \방향
            ans += go(x+1, y+1, 1);
        }
        if (x+1 <= N && a[x+1][y] == 0) { // | 방향
            ans += go(x+1, y, 2);
        }
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }

    cout << go(1, 2, 0) << endl;
    return 0;
}
