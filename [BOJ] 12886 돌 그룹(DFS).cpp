#include <iostream>
#include <algorithm>
using namespace std;

int X, Y, Z;
int sum;
int a[3], b[3];
bool check[1501][1501];
void dfs(int x, int y) {
    if (check[x][y]) return;
    check[x][y] = true;
    int a[3] = {x, y, sum-x-y};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i] < a[j]) {
                int b[3] = {x, y, sum-x-y};
                b[i] += a[i];
                b[j] -= a[i];
                dfs(b[0], b[1]);
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> X >> Y >> Z;
    sum = X + Y + Z;

    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    dfs(X, Y);


    if (check[sum/3][sum/3]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}
