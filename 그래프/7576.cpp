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
* �� �;����� üũ �Լ�
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
	// �;�� �� �丶�� ���� == ���� �丶�� ����
	return possible == tomatoCnt;
}

/**
* bfs �Լ�
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

				// arr[][] ���� ���� ���ϴ��� Ȯ�� (x���� : 1 ~ n, y���� : 1 ~ m) 
				if (ny >= 1 && nx >= 1 && ny <= m && nx <= n && arr[ny][nx] == 0) {
					arr[ny][nx] = 1;
					q.push({ ny, nx });
				}
			}
			q.pop();

			// ���� �� �ִ� �丶�並 ���� ������ ���� �;��� ���
			if (q.size() == 0 && allRipe())
				return day;

			// ���� �� �ִ� �丶��� ���� �������� �� ���� �丶�� ����
			else if (q.size() == 0 && !allRipe())
				return -1;
		}
		day++;
	}
}

/**
* main �Լ�
**/
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 1)
				q.push({ i,j });
			else if (arr[i][j] == -1)
				noTomato++; // �丶�並 ���� �� ���� ĭ
		}
	}
	if (q.size() == m * n - noTomato) {
		cout << 0 << endl; // ��� �丶�� �� �;��� ���
	} else {
		int result = bfs(); // day ���
		cout << result << endl;
	}
	return 0;
}