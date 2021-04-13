#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
// 남 동 북 서
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void rotate(vector<vector<int>>& arr) {
    // (n, m 중에 작은 숫자 + 1)/2 한 만큼 테두리가 생김
    // 그 테두리 갯수만큼 돌리면 됨.
    // ( 1, 2 ) -> 1번 회전
    // ( 3, 4 ) -> 2번 회전
    // ( 5, 6 ) -> 3번 회전

    int count = (min(n, m)+1)/2;

    for (int i = 0; i < count; i++) {
        int dir = 0; // 방향
        int x = i;  // 시작점 (왼쪽 위)
        int y = i;
        int temp = arr[x][y];

        while (dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //사각형을 벗어나지 않으면 계속 진행
            if (nx < i || ny < i || nx > n-i-1 || ny > m-i-1) {
                dir++;
            }
            else {
                arr[x][y] = arr[nx][ny];
                x = nx;
                y = ny;
            }
        }
        arr[i+1][i] = temp; //a10 = a00
    }
}

int main () {
    cin >> n >> m >> t;

    vector<vector<int>> arr(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        rotate(arr);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
