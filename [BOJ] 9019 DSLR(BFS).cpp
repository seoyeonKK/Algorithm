#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int K;
bool check[10001];
int dist[10001];
char how[10001];
int from[10001];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;

    while(K--) {

        int n, m;
        cin >> n >> m;

        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        memset(from, 0, sizeof(from));

        check[n] = true;
        dist[n] = 0;
        from[n] = -1;

        queue<int> q;
        q.push(n);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (cur == m) break;

            // D
            int next = (cur * 2) % 10000;
            if (!check[next]) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'D';
            }

            // S
            next = cur - 1;
            if (next == -1) next = 9999;
            if (!check[next]) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'S';
            }

            // L
            next = (cur % 1000) * 10 + (cur / 1000);
            if (!check[next]) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'L';
            }

            // R
            next = (cur % 10) * 1000 + (cur / 10);
            if (!check[next]) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[cur] + 1;
                from[next] = cur;
                how[next] = 'R';
            }
        }
        string ans = "";
        while (m != n) {
            ans += how[m];
            m = from[m];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
