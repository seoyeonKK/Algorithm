#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int right = 0, left = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') right++;
        if (s[i] == '(') left++;
        
        if (right > left) return false;
        
    }
    if (right != left) return false;

    return answer;
}
