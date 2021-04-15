#include <iostream>
#include <vector>
using namespace std;

int T, n;

int main () {
    cin >> T;
    vector<string> wheel(T);

    for (int i = 0; i < T; i++) {
        cin >> wheel[i];
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int num, dir;
        cin >> num >> dir;
        num -= 1; // 톱니바퀴번호 idx 0~3 으로 바꾸기

        vector<int> d(n);
        d[num] = dir; // 각 톱니바퀴의 이동 방향을 저장

        // 왼쪽 톱니바퀴들 이동 방향 구하기
        for (int i = num-1; i >= 0; i--) {
            // 다르면 반대방향으로 회전
            if (wheel[i][2] != wheel[i+1][6]) {
                d[i] = -d[i+1];
            }
            // 같으면 더이상 안 움직임
            else break;
        }

        // 오른쪽 톱니바퀴들 이동 방향 구하기
        for (int i = num+1; i < T; i++) {
            // 다르면 반대방향으로 회전
            if (wheel[i][6] != wheel[i-1][2]) {
                d[i] = -d[i-1];
            }
            // 같으면 더이상 안 움직임
            else break;
        }

        // 회전 방향대로 톱니바퀴 움직이기
        for (int i = 0; i < n; i++) {
            // 안 움직인 톱니
            if (d[i] == 0) continue;
            // 시계방향 회전하는 톱니
            if (d[i] == 1) {
                char temp = wheel[i][7];
                for (int j = 7; j >= 1; j--) {
                    wheel[i][j] = wheel[i][j-1];
                }
                wheel[i][0] = temp;
            }
            // 반시계방향 회전하는 톱니
            else if (d[i] == -1) {
                char temp = wheel[i][0];
                for (int j = 0; j < 7; j++) {
                    wheel[i][j] = wheel[i][j+1];
                }
                wheel[i][7] = temp;
            }
        }
    }

    // S극인 톱니 갯수 구하기
    int cnt = 0;
    for (int i = 0; i < T; i++) {
        if (wheel[i][0] == '1') {
            cnt ++;
        }
    }

    cout << cnt << endl;

    return 0;
}
