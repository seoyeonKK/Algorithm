#include <string>
#include <vector>
using namespace std;

long long solution(int n) {
    long long answer = 0;
    int div = 1234567;
    long long a = 1;
    long long b = 2;
    
    if (n == 1) return a; 
    else if (n == 2) return b;
    
    for (int i = 3; i <= n; i++) {
        answer = (a + b) % div;
        a = b;
        b = answer;
    }
    
    return answer;
}
