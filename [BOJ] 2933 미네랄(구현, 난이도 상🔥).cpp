#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 111
using namespace std;

int R, C;
int N;
char map[MAX][MAX];
int check[MAX][MAX];
vector<pair<int, int>> group;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int x, int y) {
    if (map[x][y] == '.') return;
    if (check[x][y]) return;
    check[x][y] = true;
    group.push_back({ x, y });
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
            dfs(nx, ny);
        }
    }
}

void go() {
    memset(check, false, sizeof(check)); // 미네랄이 땅으로 떨어지면 더이상 이동하지 않겠다.
    for (int x = 0; x < R; x++) {
        for (int y = 0; y < C; y++) {
            if (map[x][y] == '.') continue;
            if (check[x][y]) continue;
            group.clear();
            dfs(x, y);
            vector<int> low(C, -1); // 각 열마다 가장 밑에있는 미네랄이 어디에 있는지 체크
            for (auto &p : group) {
                low[p.second] = max(low[p.second], p.first); // 각 열마다 얼마나 큰 행에 들어있는지
                map[p.first][p.second] = '.'; // 이동할 거니까 빈칸으로 만듬
            }
            int lowest = R; // 몇 칸 이동할지
            // 내려가는 칸 수 계산
            for (int i,j = 0; j < C; j++) {
                if (low[j] == -1) continue;
                for (i=low[j]; i < R && map[i][j] == '.'; i++);
                lowest = min(lowest, i-low[j]-1);
            }
            // lowest만큼 내려가기
            for (auto &p : group) {
                p.first += lowest;
                map[p.first][p.second] = 'x';
                check[p.first][p.second] = true;
            }

        }
    }
}

int main () {
     cin >> R >> C;
     for (int i = 0; i < R; i++) 
         cin >> map[i];
     cin >> N;
     
     for (int i = 0; i < N; i++) {
         int height;
         cin >> height;
         height = R-height;
         // 왼쪽에서 던짐
         if (i%2 == 0) {
             for (int j = 0; j < C; j++) {
                 if (map[height][j] == 'x') {
                     map[height][j] = '.';
                     break;
                 }
             }
         }
         // 오른쪽에서 던짐
         else {
             for (int j = C-1; j >= 0; j--) {
                 if (map[height][j] == 'x') {
                     map[height][j] = '.';
                     break;
                 }
             }
         }
         go();
     }
     for (int i = 0; i < R; i++) {
         cout << map[i] << endl;
     }
     
    return 0;
}
