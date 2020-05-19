#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string p) {
    string answer = "";
    int left = 0, right = 0;
    bool check = false;
    
    if (p.length() == 0) return "";
    
    for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') left++;
		if (p[i] == ')') right++;
		if (right > left) check = true;
        //오른쪽 괄호 수가 더 커지는 순간 이미 올바른 문자열이 아니기 때문에 check를 해준다
		if (left == right) { // 개수가 같아질 때가 균형잡힌 문자열 u가 만들어지는 순간
			if (check == true) { //u가 올바른 문자열이 아닐 경우
				answer += '(';
				answer += solution(p.substr(i + 1, p.length() - i - 1));
				answer += ')';
				for (int j = 1; j < i; j++) {
					if (p[j] == ')') answer += '(';
					if (p[j] == '(') answer += ')';
				}
				return answer;
			}
			else { //u가 올바른 문자열일 경우
				answer += p.substr(0, i + 1);
				answer += solution(p.substr(i + 1, p.length() - i - 1));
				return answer;
			}
		}
	}
}
