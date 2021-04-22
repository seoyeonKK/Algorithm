#include <iostream>
using namespace std;

// D[길이][a개][b개][쌍의 갯수]
// i번쨰 글자가 A인 경우 : D[i+1][a+1][b][p]
// i번째 글자가 B인 경우 : D[i+1][a][b+1][p+a]
// i번쨰 글자가 C인 경우 : D[i+1][a][b][p+a+b]

bool d[31][31][31][436];
char ans[32];
int n, k;

int go(int i, int a, int b,  int p) {
    if (i == n) {
        if (p == k) return true;
        else return false;
    }

    if (d[i][a][b][p]) return false;
    d[i][a][b][p] = true;

    ans[i] = 'A';
    if (go(i+1, a+1, b, p)) return true;

    ans[i] = 'B';
    if (go(i+1, a, b+1, p+a)) return true;

    ans[i] = 'C';
    if (go(i+1, a, b, p+a+b)) return true;

    return false;
}

int main() {
    cin >> n >> k;
    if (go(0, 0, 0, 0)) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}
