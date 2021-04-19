#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool fight[101][101];
bool visited[101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 0; i < results.size(); i++) {
        fight[results[i][0]][results[i][1]] = 1; 
    }
    
    // 플로이드 와샬
    for(int b = 1; b <= n; b++) {
        for(int a = 1; a <= n; a++) {
            for(int c = 1; c <= n; c++) {
                // a가 b를 이겼고 b가 c를 이겼으면, a가 c를 이겼다고 표시
                if(fight[a][b] && fight[b][c])
                    fight[a][c] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int winCount = 0;
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            // i가 j를 이겼거나 j가 i를 이긴 경우
            if(fight[i][j] || fight[j][i])
                winCount++;
        }
        // 둘중에 승패가 확실한 경우(본인 빼고 승패가 결정난 경우)
        if (winCount == n-1)
            answer++;
    }
    
    return answer;
}
