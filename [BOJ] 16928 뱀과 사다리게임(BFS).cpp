#include <iostream>
#include <vector>
#include <queue>
#define next _next
using namespace std;

int dist[101];
int next[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1 ; i <= 100; i++) {
        next[i] = i;
        dist[i] = -1;
    }

    while (N--) {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }
    while (M--) {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }

    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) { // 주사위
            int y = x + i; // 다음칸 이동
            if (y > 100) continue;
            y = next[y];
            if (dist[y] == -1) { // 방문하지 않은 곳이면
                dist[y] = dist[x] + 1; // 전 이동 횟수 + 1  
                q.push(y);
            }
        }
    }

    cout << dist[100] << endl;

    return 0;
}
