#include <iostream>
#include <vector>
using namespace std;

int a[200][200];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int R, C, N;
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == '.') {
                a[i][j] = 0;
            }
            else {
                a[i][j] = 2;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (i%2 == 0) { // 폭탄 추가
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    if (a[j][k] == 0) {
                        a[j][k] = 3;
                    }
                    else if (a[j][k] > 0){
                        a[j][k]--;
                    }
                }
            }
        }
        else { // 폭탄 터짐
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    if (a[j][k] == 1) { // 1초 남은 폭탄은 이번에 터지는 폭탄
                        a[j][k] = 0;
                        for (int l = 0; l < 4; l++) {
                            int nx = j + dx[l];
                            int ny = k + dy[l];
                            if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                                if (a[nx][ny] != 1) { // 인접한 칸이 1초 남은 폭탄이 아니라면, 이번에 터지는 폭탄
                                    a[nx][ny] = 0;
                                }
                            }
                        }
                    }
                }
            }

            for (int j = 0; j < R; j++) { // 이번에 터진 폭탄이 아니라면, (폭탄 수명 - 1)
                for (int k = 0; k < C; k++) {
                    if (a[j][k] > 0) {
                        a[j][k]--;
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] == 0) {
                cout << '.';
            }
            else {
                cout << 'O';
            }
        }
        cout << endl;
    }

    return 0;
}
