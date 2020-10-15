#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int parent[500*500];
int ans[500*500];
int a[500][500];

int go(int idx) {
    if (parent[idx] == idx) return idx;
    else {
        return parent[idx] = go(parent[idx]);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           int x = i;
           int y = j;
           for (int k = 0; k < 8; k++) {
               int nx = i + dx[k];
               int ny = j + dy[k];
               if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                   if (a[nx][ny] < a[x][y]) {
                       x = nx;
                       y = ny;
                   }
               }
           }
           parent[i*m+j] = x*m+y;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[go(i*m+j)] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i*m+j] << " ";
        }
        cout << endl;
    }

    return 0;
}
