#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            idx = 0;
            answer += " ";
            continue;
        }
        if (idx%2) {
            answer += tolower(s[i]);
        }
        else {
            answer += toupper(s[i]);
        }
        idx++;
    }
    cout << answer;
    return answer;
}
