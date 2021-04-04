#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int main () {
    string s;
    cin >> s;

    int sum = 0;
    string answer;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            answer += s[i];
        }
        else {
            sum += (s[i]-'0');
        }
    }
    sort(answer.begin(), answer.end());

    if (sum != 0) {
        answer += to_string(sum);
    }

    cout << answer << endl;

    return 0;
}
