#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());
    
    while(n) {
        int temp = q.top();
        
        if (temp == 0) break;
        
        q.pop();
        q.push(temp-1);
        n--;
    }
    
    while(!q.empty()) {
        answer += (q.top() * q.top());
        q.pop();
    }
    
    return answer;
}
