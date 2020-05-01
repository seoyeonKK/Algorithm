#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); i++) {
        v.push_back({ priorities[i], i });
    }
    
    int i = 0;
    while(!v.empty()) {
        bool flag = true;
        int front = v.at(0).first;
        
        for (int i = 0; i < v.size(); i++) {
            if (front < v[i].first) {
                v.push_back(v[0]);
                v.erase(v.begin()+0);
                flag = false;
                break;
            }
        }
        
        if (flag) {
            q.push(v.front());
            v.erase(v.begin()+0);
        }
    }
    
    int idx = 0;
    while(!q.empty()) {
        if (location == q.front().second) {
            answer = idx + 1;
            break;
        }
        else {
            q.pop();
        }
        idx++;
    }
    
    return answer;
}
