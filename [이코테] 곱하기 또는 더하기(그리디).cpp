#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main () {
    string str;
    cin >> str;

    long long result = str[0]-'0'; // 숫자 변환 : char -> int 

    for (int i = 1; i < str.length(); i++) {
        int num = str[i] - '0';
        // 둘 중에 하나라도 1이하라면 덧셈이 유리하다. 아니라면, 곱셈이 유리하다.
        if (result <= 1 || num <= 1) {
            result += num;
        }
        else {
            result *= num;
        }
    }

    cout << result << endl;

    return 0;
}
