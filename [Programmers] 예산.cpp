#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;

    sort(budgets.begin(), budgets.end());
    
    int max = budgets.back();
    int min = 1;
    int d = 1000000000;

    while(max >= min){
        int mid = (max + min)/2;

        int sum = 0;

        for(int i = 0; i < budgets.size(); i++){
            if(budgets[i] <= mid){
                sum += budgets[i];
            }
            else{
                sum += mid;
            }
        }

        if(sum == M){
            answer = mid;
            break;
        }
        else if(sum > M) {
            max = mid-1;
        }
        else {
            if(M-sum < d){
                answer = mid;
                d = M-sum;
            }
            min = mid + 1;
        }
    }
    return answer;
}
