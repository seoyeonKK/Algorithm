#include <iostream>
#include <vector>
using namespace std;

int N;
bool check_col[15];
bool check_dig[31];
bool check_dig2[31];
bool queen[15][15];

bool check(int row, int col) {
    // 열 체크
    if (check_col[col]) {
        return false;
    }
    // 왼쪽 위 대각선
    if (check_dig[row+col]) {
        return false;
    }
    // 오른쪽 위 대각선
    if (check_dig2[row-col+N]) {
        return false;
    }

    return true;
}

int move(int row) {
    if (row == N) return 1;

    int cnt = 0;
    for (int col = 0; col < N; col++) {
        if (check(row, col)) {
            check_col[col] = true;
            check_dig[row+col] = true;
            check_dig2[row-col+N] = true;
            queen[row][col] = true;

            cnt += move(row+1);

            check_col[col] = false;
            check_dig[row+col] = false;
            check_dig2[row-col+N] = false;
            queen[row][col] = false;
        }
    }
    return cnt;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    cout << move(0) << endl;

    return 0;
}
