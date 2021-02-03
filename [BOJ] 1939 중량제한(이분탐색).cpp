#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define end _end
using namespace std;

vector<pair<int, int>> a[10001];
bool visited[10001];
int start, end;

// DFS로 노드 탐색
bool go(int node, int limit) {
    if (visited[node]) {
        return false;
    }
    visited[node] = true;
    if (node == end) {
        return true;
    }
    for (auto &p : a[node]) {
        int next = p.first;
        int cost = p.second;
        if (cost >= limit) {
            if (go(next, limit)) {
                return true;
            }
        }
    }
    return false; // 중량 제한을 넘어선다면 false 리턴
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    cin >> start >> end;

    // 중량을 mid로 둠
    // 중량의 범위 : 1 <= mid <= 1000000000
    int left, right;
    left = 1;
    right = 1000000000;
    int ans = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        memset(visited, false, sizeof(visited)); // 중량을 다르게 할 때마다 visited 초기화 
        if (go(start, mid)) { // DFS로 노드 탐색 
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
