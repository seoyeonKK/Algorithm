#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visit[10000];

bool dfs(vector<vector<string>> &tickets, string from, vector<string> &answer, vector<string> &temp, int count) {
    temp.push_back(from);
    if (count == tickets.size()) {
        answer = temp;
        return true;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (!visit[i] && tickets[i][0] == from) {
            visit[i] = true;
            bool success = dfs(tickets, tickets[i][1], answer, temp, count+1);
            if (success) return true;
            visit[i] = false;
        }       
    }
    cout << "d";
    temp.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", answer, temp, 0);
    
    return answer;
}
