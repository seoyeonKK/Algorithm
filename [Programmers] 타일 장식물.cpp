#include <string>

using namespace std;
long fibo_list[80]; // 피보나치 배열
long last; // 마지막 피보나치 수

int fibo(int n) {
    fibo_list[0] = 1;
    fibo_list[1] = 1;
    
    // 피보나치 반복 알고리즘
    for (int i = 2; i < n; i++) {
        fibo_list[i] = fibo_list[i-1] + fibo_list[i-2];
    } 
 
    last = fibo_list[n-1];
    
    return fibo_list[n];
}

long long solution(int N) {
    long long answer = 0;
    int x;
    
    x = fibo(N+2); // 반복 알고리즘이 2부터 돌기 때문에 N+2 해준다.    
    answer = (x + last)*2 + x*2; // 둘레 계산
        
    return answer;
}
