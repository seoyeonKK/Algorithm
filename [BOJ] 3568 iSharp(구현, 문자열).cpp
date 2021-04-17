#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main () {
    // 공백 포함 입력 받기
    string s;
    getline(cin, s);

    // 공백 기준 문자열 자르기
    stringstream ss(s);
    ss.str(s);

    string word;
    vector<string> var;

    while(ss >> word) {
        var.push_back(word);
    }

    // 초기 변수형 설정
    string init_type = var[0];

    for (int i = 1; i < var.size(); i++) {
        string full = init_type;
        string name = "";
        stack<char> add_type;

        // 각 변수 선언문 순회 (마지막은 콜론 or 콤마 이기 때문에 for문 범위 size-1까지)
        for (int j = 0; j < var[i].size()-1; j++) {
            // 변수명이면 name에 저장
            if (isalpha(var[i][j])) {
                name += var[i][j];
            }
            // 변수형이면 add_type 스택에 저장
            else {
                // 단, '[' or ']' 은 뒤집히지 않도록 저장
                if (var[i][j] == ']') {
                    add_type.push('[');
                }
                else if (var[i][j] == '[') {
                    add_type.push(']');
                }
                else {
                    add_type.push(var[i][j]);
                }
            }
        }

        // 스택 pop해서 순서대로 초기 변수형에 붙이기 
        while(!add_type.empty()) {
            full += add_type.top();
            add_type.pop();
        }

        // 최종 변수형 뒤에 변수명 붙이기 
        full += " ";
        full += name;

        cout << full << ";" << endl;
    }

    return 0;
}
