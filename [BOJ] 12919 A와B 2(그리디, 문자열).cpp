#include <iostream>
#include <algorithm>
using namespace std;

string cut(string s) {
    s.pop_back();
    return s;
}

string rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// a - a (O) : A연산 
// a - b (X) : 모두 아님.
// b - a (O) : A 혹은 B 연산. 2가지 경우의 수 재귀로 조사 
// b - b (O) : B연산
bool can(string s, string t) {
    if (s == t) return true;
    if (t.length() > 0) {
        // A 먼저 조사 
        if (t.back() == 'A' && can(s, cut(t))) {
            return true;
        }
        // B 조사 
        if (t[0] == 'B' && can(s, cut(rev(t)))) {
            return true;
        }
    }
    return false;
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << can(s, t) << endl;

    return 0;
}
