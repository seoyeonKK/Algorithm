#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int S[10], W[10];

int go(int idx) {
    if (idx == N) { // 맨 마지막 계란일 때
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] <= 0) {
                cnt++;
            }
        }
        return cnt;
    }
    if (S[idx] <= 0) { // 손에 든 계란이 깨졌을 때
        return go(idx+1);
    }
    int ans = 0;
    bool ok = false;
    for (int j = 0; j < N; j++) {
        int i = idx;
        if (i == j) continue;
        if (S[j] > 0) {
            ok = true;
            S[i] -= W[j];
            S[j] -= W[i];
            int temp = go(idx+1); // 왼손 계란을 바꾼다.
            if (ans < temp) ans = temp; // 최댓값 비교 
            S[i] += W[j]; // 원상태로 복구 
            S[j] += W[i]; // 원상태로 복구
        }
    }
    if (!ok) { // 깨지지 않은 계란이 없으면
        return go(idx+1);
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> W[i];
    }

    cout << go(0) << endl;
    return 0;
}
