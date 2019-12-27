#include<iostream>
#include <queue>
using namespace std;
int a[9][9];
int n, miss;
queue<int> change;

bool impossible(int num, int x, int y) {
    int rx = x / 3 * 3, ry = y / 3 * 3;
    for (int i = 0; i < 9; i++)
        if (a[x][i] == num || a[i][y] == num) return false;
    for (int i = rx; i < rx + 3; i++)
        for (int j = ry; j < ry + 3; j++)
            if (a[i][j] == num) return false;
    return true;
}

void go(int num) {
    int x = 0, y = 0;
    int count = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            x = i, y = j;
            if (!impossible(a[i][j], x, y)) {
                for (int k = 1; k < 10; k++) {
                    if (k == a[i][j]) continue;
                    if (impossible(k, x, y)) {
                        a[x][y] = k;
                        change.push(x+1);
                        change.push(y+1);
                        change.push(k);
                        count++;
                    }
                    if (count == miss) break;
                }
            }
        }
        if (count == miss) break;
    }

    unsigned long size;
    size = change.size();

    cout << "#" << num+1 << " ";
    for (int j = 0; j < size; j++) {
        if (!change.empty()) {
            cout << change.front() << " ";
            change.pop();
        }
    }
    cout << endl;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> miss;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> a[i][j];

        go(i);
    }
    return 0;
}
