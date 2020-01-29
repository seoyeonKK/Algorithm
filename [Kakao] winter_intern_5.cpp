#include <vector>
#include <iostream>
using namespace std;

int solution(vector stones, int k) {
    int answer = 0;

    for(int i=0; i < stones.size(); i++) {
        int count = 0;
        int max = 0;
        for(int j = 1; j<k+1; j++) {//내 뒤 세명만 검사
            if(stones[i] > stones[i+j]) {
                count++;
                if(stones[i+j]>max)
                    max = stones[i+j];
                continue;
            }
            else
                break;
        }
        if(count == k){
            if(answer == 0 || max < answer)
                answer = max;
        }
    }
    return answer;
}
