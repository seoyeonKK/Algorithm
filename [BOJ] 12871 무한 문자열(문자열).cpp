#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    string S, T;
    cin >> s >> t;

    S = s;
    T = t;

    while(S.length() != T.length()) {
        if (S.length() < T.length()) {
            S += s;
        }
        else {
            T += t;
        }
    }
    if (S == T) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
