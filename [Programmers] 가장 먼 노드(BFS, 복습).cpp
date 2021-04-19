#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int connect[20001][20001];
bool visit[20001];
int dist[20001];
queue<int> q;

int solution(int n, vector<vector<int>> vertex) {
    int max = 0;
    int answer = 0;
    
    // 간선 표시
    for(int i = 0; i < vertex.size(); i++) {
        connect[vertex[i][0]][vertex[i][1]] = 1;
        connect[vertex[i][1]][vertex[i][0]] = 1;
    }

    // 1번 노드 큐 삽입
    visit[1] = true;
    q.push(1);
    dist[1] = 0; // 1번 노드 거리 = 0

    // bfs
    while(!q.empty()) {       
        int cur = q.front();
        q.pop();       
        
        // 인접 행렬 탐색
        for(int i = 1; i <= n; i++) {
            if(connect[cur][i] == 1 && !visit[i]) {
                q.push(i);
                visit[i] = true;
                dist[i] = dist[cur] + 1;
                
                if (max < dist[i]) {
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
