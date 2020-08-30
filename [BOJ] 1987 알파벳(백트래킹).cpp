#include <iostream>
#include <vector>
using namespace std;

int N, M;
int ans = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void move (vector<string> &arr, vector<bool> &check, int x, int y, int cnt) {
    if (cnt > ans) ans = cnt;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && !check[arr[nx][ny]-'A']) {
            check[arr[nx][ny]-'A'] = true;
            move(arr, check, nx, ny, cnt+1);
            check[arr[nx][ny]-'A'] = false;
        }
    }

}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    vector<string> arr(N);
    vector<bool> check(26);

    for (int i = 0; i < N; i++) {
            cin >> arr[i];
    }

    check[arr[0][0]-'A'] = true;
    move(arr, check, 0, 0, 1);

    cout << ans << endl;

    return 0;
}
