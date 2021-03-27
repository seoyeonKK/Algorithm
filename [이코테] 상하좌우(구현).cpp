#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n;
int dx[] = {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

bool inRange(int nx, int ny) {
    return (nx > 0 && nx <= n && ny > 0 && ny <= n);
}

int main () {
    cin >> n;
    vector<vector<int>> map(n+1, vector<int> (n+1));

    string dir;
    cin.ignore(); // 버퍼 지우기
    getline(cin, dir); // 한 줄 입력 받기

    int x = 1, y = 1;
    for (int i = 0; i < dir.size(); i++) {
        int nx, ny;
        if (dir[i] == 'U') {
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if (dir[i] == 'D') {
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if (dir[i] == 'L') {
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else if (dir[i] == 'R') {
            nx = x + dx[3];
            ny = y + dy[3];
        }

        if (inRange(nx, ny)) {
            x = nx;
            y = ny;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}
