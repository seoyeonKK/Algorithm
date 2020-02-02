#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    
    for (int i = 0; i < commands.size(); i++) {
        
        // vector slice
        v = std::vector<int>(array.begin()+commands[i][0]-1, array.begin()+commands[i][1]);
        
        sort(v.begin(), v.end());

        answer.push_back(v[commands[i][2] - 1]);
    
        v.clear();
    }
    
    return answer;
}
