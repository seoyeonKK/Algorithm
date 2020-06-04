#include <string>
#include <vector>

using namespace std;

int getCount(int n) {
    int count = 0;
    
    while(n > 0) {
        if (n % 2 == 1) count++;
        
        n = n / 2;
    }   
    return count;
}

int solution(int n) {
    int answer = 0;
    int cnt;
    
    cnt = getCount(n);
    
    while(1) {
        if (cnt == getCount(++n)) {
            answer = n;
            break;
        }
    }
    
    return answer;
}
