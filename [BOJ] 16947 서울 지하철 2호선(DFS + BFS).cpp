#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> a[3000];
int check[3000]; // 0: not visited, 1: visited, 2: cycle
int dist[3000];

// p -> x 간선
int go (int x, int p) {
    // -2 : 사이클 찾음, 포함X, -1 : 사이클 못찾음, 0~n-1 : 사이클 찾음, 시작 인덱
    if (check[x] == 1) return x;
    check[x] = 1;
    for (int y : a[x]) {
        if (y == p) continue;
        int res = go(y, x);
        if (res == -2) return -2;
        if (res >= 0) {
            check[x] = 2; // 사이클 포함
            if (x == res) return -2;
            else return res;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    go(0, -1); // -1 -> 0 임의 간선

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (check[i] == 2) {
            dist[i] = 0;
            q.push(i);
        }
        else {
            dist[i] = -1;
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : a[x]) {
            if (dist[y] == -1) {
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
