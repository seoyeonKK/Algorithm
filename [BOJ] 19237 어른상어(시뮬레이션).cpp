#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Shark {
	int x;
	int y;
	int dir;
	int order[5][5];
	bool isdead;
};

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
int N, M, K;
int a[20][20];
pair<int, int> smell[20][20];
Shark shark[401];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j] > 0) {
				shark[a[i][j]].x = i;
				shark[a[i][j]].y = j;
				shark[a[i][j]].isdead = false;

				smell[i][j].first = a[i][j];
				smell[i][j].second = K;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> shark[i].dir;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 1; k <= 4; k++) {
				cin >> shark[i].order[j][k];
			}
		}
	}

	int ans = 1;

	while (ans <= 1000) {
		for (int i = 1; i <= M; i++) {
			if (shark[i].isdead) continue;

			bool go = false;
			for (int dir = 1; dir <= 4; dir++) {
				int nx = shark[i].x + dx[shark[i].order[shark[i].dir][dir]];
				int ny = shark[i].y + dy[shark[i].order[shark[i].dir][dir]];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N || smell[nx][ny].first != 0) {
					continue;
				}

				go = true;

				if (a[nx][ny] != 0) {
					if (a[nx][ny] < i) {
						shark[i].isdead = true;
						a[shark[i].x][shark[i].y] = 0;
						
					}
					else {
						shark[a[nx][ny]].isdead = true;
						a[nx][ny] = i;
						shark[i].x = nx;
						shark[i].y = ny;
						shark[i].dir = shark[i].order[shark[i].dir][dir];
					}
				}
				else {
					a[shark[i].x][shark[i].y] = 0;
					shark[i].x = nx;
					shark[i].y = ny;
					shark[i].dir = shark[i].order[shark[i].dir][dir];
					a[nx][ny] = i;
				}
				break;
			}

			if (!go) {
				for (int dir = 1; dir <= 4; dir++) {
					int nx = shark[i].x + dx[shark[i].order[shark[i].dir][dir]];
					int ny = shark[i].y + dy[shark[i].order[shark[i].dir][dir]];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
						continue;
					}

					if (smell[nx][ny].first == i) {
						a[shark[i].x][shark[i].y] = 0;
						shark[i].x = nx;
						shark[i].y = ny;
						shark[i].dir = shark[i].order[shark[i].dir][dir];
						a[nx][ny] = i;
						break;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (smell[i][j].first != 0) {
					smell[i][j].second--;
					if (smell[i][j].second == 0) {
						smell[i][j].first = 0;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] != 0) {
					smell[i][j].first = a[i][j];
					smell[i][j].second = K;
				}
			}
		}

		bool check = true;
		for (int i = 2; i <= M; i++) {
			if (!shark[i].isdead) {
				check = false;
				break;
			}
		}

		if (check) {
			cout << ans << endl;
			return 0;
		}
		else {
			ans++;
		}
	}

	cout << -1 << endl;

	return 0;
}
