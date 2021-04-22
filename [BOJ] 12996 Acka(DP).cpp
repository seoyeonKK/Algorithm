#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000007;
long long d[51][51][51][51];

long long go(int n, int a, int b, int c) {
    if (n == 0) {
        if (a == 0 && b == 0 && c == 0) return 1;
        else return 0;
    }
    if (a < 0 || b < 0 || c < 0) return 0;
    long long &ans = d[n][a][b][c];
    if (ans !=- 1) return ans;
    ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (i+j+k == 0) continue;
                ans += go(n-1, a-i, b-j, c-k);
            }
        }
    }
    ans %= mod;
    return ans;
}

int main () {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    memset(d, -1, sizeof(d));
    cout << go(n, a, b, c) << endl;

    return 0;
}
