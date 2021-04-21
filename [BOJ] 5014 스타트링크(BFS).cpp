#include <iostream>
#include <queue>
using namespace std;

// 정점 : 몇 층인지
// 간선 : 몇 번 버튼을 눌렀는지
int dist[1000001];
bool check[1000001];

int main() {
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d; // f:건물높이, g:목적지, s:현재위치, u:위로 몇 층 이동, d:아래로 몇 층 이동

    queue<int> q;
    q.push(s);
    check[s] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if (now+u <= f && check[now+u] == false) {
            dist[now+u] = dist[now] + 1;
            check[now+u] = true;
            q.push(now+u);
        }
        if (now-d >= 1 && check[now-d] == false) {
            dist[now-d] = dist[now] + 1;
            check[now-d] = true;
            q.push(now-d);
        }
    }
    
    if (check[g]) {
        cout << dist[g] << endl;
    }
    else {
        cout << "use the stairs" << endl;
    }
    
    return 0;
}
