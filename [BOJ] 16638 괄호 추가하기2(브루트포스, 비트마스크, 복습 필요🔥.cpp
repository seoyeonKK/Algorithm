#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Term{
    int num;
    int op;
};

int main() {
    int N;
    string S;

    cin >> N;
    cin >> S;
    vector<Term> a(N);

    for (int i = 0; i < N; i++) {
        if (i%2 == 0) { // number 자리 일 때
            a[i] = {S[i] - '0', 0};
        }
        else { // 연산자 일 때
            int op = 1;
            if (S[i] == '-') op = 2;
            else if (S[i] == '*') op = 3;
            a[i] = {0, op};
        }
    }
    int M = (N-1) / 2;
    int ans = -2147483648; // int최솟값
    for (int i = 0; i < (1<<M); i++) {
        bool ok = true;
        for (int j = 0; j < M-1; j++) {
            if ((i & (1<<j)) > 0 && (i & (1<<j+1)) > 0) {
                ok = false;
            }
        }
        if (!ok) continue;
        vector<Term> b(a);
        for (int j=0; j<M; j++) {
            if ((i&(1<<j)) > 0) {
                int k = 2*j+1;
                if (b[k].op == 1) {
                    b[k-1].num += b[k+1].num;
                    b[k].op = -1;
                    b[k+1].num = 0;
                } else if (b[k].op == 2) {
                    b[k-1].num -= b[k+1].num;
                    b[k].op = -1;
                    b[k+1].num = 0;
                } else if (b[k].op == 3) {
                    b[k-1].num *= b[k+1].num;
                    b[k].op = -1;
                    b[k+1].num = 0;
                }
            }
        }
        vector<Term> c;
        for (int j=0; j<N; j++) {
            if (j%2 == 0) {
                c.push_back(b[j]);
            } else {
                if (b[j].op == -1) {
                    j += 1;
                } else {
                    if (b[j].op == 3) {
                        int num = c.back().num * b[j+1].num;
                        c.pop_back();
                        c.push_back({num, 0});
                        j += 1;
                    } else {
                        c.push_back(b[j]);
                    }
                }
            }
        }
        b = c;
        int m2 = ((int)b.size()-1)/2;
        int res = b[0].num;
        for (int j=0; j<m2; j++) {
            int k = 2*j+1;
            if (b[k].op == 1) {
                res += b[k+1].num;
            } else if (b[k].op == 2) {
                res -= b[k+1].num;
            }
        }
        if (ans < res) {
            ans = res;
        }
    }
    cout << ans << endl;

    return 0;
}
