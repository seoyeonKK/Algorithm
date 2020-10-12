#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int n = 5;
int dx[] = {0,0,0,0,1,-1};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {1,-1,0,0,0,0};

int bfs(vector<vector<vector<int>>> &a) {
    if (a[0][0][0] == 0) return -1;
    int dist[n][n][n];
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,0));
    dist[0][0][0] = 0;
    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        for (int k=0; k<6; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int nz = z+dz[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && 0 <= nz && nz < n) {
                if (a[nx][ny][nz] == 1 && dist[nx][ny][nz] == -1) {
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                    q.push(make_tuple(nx, ny, nz));
                }
            }
        }
    }
    return dist[n-1][n-1][n-1];
}

vector<vector<int>> clockwise(vector<vector<int>> &a) {
    vector<vector<int>> b(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            b[i][j] = a[n-j-1][i];
        }
    }
    return b;
}

int main() {
    vector<vector<vector<int>>> a(n);
    for (int k=0; k<n; k++) {
        a[k].resize(n, vector<int>(n));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> a[k][i][j];
            }
        }
    }
    vector<int> order;
    for (int i=0; i<n; i++) {
        order.push_back(i);
    }
    int ans = -1;
    do {
        vector<vector<vector<int>>> b(n);
        for (int i=0; i<n; i++) {
            b[order[i]] = a[i];
        }
        for (int l1=0; l1<4; l1++) {
            for (int l2=0; l2<4; l2++) {
                for (int l3=0; l3<4; l3++) {
                    for (int l4=0; l4<4; l4++) {
                        for (int l5=0; l5<4; l5++) {
                            int cur = bfs(b);
                            if (cur != -1) {
                                if (ans == -1 || ans > cur) {
                                    ans = cur;
                                }
                            }
                            b[4] = clockwise(b[4]);
                        }
                        b[3] = clockwise(b[3]);
                    }
                    b[2] = clockwise(b[2]);
                }
                b[1] = clockwise(b[1]);
            }
            b[0] = clockwise(b[0]);
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << endl;
    return 0;
}
