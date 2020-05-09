#include <vector>
#include <stack>
#include <string>
 
using namespace std;
 
int solution(string arrangement) {
    int answer = 0;
    stack<int> num;
    for (int i = 0; i < arrangement.length(); i++){
        if (arrangement[i] == '(')
            num.push(1);
        else{
            num.pop();
            if (arrangement[i - 1] == '(')
                answer += num.size();
            else
                answer++;
        }
    }
    return answer;
}
