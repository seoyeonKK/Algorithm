// takes 30m - not complete 
// remain 시간 계산하는 것
// job이 끝났을 때 시간 시점에 pop g
 
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int remain = 0;
    int i = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp;
    
    while(!temp.empty()) {
        if (i < jobs[i][0]) {
            i++;
            continue;
        } // 최소힙 시작 시간이 현재 시간보다 느릴 때
        else {
            temp.push({ make_pair(jobs[i][1], jobs[i][0]) });
        }
        
        if (i - remain == temp.top().first) {
            answer = i - temp.top().second;
            temp.pop();
        }
        i++;
    }
    
    return answer / jobs.size();
}
