#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int a = 0;
    
    if (n > s) {
        answer.push_back(-1);
    }
    else {
        answer.assign(n, s/n);
        
        int diff = s % n;
        int pos = n - 1;
        
        if (diff) {
            for (int i = diff; i > 0 ; i--) {
                answer[pos--]++;
            }
        }
    }
    
    return answer;
}
