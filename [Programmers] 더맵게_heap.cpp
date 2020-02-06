#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int first,second;
    priority_queue<int, vector<int>, greater<int>> temp; // heap으로 우선 순위 queue
    
    for(int i = 0; i < scoville.size(); i++)
        temp.push(scoville[i]);
 
    // K 미만이면서 계산할 스코빌 지수가 남아있을 때까지 while
    while (temp.top() < K && temp.size() > 1) {
        answer++;
        first = temp.top(); 
        temp.pop();
        second = temp.top();
        temp.pop();
        temp.push(first + second * 2); // 새로운 스코빌 지수 삽입
    }
    
    // 1개가 될 때까지도 K를 넘지 못하면
    if (temp.top() < K)
        return -1;
    
    return answer;
}
