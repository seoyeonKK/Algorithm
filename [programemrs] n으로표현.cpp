#include <string>

using namespace std;

int answer = -1;

void dfs(int n, int pos, int num, int number, string s) {
    if (pos > 8) return;
    
    if (num==number) {
        if (answer==-1 || pos<answer) {
            answer = pos;
        }
        return;
    }
    
    int nn = 0;
    
    for (int i = 0; i < 8; i++) {
        nn=nn*10+n;
        dfs(n, pos+i+1, num+nn, number, "+");
        dfs(n, pos+i+1, num-nn, number, "-");
        dfs(n, pos+i+1, num*nn, number, "*");
        dfs(n, pos+i+1, num/nn, number, "/");
    }
}

int solution(int N, int number) {
    dfs(N, 0, 0, number, "");
    
    return answer;
}
