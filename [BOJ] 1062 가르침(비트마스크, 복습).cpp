#include <iostream>
#include <vector>
using namespace std;


int count(int mask, vector<int> &words) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1<<26)-1-mask)) == 0) { // 배우지 않은 알파벳이 단어에 있는지 검사
            cnt += 1;
        }
    }
    return cnt;
}

int go(int idx, int K, int mask, vector<int> &words) {
    if (K < 0) return 0;
    if (idx == 26) return count(mask, words);
    int ans = 0;
    int t1 = go(idx+1, K-1, mask | (1 << idx), words);
    if (ans < t1) ans = t1;
    if (idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' && idx != 'i'-'a' && idx != 'c'-'a') {
        t1 = go(idx+1, K, mask, words);
        if (ans < t1) ans = t1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> words(N);

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;


        for (char x : S) {
            words[i] |= (1 << (x - 'a'));
        }
    }

    cout << go(0, K, 0, words) << endl;
    return 0;
}
