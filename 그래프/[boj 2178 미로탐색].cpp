#include <queue>
#include <iostream>
#include <cstdio>
#pragma warning(disable : 4996)

using namespace std;

#define MAX 101
using namespace std;
int arr[MAX][MAX];
int visited[MAX][MAX];
int LR[4] = { 1,-1,0,0 };
int UD[4] = { 0,0,1,-1 };
queue < pair<int, int> > q;


void bfs() {
	int nx, ny;
	q.push({ 1,1 });
	pair <int, int> p;

	while (!q.empty()) {

		p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = p.second + LR[i];
			ny = p.first + UD[i];
			if (arr[ny][nx] != 0 && !visited[ny][nx]) {
				arr[ny][nx] = arr[p.first][p.second] + 1;
				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	bfs();
	cout << arr[n][m];
	return 0;
}
