#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
	
    // vector 동적 할당
    vector<int> dp1(money.size()); 
    vector<int> dp2(money.size() - 1);
    
    // 첫 번째 집부터 훔칠 경우
    dp1[0] = money[0];
    dp1[1] = money[0];
    
    // 두 번째 집부터 훔칠 경우
    dp2[0] = 0;
    dp2[1] = money[1];
    
    // dp1 max 값 비교
    for (int i = 2; i < money.size() - 1; i++) {
        dp1[i] = max(dp1[i-2] + money[i], dp1[i-1]);
    }
    
    // dp2 max 값 비교
    for (int i = 2; i < money.size(); i++) {
        dp2[i] = max(dp2[i-2] + money[i], dp2[i-1]);
    }
    
    // 최종 훔친 돈(dp1, dp2) 비교
    return max(dp1[money.size()-2], dp2[money.size()-1]);
}
