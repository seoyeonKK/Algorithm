#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    
    // 체육복 여유 분이 있지만 잃어버린 경우
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (lost[j] == reserve[i]) {
                reserve.erase(reserve.begin()+i);
                lost.erase(lost.begin()+j);
                answer++;              
                i--;
                break;
            }
        }
    }
    
    // 여유 분의 체육복을 양 옆 학생에게 빌려주는 경우
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i]+1 == reserve[j] || lost[i]-1 == reserve[j]) {
                reserve.erase(reserve.begin()+j);
                answer++;
                break;
            }
        }    
    }
    
    return answer;
}
