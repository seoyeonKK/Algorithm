#include <iostream>
#include <string>
using namespace std;

/* c[][]은
 * 이 방식으로 표시
0그룹     00
1그룹    1  2
1그룹    1  2
2그룹     33
3그룹    4  5
3그룹    4  5
4그룹     66
 *
*/

int c[10][10]={
        {1,1,1,0,1,1,1},
        {0,0,1,0,0,1,0},
        {1,0,1,1,1,0,1},
        {1,0,1,1,0,1,1},
        {0,1,1,1,0,1,0},
        {1,1,0,1,0,1,1},
        {1,1,0,1,1,1,1},
        {1,0,1,0,0,1,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
};

int main() {
    int s;
    string n;
    cin >> s >> n;
    int m = n.length();
    for (int i = 0; i < 5; i++) {
        // 가로 그룹(0, 2, 4) 출력
        if (i == 0 || i == 2 || i == 4) {
            for (int j = 0; j < m; j++) {
                int now = n[j] - '0';
                if (j != 0) {
                    cout << ' ';
                }
                cout << ' ';
                // 가로 줄 idx
                if ((i == 0 && c[now][0]) || (i == 2 && c[now][3]) || (i == 4 && c[now][6])) {
                    for (int k = 0; k < s; k++) {
                        cout << '-';
                    }
                }
                else {
                    for (int k = 0; k < s; k++) {
                        cout << ' ';
                    }
                }
                cout << ' ';
            }
            cout << endl;
        }
        // 세로 그룹(1, 3) 출력
        else {
            for (int l = 0; l < s; l++) {
                for (int j = 0; j < m; j++) {
                    int now = n[j] - '0';
                    if (j != 0) {
                        cout << ' ';
                    }
                    // 왼쪽 세로 줄 idx
                    if ((i == 1 && c[now][1]) || (i == 3 && c[now][4])) {
                        cout << '|';
                    }
                    else {
                        cout << ' ';
                    }
                    for (int k = 0; k < s; k++) {
                        cout << ' ';
                    }
                    // 오른쪽 세로 줄 idx
                    if ((i == 1 && c[now][2]) || (i == 3 && c[now][5])) {
                        cout << '|';
                    } else {
                        cout << ' ';
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
