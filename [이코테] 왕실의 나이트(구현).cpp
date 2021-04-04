#include <iostream>
#include <vector>
#define SIZE 8
using namespace std;

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2};

int main () {
    string s;
    cin >> s;
    int x = s[0]-'a', y = s[1]-'0'-1; // ascii 코드 변환
    int count = 0;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
