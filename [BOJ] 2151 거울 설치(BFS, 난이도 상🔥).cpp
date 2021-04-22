#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

// 정점 : 문, 거울 설치할 수 있는 위치

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> b(n, vector<int>(n));
    vector<pair<int, int>> v;
    int start = -1, end =-1;
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '#') {
                if (start == -1) {
                    start = v.size();
                }
                else {
                    end = v.size();
                }
                v.push_back({i, j}); // 정점 삽입
                b[i][j] = v.size()-1; // 몇번 정점인지 저장
            }
            else if (s[i][j] == '!') {
                v.push_back({i, j}); // 정점 삽입
                b[i][j] = v.size()-1; // 몇번 정점인지 저장
            }
        }
    }
    
    int m = v.size(); // 정점의 크기
    vector<vector<bool>> a(m, vector<bool>(m, false));
    for (int i = 0; i < v.size(); i++) {
        for (int k = 0; k < 4; k++)  {
            int x = v[i].first+dx[k];
            int y = v[i].second+dy[k];
            while(0 <= x && x < n && 0 <= y && y < n) {
                if (s[x][y] == '*') break;
                if (s[x][y] == '!' || s[x][y] == '#') {
                    a[i][b[x][y]] = true;
                }
                x += dx[k];
                y += dy[k];
            }
        }
    }

    queue<int> q;
    vector<int> dist(m, -1);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < m; i++) {
            if (a[now][i] && dist[i] == -1) {
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }

    cout << dist[end]-1 << endl;

    return 0;
}
