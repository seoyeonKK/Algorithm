// 더 맵게 시간 초과 
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int newScoville = 0;
    vector< int >::iterator i = scoville.begin();
    
    sort(scoville.begin(), scoville.end());
    
    while(scoville[0] < K) {
        newScoville = scoville[0] + scoville[1]*2;

        scoville.erase(i, i+2);
        
        scoville.push_back(newScoville);
        
        sort(scoville.begin(), scoville.end());
        
        answer++;
    }
    
    return answer;
}
