#include <iostream>
using namespace std;

int n, m;
int u, v;
int cnt;
bool visit[1001];
bool map[1001][1001];

void dfs(int x) {
	visit[x] = true;

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && map[x][i]) {
			dfs(i);
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}
