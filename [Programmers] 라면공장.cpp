// 무조건 공급 받고, 최대힙을 사용해 stock이 바닥날 때 공급 받은 stock 채우기
// 채웠을 때 answer 카운트

#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j = 0;
    priority_queue<int, vector<int>, less<int>> temp; // less는 최대 힙
    
    for (int i = 0; i < k; i++) {
    
        // 공급 받는 날짜이면
        if (dates[j] == i) {
            temp.push(supplies[j]);
            if (j != supplies.size() - 1) j++;
        }
        
        // 남은 stock이 없으면
        if (stock == 0) {
            stock += temp.top(); // 최대 힙으로 가져와야 최소 횟수로 공급 받는다.
            temp.pop();
            answer++;
        }
        
        stock--; // 하루 지날 때 1톤 사용
    }
    
    return answer;
}
