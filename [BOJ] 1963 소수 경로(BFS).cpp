#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int change(int now, int idx, int k) {
    if (idx == 0 && k == 0) return -1;
    string s = to_string(now);
    s[idx] = k + '0';
    return stoi(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool prime[10001] = {false,};
    bool check[10001];
    int d[10001];

    int T;

    for (int i = 2; i <= 10000; i++) {
        if (prime[i] == false) {
            for (int j = i*i; j <= 10000; j+=i) {
                prime[j] = true;
            }
        }
    }

    cin >> T;

    while(T--) {
        int n, m;
        cin >> n >> m;

        memset(check, false, sizeof(check));
        memset(d, 0, sizeof(d));
        d[n] = 0;
        check[n] = true;

        queue<int> q;
        q.push(n);
        while(!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= 9; j++) {
                    int next = change(now, i, j);
                    if (next != -1) {
                        if (!prime[next] && !check[next]) {
                            q.push(next);
                            d[next] = d[now] + 1;
                            check[next] = true;
                        }
                     }
                }
            }
        }
        cout << d[m] << endl;
    }


    return 0;
}
