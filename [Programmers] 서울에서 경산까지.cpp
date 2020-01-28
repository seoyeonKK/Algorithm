#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[101][100001] = {0,}; // 모금액 저장 배열 dp[루트][이동시간] 0으로 초기화

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    dp[0][travel[0][0]] = travel[0][1]; // 구간 1 도보 이동
    dp[0][travel[0][2]] = travel[0][3]; // 구간 1 자전거 이동
    
    for (int i = 1; i < travel.size(); i++) {
        for (int k = 0; k < K; k++) {
            
            if (dp[i-1][k] == 0) continue; // 걸린 시간이 아니면 pass
            
            /*
             * 기존 루트 + 도보 이동
             */
            if (travel[i][0] + k <= K) {
                // 이동 시간이 같으면 dp[i][travel[i][0]+k], dp[i-1][k] + travel[i]1[1] 중에 max값 저장
                // 이동 시간이 같지 않으면 dp[i][travel[i][0]+k] 값은 0 
                dp[i][travel[i][0]+k] = max(dp[i][travel[i][0]+k], dp[i-1][k] + travel[i][1]); 
                
                answer = max(answer, dp[i][travel[i][0]+k]); // 모금액 최댓값 update
            }

            /*
             * 기존 루트 + 자전거 이동
             */
            if (travel[i][2] + k <= K) {
                // 이동 시간이 같으면 dp[i][travel[i][2]+k], dp[i-1][k] + travel[i][3] 중에 max값 저장
                // 이동 시간이 같지 않으면 dp[i][travel[i][2]+k] 값은 0 
                dp[i][travel[i][2]+k] = max(dp[i][travel[i][2]+k], dp[i-1][k] + travel[i][3]);
                
                answer = max(answer, dp[i][travel[i][2]+k]); // 모금액 최댓값 update
            }
            
        }
    }
    return answer;
}
