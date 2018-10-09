#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000;
int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx) {
	cout << idx << " ";
	for (int i = 1; i < N; i++) {
		if (adjacent[idx][i] && !visited[i]) {
			visited[i] = 1;
			DFS(i);
		}
	}
}

void BFS(int idx) {
	
	q.push(idx);
	visited[idx] = 1;

	while (!q.empty()) {
		idx = q.front();
		q.pop();

		cout << idx << " ";

		for (int i = 1; i <= N; i++) {
			if (adjacent[idx][i] && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main(void) {
	cin >> M >> N >> V;

	for (int i = 0; i <= M; i++) {
		int from, to;
		cin >> from >> to;
		adjacent[from][to] = 1;
		adjacent[to][from] = 1;
	}

	visited[V] = 1;
	DFS(V);
	cout << endl;
	
	memset(visited, false, sizeof(visited));
	BFS(V);
	cout << endl;

	return 0;
}