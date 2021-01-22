#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, K;
    cin >> N >> K;
    
    for (int a = 0; a <= N; a++) { // a의 갯수
        int b = N-a; // b의 갯수
        if (a*b < K) continue; // 0 <= K <= a*b 이다. 앞(aaa)뒤(bb) 최소 쌍.
        vector<int> cnt(b+1); // b사이에 끼게 될 a의 위치
        for (int i = 0; i < a; i++) {
            int x = min(b, K); // a가 추가될 수 있는 위치의 범위는 (K ~ b)
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
