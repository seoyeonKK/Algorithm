#include <iostream>
using namespace std;

int N, total;
int col[15] = {};

bool check(int x) {
    for(int i = 0; i < x; i++)
        if(col[i] == col[x] || abs(col[x] - col[i]) == x - i) // 한 행에 한 퀸만 존재하므로, 대각선이거나 같은 라인은 거르자
            return false;
    return true;
}

void nqueen(int x) {
    if(x == N)
        total++;
    else {
        for (int row = 0; row < N; row++) {
            col[x] = row; // 해당 위치에 퀸을 배치
            if (check(x)) // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
                nqueen(x + 1);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    nqueen(0);
    
    cout << total << endl;
    return 0;
}
