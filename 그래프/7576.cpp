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
int n, m, noTomato;
queue < pair<int, int> > q;

/**
* 다 익었는지 체크 함수
**/
bool allRipe() {
	int possible = m*n - noTomato;
	int tomatoCnt = 0;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1)
				tomatoCnt++;
		}
	}
	// 익어야 할 토마토 갯수 == 익은 토마토 갯수
	return possible == tomatoCnt;
}

/**
* bfs 함수
**/
int bfs() {
	int nx, ny;
	int day = 0;
	pair <int, int> p;

	if (q.empty())
		return -1;

	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			p = q.front();
			for (int i = 0; i < 4; i++) {
				nx = p.second + LR[i];
				ny = p.first + UD[i];

				// arr[][] 범위 내에 속하는지 확인 (x범위 : 1 ~ n, y범위 : 1 ~ m) 
				if (ny >= 1 && nx >= 1 && ny <= m && nx <= n && arr[ny][nx] == 0) {
					arr[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
			q.pop();

			// 익힐 수 있는 토마토를 전부 익혔고 전부 익었을 경우
			if (q.size() == 0 && allRipe())
				return day;

			// 익힐 수 있는 토마토는 전부 익혔지만 안 익은 토마토 존재
			else if (q.size() == 0 && !allRipe())
				return -1;
		}
		day++;
	}
}

/**
* main 함수
**/
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1)
				q.push({ i,j });
			else if (arr[i][j] == -1)
				noTomato++; // 토마토를 넣을 수 없는 칸
		}
	}
	if (q.size() == m * n - noTomato) {
		cout << 0 << endl; // 모든 토마토 다 익었을 경우
	} else {
		int result = bfs(); // day 출력
		cout << result << endl;
	}
	return 0;
}