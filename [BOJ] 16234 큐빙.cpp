#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int N, L, R;
bool chk = true;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int visited[50][50];
int ch;
int ans = 0;
queue<pair<int, int>> q;
queue<pair<int, int>> pos;

bool inRange(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) return 0;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    while (chk){
        ch++;
        chk = false;
        ans += 1;

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j] == ch) continue;

                int sum = map[i][j];

                q.push({ j, i });
                pos.push({ j, i });
                visited[i][j] = ch;

                while (!q.empty()){
                    int x_tmp = q.front().first;
                    int y_tmp = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++){
                        int x = x_tmp + dx[k];
                        int y = y_tmp + dy[k];

                        if (!inRange(x, y) || visited[y][x] == ch || abs(map[y_tmp][x_tmp] - map[y][x]) < L || abs(map[y_tmp][x_tmp] - map[y][x])>R)
                            continue;

                        chk = true;

                        q.push({ x, y });
                        pos.push({ x, y });

                        sum += map[y][x];
                        visited[y][x] = ch;
                    }

                }

                int avr = sum / pos.size();

                while (!pos.empty()){
                    map[pos.front().second][pos.front().first] = avr;
                    pos.pop();
                }
            }
        }

    }
    cout << ans - 1;

    return 0;
}
