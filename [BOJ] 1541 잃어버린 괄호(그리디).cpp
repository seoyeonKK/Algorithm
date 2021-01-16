#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    string s;
    cin >> s;
    vector<int> num;
    vector<int> sign; // 1이면 +, -1이면 -
    bool minus = false;
    int cur = 0;
    sign.push_back(1); // 첫번째는 부호가 없어서 일관성을 주기 위해 +를 임의로 부여

    // string에서 연산자와 피연산자를 분리
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                sign.push_back(1);
            }
            else {
                sign.push_back(-1);
            }
            num.push_back(cur);
            cur = 0;
        }
        else {
            cur = cur * 10 + (s[i]-'0'); // 두자리 수 이상일 경우
        }
    }
    num.push_back(cur);

    // minus 이후의 수를 괄호로 묶고 뺀다.
    int ans = 0;
    minus = false;
    for (int i = 0; i < num.size(); i++) {
        if (sign[i] == -1) {
            minus = true;
        }
        if (minus) {
            ans -= num[i];
        }
        else {
            ans += num[i];
        }
    }
    cout << ans << endl;

    return 0;
}
