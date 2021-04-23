#include <iostream>
using namespace std;

int n, m;
int a[100];

int calc(int i, string s) {
    if (i + s.length() > n) return 0;
    int base = a[i] - (s[0] - '0'); // 테트리스가 i열에 떨어진 높이
    for (int j = 0; j < s.length(); j++) {
        if (base != a[i+j] - (s[j]-'0')) { // 테트리스가 있는 다른 열이랑 높이가 다르지 않다면
            return 0;
        }
    }
    return 1;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    // 테트리스 밑 바닥 높이
    for (int i = 0; i < n; i++) {
        if (m == 1) {
            ans += calc(i, "0") + calc(i, "0000");
        }
        else if (m == 2) {
            ans += calc(i, "00");
        }
        else if (m == 3) {
            ans += calc(i, "001") + calc(i, "10");
        }
        else if (m == 4) {
            ans += calc(i, "100") + calc(i, "01");
        }
        else if (m == 5) {
            ans += calc(i, "000") + calc(i, "01") + calc(i, "101") + calc(i, "10");
        }
        else if (m == 6) {
            ans += calc(i, "000") + calc(i, "00") + calc(i, "011") + calc(i, "20");
        }
        else if (m == 7) {
            ans += calc(i, "000") + calc(i, "00") + calc(i, "110") + calc(i, "02");
        }
    }

    cout << ans << endl;

    return 0;
}
