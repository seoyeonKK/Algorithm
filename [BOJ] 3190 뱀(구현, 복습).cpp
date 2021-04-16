#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100
using namespace std;

int N, K, L;
int map[MAX][MAX];
bool apple[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main () {
    cin >> N;
    cin >> K;

    // 사과 위치 표시
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        apple[r-1][c-1] = true;
    }
    // map[][] -1로 초기화
    memset(map,-1,sizeof(map));
    int now = 0; // 현재시간
    int len = 1; // 뱀의 길이
    int dir = 0; // 뱀의 방향
    int x = 0, y = 0; // 뱀의 위치
    map[0][0] = 0; // 처음 위치 0으로 표시

    cin >> L;

    // 명령어가 끝난 이후에도 이동하기 때문에 for문 i<=L 까지 돈다.
    for (int i = 0; i <= L; i++) {
        int t = N * N + 1; // 최대 시간으로 초기화 (밑에 while문에서 무한루프와 같은 역할)
        char cmd = 'L'; // cmd 값 초기화

        if (i < L) {
            cin >> t >> cmd;
        }
        // t초까지 뱀 이동
        while (now < t) {
            now += 1;
            x += dx[dir];
            y += dy[dir];
            // 범위를 벗어나면 종료
            if (x < 0 || x >= N || y < 0 || y >= N) {
                cout << now << endl;
                return 0;
            }
            // 사과가 있으면 먹고, 뱀의 길이 +1 증가
            if (apple[x][y]) {
                apple[x][y] = false;
                len += 1;
            }
            // 전에 방문하고, 차이가 길이보다 작거나 같으면 이동 안 함
            if (map[x][y] != -1 && now - map[x][y] <= len) {
                cout << now << endl;
                return 0;
            }
            map[x][y] = now; // 머리 위치에 현재 시간 표시
        }
        // while문 빠져나온 뒤 방향 변경
        if (cmd == 'L') {
            dir = (dir + 3) % 4;
        }
        else {
            dir = (dir + 1) % 4;
        }
    }

    return 0;
}
