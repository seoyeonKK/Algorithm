#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int dist[500001];
int main() {
    int n, k;
    cin >> n >> k;
    if (n == k) {
        cout << 0 << endl;
        return 0;
    }
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    for (int t=1;; t++) {
        k += t; // 동생 이동 
        if (k > 500000) break;
        queue<int> nq;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : {x+1, x-1, 2*x}) {
                if (0 <= y && y <= 500000) {
                    if (dist[y] != t) {
                        nq.push(y);
                        dist[y] = t;
                    }
                }
            }
        }
        if (dist[k] == t) {
            cout << t << endl;
            return 0;
        }
        q = nq;
    }
    
    cout << -1 << endl;

    return 0;
}
