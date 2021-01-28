#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000][1000];

void append(string &s, char c, int num) {
    for(int i = 0; i < num; i++) {
        s += c;
    }
}

int main () {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    string s = "";
    if (n%2 == 1) { // 행의 갯수가 홀수일 때
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // 홀수번째 행
                append(s, 'R', m - 1);
                if (i != n - 1) { // 마지막 행이 아니면 내려가기
                    append(s, 'D', 1);
                }
            } else { // 짝수번째 행
                append(s, 'L', m - 1);
                append(s, 'D', 1);
            }
        }
    }
    else if (m%2 == 1) { // 열의 갯수가 홀수일 때
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) { // 홀수번째 열
                append(s, 'D', n - 1);
                if (j != m - 1) { // 마지막 열
                    append(s, 'R', 1);
                }
            }
            else { // 짝수번째 열
                append(s, 'U', n - 1);
                append(s, 'R', 1);
            }
        }
    }
    else { // 행과 열 모두 짝수개일 때
        int x, y;
        x = 0;
        y = 1;
        // 이동하지 않을 칸 고르기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) % 2 == 1) { // 검정색이면서
                    if (a[x][y] > a[i][j]) { // 수가 최소
                        x = i;
                        y = j;
                    }
                }
            }
        }
        // A 시작점
        int x1 = 0;
        int y1 = 0;
        // B 도착점
        int x2 = n - 1;
        int y2 = m - 1;
        string s2 = "";

        // 행 이동
        while (x2 - x1 > 1) {
            if (x1 / 2 < x / 2) { // x1이 x 보다 위에 있을 경우 x1 아래로 이동
                append(s, 'R', m - 1);
                append(s, 'D', 1);
                append(s, 'L', m - 1);
                append(s, 'D', 1);
                x1 += 2;
            }
            if (x / 2 < x2 / 2) { // x2가 x 보다 밑에 있을 경우 x2 위로 이동
                append(s2, 'R', m - 1);
                append(s2, 'D', 1);
                append(s2, 'L', m - 1);
                append(s2, 'D', 1);
                x2 -= 2;
            }
        }

        // 얄 이동
        while (y2 - y1 > 1) {
            if (y1 / 2 < y / 2) { // y1이 y 보다 전에 있을 경우 y1 이동
                append(s, 'D', 1);
                append(s, 'R', 1);
                append(s, 'U', 1);
                append(s, 'R', 1);
                y1 += 2;
            }
            if (y / 2 < y2 / 2) { // y2가 y 보다 뒤에 있을 경우 y2 이동
                append(s2, 'D', 1);
                append(s2, 'R', 1);
                append(s2, 'U', 1);
                append(s2, 'R', 1);
                y2 -= 2;
            }
        }
        // 이동할 수 없는 칸
        if (y == y1) {
            append(s, 'R', 1);
            append(s, 'D', 1);
        } else {
            append(s, 'D', 1);
            append(s, 'R', 1);
        }
        reverse(s2.begin(), s2.end()); // B로 가는 루트 뒤집기
        s += s2;
    }
    cout << s << endl;
    return 0;
}
