#include <iostream>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;


int n, m, a, b, result;

// 벡터를 인접 리스트로 사용합니다.
vector<int> v[MAX];

// 시작 정점으로 부터의 거리 정보를 담을 배열입니다.
int check[MAX];

void bfs(int start){
    check[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i];
            if(check[next] == 0){
                
                // 다음 방문할 정점의 거리를 현재 정점까지의 거리 +1이됩니다.
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    // 간선의 정보를 입력받으면서 양방향 그래프로 만들어줍니다.
    for(int i=0; i<m; i++){
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // 시작 정점을 거리를 1로 체크하고, BFS 탐색을 시작합니다.
    check[1] = 1;
    bfs(1);
    
    // check[i]가 1이면 정점. 2, 3이면 초대해도 되는 사람들입니다.
    result = 0;
    for(int i=2; i<=n; i++){
        if(check[i] == 2 || check[i] == 3){
            result++;
        }
    }

    // 4. 결과 출력
    cout << result << endl;
    
    return 0;
}
