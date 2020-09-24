#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int flip(char c) {
    if (c == 'H') return 'T';
    else return 'H';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int answer = n*n;

    // 비트마스크
    for (int state = 0; state < (1 << n); state++) { // 행을 바꿀지 말지
        int sum = 0;
        for (int j = 0; j < n; j++) { // i열
            int cnt = 0;
            for (int i = 0; i < n; i++) { // j열
                char cur = v[i][j];
                if (state & (1 << i)) {
                    cur = flip(cur);
                }
                if (cur == 'T') {
                    cnt += 1;
                }
            }
            sum += min(cnt, n-cnt); // cnt = T, n-cnt = H 개수
        }
        if (answer > sum) answer = sum;
    }

    cout << answer << endl;

    return 0;
}
