#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;

int N, M;
int next[101];
int dist[101];

int main() {
    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= 100; i++) {
        next[i] = i;
        dist[i] = -1; // 모두 방문하지 않은 형태
    }

    // 사다리 정보 입력
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        next[x] = y;
    }

    // 뱀 정보 입력
    for (int i = 0; i < M; i++) {
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
        for (int i = 1; i <= 6; i++) { // 주사위 1~6
            int y = x+i;
            if (y > 100) continue;
            y = next[y]; // 뱀과 사다리라면 이동
            if (dist[y] == -1) {
                dist[y] = dist[x] + 1; // 주사위 굴린 횟수 추가 
                q.push(y);
            }
        }
    }
    
    cout << dist[100] << endl;

    return 0;
}
