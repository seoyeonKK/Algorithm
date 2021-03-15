#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
using namespace std;

int n;
int dump = 0;
int arr[MAX][MAX];
int sand[4][5][5] =
                  // 서
                 {{{0, 0, 2, 0, 0},
                  {0, 10, 7, 1, 0},
                  {5, 0, 0, 0, 0},
                  {0, 10, 7, 1, 0},
                  {0, 0, 2, 0, 0}},
                   // 남
                  {{0, 0, 0, 0, 0},
                   {0, 1, 0, 1, 0},
                   {2, 7, 0, 7, 2},
                   {0, 10, 0 , 10, 0},
                   {0, 0, 5, 0, 0}},
                   // 동
                  {{0, 0, 2, 0, 0},
                   {0, 1, 7, 10, 0},
                   {0, 0, 0, 0, 5},
                   {0, 1, 7, 10, 0},
                   {0, 0, 2, 0, 0}},
                   // 북
                  {{0, 0, 5, 0, 0},
                   {0, 10, 0 , 10, 0},
                   {2, 7, 0, 7, 2},
                   {0, 1, 0, 1, 0},
                   {0, 0, 0, 0, 0}}};

void sandMove(int r, int c, int dir) {
    int total = 0;
    
    // arr[i][j]은 기존의 모래를 (0,0)부터 탐색하는 idx, sand[dir][a][b]은 추가되는 모래 비율을 (0,0)부터 탐색하는 idx
    // (r-2, c-2)를 한 이유는 현재 (r,c)가 중간 idx를 가리키고 있기 때문 
    for (int i = r-2, a = 0; i <= r+2; i++, a++) { // a 동시 증가
        for (int j = c-2, b = 0; j <= c+2; j++, b++) { // b 동시 증가
            int extra = sand[dir][a][b] * arr[r][c] * 0.01; // 추가될 모래 양 구하기
            total += extra; // 추가된 total 모래
            
            // 범위 내라면 모래를 추가한다.
            if (i >= 0 && i < n && j >= 0 && j < n) {
                arr[i][j] = arr[i][j] + extra;
            }
            // 범위 밖이라면 나가 떨어진다.
            else {
                dump += extra;
            }
        }
    }

    int rest = arr[r][c] - total; // 남은 모래양

    // 각 a 자리에 rest 모래를 추가한다. 
    // r-1, r+1, c-1, c+1 각 범위 체크 해준다. 안하면 idx 에러 발생 (더 좋은 범위 체크 방식이 있을까...?)
    if (dir%4 == 0) {
        if (c-1 >= 0)
            arr[r][c-1] += rest;
        else
            dump += rest;
    }
    else if (dir%4 == 1) {
        if (r+1 < n)
            arr[r+1][c] += rest;
        else
            dump += rest;
    }
    else if (dir%4 == 2) {
        if (c+1 < n)
            arr[r][c+1] += rest;
        else
            dump += rest;
    }
    else if (dir%4 == 3) {
        if (r-1 >= 0)
            arr[r-1][c] += rest;
        else
            dump += rest;
    }
    arr[r][c] = 0; // 기존 자리를 꼭 0으로 초기화 해준다.
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int r, c;
    r = c = n/2; // 정 중앙 idx (r,c)
    
    // 회전 횟수
    for (int i = 0; i < n*2-1; i++) {
        int dir = i%4; // 0: 서, 1 : 남, 2 : 동, 3: 북
        int count = i/2+1; // 각 회전마다의 블록 이동 횟수 (0, 1) 번째 회전 -> (1칸이동), (2, 3) 번째 회전 -> (2칸이동) 규칙을 따른다. 단 마지막 회전때는 한 번 덜 이동한다.
        
        // 마지막 회전이라면 count-1
        if (i == n*2-2) {
            count -= 1;
        }

        // dir 방향대로 한 칸 이동 후 sandMove() 실행
        for (int j = 0; j < count; j++) {
            if (dir == 0) {
                c = c - 1;
            }
            else if (dir == 1) {
                r = r + 1;
            }
            else if (dir == 2) {
                c = c + 1;
            }
            else if (dir == 3) {
                r = r - 1;
            }
            sandMove(r, c, dir);
        }
    }

    cout << dump << endl;

    return 0;
}
