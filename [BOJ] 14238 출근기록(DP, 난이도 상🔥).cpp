#include <iostream>
using namespace std;


/*
<점화식>
D[a 개수][b 개수][c 개수][p1 전날 일한 사람][p2 전전날 일한 사람]
오늘 일한 사람이 A인 경우 : D[a+1][b][c]['A'][p1]
오늘 일한 사람이 B인 경우 : D[a][b+1][c]['B'][p1]
오늘 일한 사람이 C인 경우 : D[a][b][c+1]['C'][p1]

단, B의 경우 P1 != 'B'
    C의 경우 P1 != 'C' && p2 != 'C'
*/

int d[51][51][51][3][3];
int go(int a, int b, int c, int p1, int p2) {
    int &ans = d[a][b][c][p1][p2];
    if (a+b+c == 0) {
        return ans = 1;
    }
    if (ans != -1) return ans;
    if (a > 0 && go(a-1, b, c, 0, p1) == 1) {
        return ans = 1;
    }
    if (b > 0 && p1 != 1) {
        if (go(a, b-1, c, 1, p1) == 1) {
            return ans = 1;
        }
    }
    if (c > 0 && p1 != 2 && p2 != 2) {
        if (go(a, b, c-1, 2, p1) == 1) {
            return ans = 1;
        }
    }
    return ans = 0;
}

string back(int a, int b, int c, int p1, int p2) {
    if (a+b+c == 0) {
        return "";
    }
    if (a > 0 && go(a-1, b, c, 0, p1) == 1) {
        return "A" + back(a-1, b, c, 0, p1);
    }
    if (b > 0 && p1 != 1) {
        if (go(a, b-1, c, 1, p1) == 1) {
            return "B" + back(a, b-1, c, 1, p1);
        }
    }
    if (c > 0 && p1 != 2 && p2 != 2) {
        if (go(a, b, c-1, 2, p1) == 1) {
            return "C" + back(a, b, c-1, 2, p1);
        }
    }
    return "";
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int limit[3] = {0, 0, 0};
    for (int i=0; i<n; i++) {
        limit[s[i]-'A'] += 1;
    }
    memset(d,-1,sizeof(d));
    int ans = go(limit[0], limit[1], limit[2], 0, 0);
    if (ans == 0) {
        cout << -1 << '\n';
    } else {
        cout << back(limit[0], limit[1], limit[2], 0, 0) << '\n';
    }
    return 0;
}
