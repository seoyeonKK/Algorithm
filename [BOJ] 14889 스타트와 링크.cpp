
#include <iostream>
#define MAX 22
#define INF 987654321
using namespace std;

bool check[MAX];
int map[MAX][MAX];
int N, ans = INF;

void DFS(int d, int pos) {
    if (d == N / 2) {
        int start, link;

        start = link = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (check[i] && check[j]) start += map[i][j];
                if (!check[i] && !check[j]) link += map[i][j];
            }
        }

        int tmp = abs(start - link);

        if (tmp < ans) ans = tmp;

        return;
    }

    for (int i = pos; i < N; i++) {
        check[i] = true;
        DFS(d + 1, i + 1);
        check[i] = false;
    }
}

int main(void) {
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    DFS(0, 1);

    cout << ans << endl;

    return 0;
}
