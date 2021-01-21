#include <iostream>
#include <algorithm>
using namespace std;

bool comp(char x, char y) {
    return x > y;
}

int main () {
    string S;
    cin >> S;

    int sum = 0;
    for (char c : S) {
        sum += c - '0'; // 각 자릿수를 더한다.
    }
    
    sort(S.begin(), S.end());
    
    // 30의 배수의 마지막 수는 항상 0이다. 3의 배수라는 것은 각 자릿수를 모두 더한 값이 3의 배수이다.
    if (S[0] == '0' && sum%3 == 0) {
        sort(S.begin(), S.end(), comp); // 최대 수이기 때문에 desc sorting
        cout << S << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
