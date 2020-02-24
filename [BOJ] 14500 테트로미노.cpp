#include <iostream>
#include <algorithm>
#define MAX_SIZE 500
using namespace std;

int N, M, MAX = 0;
int map[MAX_SIZE][MAX_SIZE] = {0, };
bool visited[MAX_SIZE][MAX_SIZE] = {0, };

// 동 서 북 남
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inRange(int x, int y) {
    if (x < 0 || x >= N || y < 0  || y >= M)
        return false;
    else
        return true;
}

// 'ㅗ', 'ㅏ', 'ㅓ', 'ㅜ' 를 제외한 모든 모양에 해당되는 dfs 함수
void move(int x, int y, int count, int sum) {
    
    // 조각 4개가 모였다면 max 업뎃
    if (count == 4) {
        MAX = max(MAX, sum);
        return;
    }

    // 동 서 남 북 dfs
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inRange(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            move(nx, ny, count+1,  sum + map[nx][ny]);
            visited[nx][ny] = 0;
        }
    }
}

// 'ㅗ', 'ㅏ', 'ㅓ', 'ㅜ' 에 해당되는 dfs로 처리 불가한 모양
void specialShape(int x, int y) {
    for (int i = 0; i < 4; i++){
        int sum = map[x][y];
        bool flag = true;
        
        // 중심을 제외하고 상, 하, 좌, 우 중 3개 
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[(i+j) % 4];
            int ny = y + dy[(i+j) % 4];

            if (inRange(nx, ny)) {
                sum += map[nx][ny];
            }
            else {
                flag = false;
                break;
            }
        }

        if (flag) {
            MAX = max(MAX, sum);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N*M; i++) {
        int x = i / M; // 행
        int y = i % M; // 열

        visited[x][y] = 1;

        move(x, y, 1, map[x][y]); // dfs start
        specialShape(x, y); // specialShape start

        visited[x][y] = 0; // dfs 후 visit[][] 0 처리
    }

    cout << MAX << endl;

    return 0;
}
