#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, K;
    cin >> N >> K;
    for (int a = 0; a <= N; a++) {
        int b = N-a;
        if (a*b < K) continue; // 0 <= K <= a*b
        vector<int> cnt(b+1);
        for (int i = 0; i < a; i++) {
            int x = min(b, K);
            cnt[x] += 1; // A가 i번 위치에 몇 개인지.
            K -= x;
        }
        for (int i = b; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << "A"; // 카운트 갯수만큼 추가
            }
            if (i > 0) {
                cout << "B";
            }
        }
        cout << endl;
    }
    cout << -1 << endl;
    return 0;
}
