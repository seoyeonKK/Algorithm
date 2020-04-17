#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
    bool flag = true;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
} 

int solution(vector<int> nums) {
    int answer = 0;
    int size = (int)nums.size();
    int num = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                num = nums[i] + nums[j] + nums[k];
                if (isPrime(num)) answer++;
            }
        }
    }
    
    return answer;
}
