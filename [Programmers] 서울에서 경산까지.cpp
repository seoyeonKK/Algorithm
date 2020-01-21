#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[101][100001] = {0,};

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    dp[0][travel[0][0]] = travel[0][1];
    dp[0][travel[0][2]] = travel[0][3];
    
    for (int i = 1; i < travel.size(); i++) {
        for (int k = 0; k < K; k++) {
        
            if (dp[i-1][k] == 0) continue;
            
            if (travel[i][0] + k <= K) {
                dp[i][travel[i][0]+k] = max(dp[i][travel[i][0]+k], dp[i-1][k] + travel[i][1]);
                answer = max(answer, dp[i][travel[i][0]+k]);
            }
            
            if (travel[i][2] + k <= K) {
                dp[i][travel[i][2]+k] = max(dp[i][travel[i][2]+k], dp[i-1][k] + travel[i][3]);
                answer = max(answer, dp[i][travel[i][2]+k]);
            }
        }
    }
    return answer;
}
