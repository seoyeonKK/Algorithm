#include <iostream>
#include <queue>
#include <string>
#define SIZE 8
using namespace std;

int wheel[4][8];
queue<pair<int, int>> q;
int K;

void shiftRight(int i) {
    int temp;

    temp = wheel[i][SIZE - 1];

    for (int j = SIZE - 1; j > 0; j--) {
        wheel[i][j] = wheel[i][j-1];
    }

    wheel[i][0] = temp;
}

void shiftLeft(int i) {
    int temp;

    temp = wheel[i][0];

    for (int j = 0; j < SIZE - 1; j++) {
        wheel[i][j] = wheel[i][j+1];
    }

    wheel[i][SIZE - 1] = temp;
}

void checkLeft(int idx, int direction) {
    int i = idx;

    while(idx > 0) {
        if (wheel[idx][6] != wheel[idx-1][2]) idx--;
        else break;
    }

    for (int j = i - 1; j >= idx; j--) {
        if (direction == 1) {
            shiftLeft(j);
            direction = -1;
        }
        else if (direction == -1) {
            shiftRight(j);
            direction = 1;
        }
    }
}

void checkRight(int idx, int direction) {
    int i = idx;

    while(idx < 3) {
        if (wheel[idx][2] != wheel[idx + 1][6]) idx++;
        else break;
    }

    for (int j = i + 1; j <= idx; j++) {
        if (direction == 1) {
            shiftLeft(j);
            direction = -1;
        }
        else if (direction == -1) {
            shiftRight(j);
            direction = 1;
        }
    }
}

void move() {

    while(!q.empty()) {

        if (1 == q.front().second) {
            checkLeft(q.front().first, q.front().second);
            checkRight(q.front().first, q.front().second);
            shiftRight(q.front().first);
        }
        else if (-1 == q.front().second) {
            checkLeft(q.front().first, q.front().second);
            checkRight(q.front().first, q.front().second);
            shiftLeft(q.front().first);
        }

        q.pop();
    }

}

int score() {
    int sum = 0;

    if (wheel[0][0] == 1) sum += 1;
    if (wheel[1][0] == 1) sum += 2;
    if (wheel[2][0] == 1) sum += 4;
    if (wheel[3][0] == 1) sum += 8;

    return sum;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            wheel[i][j] = s[j] - '0';
        }
    }

    cin >> K;

    for (int i = 0; i < K; i++) {
        int n, m;
        cin >> n >> m;

        q.push({ n-1, m });
    }

    move();

    cout << score();

    return 0;
}
