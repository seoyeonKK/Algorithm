#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map< string, int > m; // pair < 종류, count >
    int answer = 1; // 나중에 곱을 하기 때문에 1로 초기화
        
    for (int i = 0; i < clothes.size(); i++) {
        
        if (m.count(clothes[i][1]) == 0) {
            m[clothes[i][1]] = 1; // m.insert(make_pair(clothes[i][1], 1)); 써도 됨
        }
        else {
            m[clothes[i][1]]++;
        }
    }
    
    // map for문 -> key로 value 접근하기
    // 파이썬 "for i in list:" 와 같은 코드
    for (auto i : m) {
        answer *= (i.second + 1); // 안 입는 경우 1을 더해서 경우의 수 구하기
    }
    // 하단 문법처럼 사용해도 됨.
//     for(auto it = m.begin(); it != m.end(); it++){
//         answer *= (it->second + 1); // 안 입는 경우 1을 더해서 경우의 수 구하기
//     }

    // 아무 것도 입지 않는 경우 1을 뺌
    answer--;

    return answer;
}
