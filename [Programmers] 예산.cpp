#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    long sum = 0;
    int old_mid;
    int mid = 50000;
    int max = 100000;
    int min = 0;
    
    sort(budgets.begin(), budgets.end());
    
    // sum : 요청 금액의 합
    for (int i = 0; i < budgets.size(); i++) {
        sum += budgets[i];
    }
    
    if (sum <= M)
        return budgets[budgets.size() - 1];
    
    // mid : 상한액 후보
    while (true) {
        sum = 0;
        
        // sum : 상한가 고려한 요청 금액의 합
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i] > mid) {
                sum += mid;
            }
            else {
                sum += budgets[i];
            }
        }
        
        if (M < sum) {
            max = mid;
        }
        else if (M > sum) {
            min = mid;
        }
        else{
            return mid;
        }
        
        old_mid = mid;
        mid = (min + max) / 2;
        
        if (mid == old_mid) {
            return mid;
        }
    }
    
    return answer;
}
