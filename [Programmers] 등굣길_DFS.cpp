#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[2] = {-1, 0};
int dy[2] = {0, -1};
long long answer = 0;

void dfs (int x, int y, vector<vector<int>> ungdung) {
    
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool flag = 0;
        
        if (nx == 1 && ny == 1) {
            answer++;
            continue;
        }
        
        if ((nx > 0) && (ny > 0)) {
            for (int j = 0; j < ungdung.size(); j++) {
                if ((nx == ungdung[j][0]) && (ny == ungdung[j][1])) 
                    flag = 1;
            }
            if (!flag) dfs(nx, ny, ungdung);
        }
        
    }
    return;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    dfs(m, n, puddles);
    return answer%1000000007;
}
