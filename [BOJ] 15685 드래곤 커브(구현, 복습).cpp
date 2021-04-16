#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int check[MAX][MAX];
// 동 북 서 남(반시계방향 90도 회전)
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> curve(int x, int y, int dir, int gen) {
    vector<int> ans = {dir}; // 현재 dir 넣기(모든 세대에 해당)
    // 1세대 이상 => 뒤집기가 필요
    for (int i = 1; i <= gen; i++) {
         vector<int> temp(ans);
         // ans 복사본 뒤집기
         reverse(temp.begin(), temp.end());
         // 반시계방향 90도 회전 (call by reference)1
         for (int &t : temp) {
             t = (t+1)%4;
         }
         ans.insert(ans.end(), temp.begin(), temp.end()); // ans 뒤에 temp 삽입
    }
    return ans;
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, dir, gen;
        cin >> y >> x >> dir >> gen;

        vector<int> dirs = curve(x, y, dir, gen);
        check[x][y] = true; // 방문 체크

        // 계산한 방향대로 이동 + 방문 체크
        for (int d : dirs) {
            x += dx[d];
            y += dy[d];
            check[x][y] = true;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= 99; i++) {
        for (int j = 0; j <= 99; j++) {
            // 사각형 모두 체크된 곳이면 카운트
            if (check[i][j] && check[i+1][j] && check[i][j+1] && check[i+1][j+1]) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
