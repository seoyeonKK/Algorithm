#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int adjacent[20001][20001];
bool visit[20001];
int dist[20001];
queue<int> q;

int solution(int n, vector<vector<int>> edge) {
    int max = 0;
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++) {
        adjacent[edge[i][0]][edge[i][1]]=1;
        adjacent[edge[i][1]][edge[i][0]]=1;
    }

    visit[1]=true;
    q.push(1);
    dist[1]=0;
    
    while(!q.empty()) {
        
        int idx = q.front();
        q.pop();       
        
        for(int i = 2; i <= n; i++) {
            if(adjacent[idx][i] == 1 && !visit[i]) {
                q.push(i);
                visit[i]=true;
                dist[i] = dist[idx] + 1;
                
                if(max < dist[i]) {
                    max = dist[i];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(max == dist[i]) answer++;
    }
    
    return answer;
}
