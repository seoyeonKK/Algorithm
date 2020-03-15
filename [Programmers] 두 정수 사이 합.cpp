#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int x = a;
    int y = b;
    
    if (x > y) {
        x = b;
        y = a;
    }
    
    for (int i = x; i <= y; i++) {
        answer += i;
    }
    
    return answer;
}
