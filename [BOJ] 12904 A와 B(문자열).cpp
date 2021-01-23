#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main () {
    string S, T;
    cin >> S >> T;
    
    // A와 B 모두 뒤에 추가하는 방식이기 때문에, 문자열의 뒤부터 체크해 나간다.
    while(T.length() > S.length()) {
        if (T.back() == 'A') {
            T.pop_back();
        }
        else if (T.back() == 'B') {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    
    if (S == T) {
        cout << "1" << endl;
    }
    else {
        cout << "0" << endl;
    }
    
    return 0;
}
