#include <iostream>
#include <queue>
#include <algorithm>
#define MAX_SIZE 20
using namespace std;

int N;
int block[MAX_SIZE][MAX_SIZE];
int ans;

int Max(int x, int y) { return x < y ? y : x; }

// copy from arr2 to arr1
void copy(int(*arr1)[MAX_SIZE], int(*arr2)[MAX_SIZE]) {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            arr1[i][j] = arr2[i][j];
        }
    }
}

// move
void move(int d) {
    queue<int> q;
    switch(d) {
        // 동
        case 0:
            for (int i = 0; i < N; i++) {
                for (int j = N-1; j >= 0; j--) {

                    if (block[i][j] != 0) {
                        q.push(block[i][j]);
                        block[i][j] = 0;
                    }
                }

                int num = 0;
                int idx = N-1;

                while(!q.empty()) {
                    num = q.front();
                    q.pop();

                    if (block[i][idx] == 0) block[i][idx] = num;
                    else if (block[i][idx] == num) {
                        block[i][idx] *= 2;
                        idx--;
                    }
                    else {
                        block[i][--idx] = num;
                    }
                }
            }
            break;

        // 서
        case 1:
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    if (block[i][j] != 0) {
                        q.push(block[i][j]);
                        block[i][j] = 0;
                    }
                }

                int num = 0;
                int idx = 0;

                while(!q.empty()) {
                    num = q.front();
                    q.pop();

                    if (block[i][idx] == 0) block[i][idx] = num;
                    else if (block[i][idx] == num) {
                        block[i][idx] *= 2;
                        idx++;
                    }
                    else {
                        block[i][++idx] = num;
                    }
                }
            }
            break;

        // 남
        case 2:
            for (int i = 0; i < N; i++) {
                for (int j = N-1; j >= 0; j--) {

                    if (block[j][i] != 0) {
                        q.push(block[j][i]);
                        block[j][i] = 0;
                    }
                }

                int num = 0;
                int idx = N-1;

                while(!q.empty()) {
                    num = q.front();
                    q.pop();

                    if (block[idx][i] == 0) block[idx][i] = num;
                    else if (block[idx][i] == num) {
                        block[idx][i] *= 2;
                        idx--;
                    }
                    else {
                        block[--idx][i] = num;
                    }
                }
            }
            break;

        // 북
        case 3:
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    if (block[j][i] != 0) {
                        q.push(block[j][i]);
                        block[j][i] = 0;
                    }
                }

                int num = 0;
                int idx = 0;

                while(!q.empty()) {
                    num = q.front();
                    q.pop();

                    if (block[idx][i] == 0) block[idx][i] = num;
                    else if (block[idx][i] == num) {
                        block[idx][i] *= 2;
                        idx++;
                    }
                    else {
                        block[++idx][i] = num;
                    }
                }
            }
            break;
    }
}


void dfs(int depth) {
   
    // 5번 이동 시 return
    if (depth == 5) {

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans = max(ans, block[i][j]); // Max값 찾기

        return;
    }

    int copyBlock[MAX_SIZE][MAX_SIZE];

    copy(copyBlock, block); // block을 copyBlock에 복

    // 동 서 남 북 이동
    for (int i = 0; i < 4; i++) {
        move(i);
        dfs(depth + 1); // 이동 시 depth 증가
        copy(block, copyBlock); // copyBlock을 block에 복사
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> block[i][j];
        }
    }

    dfs(0);

    cout << ans;
    return 0;
}
