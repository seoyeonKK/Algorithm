#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;

int map[MAX][MAX];
int visited[MAX]; //정점의 개수만큼 visited
queue<int> q;
int n,m,v;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void dfs(int v){
    cout << v << " ";
    visited[v] = 1;
    for(int i = 1; i <= n; i++){
        if(map[v][i] && !visited[i]){
            dfs(i);
        }
    }
}

void bfs(int v){
    visited[v] = 1;
    q.push(v);
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        
        cout << v << " "; //bfs는 pop으로 방문함!! 
        for(int i = 1; i <= n; i++){
            if(map[v][i] && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main(void){
    init();
    cin >> n >> m >> v;
    memset(map,0,sizeof(map));
    memset(visited,0,sizeof(visited));
    
    for(int i = 0; i < m; i++){
        int a, b; //간선을 연결, 연결되어있음을 1로 나타냄
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    dfs(v);
    cout << "\n";
    //////////////
    
    memset(visited,0,sizeof(visited));
    bfs(v);
    cout << "\n";
    return 0;
}
