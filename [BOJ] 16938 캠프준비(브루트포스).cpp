#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R, X;
int a[15];
bool check[15];

int go (int idx) {
    if (idx == N) {
        int cnt = 0;
        int sum = 0;
        int hard = -1;
        int easy = -1;
        for (int i = 0; i < N; i++) {
            if (check[i] == false) continue;
            sum += a[i];
            cnt += 1;
            if (hard == -1 || hard < a[i]) hard = a[i];
            if (easy == -1 || easy > a[i]) easy = a[i];
        }
        if (cnt >= 2 && L <= sum && sum <= R && hard-easy >= X) {
            return 1;
        }
        else
            return 0;
    }
    check[idx] = true;
    int cnt1 = go(idx+1); // 고르는 경우
    check[idx] = false;
    int cnt2 = go(idx+1); // 고르지 않는 경우

    return cnt1 + cnt2;
}

int main() {
    cin >> N >> L >> R >> X;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cout << go(0) << endl;
    return 0;
}
