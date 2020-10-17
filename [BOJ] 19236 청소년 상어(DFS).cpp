#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 4
using namespace std;

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct FISH {
	int x;
	int y;
	int dir;
	bool isdead;
	FISH() {};
	FISH(int a, int b, int c, bool d) : x(a), y(b), dir(c), isdead(d) {};
};

void copyMap(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void copyFish(FISH a[17], FISH b[17]) {
	for (int i = 0; i < 17; i++) {
		a[i] = b[i];
	}
}

int dfs(int origin_map[SIZE][SIZE], int x, int y, int dir, FISH origin_fish[17]) {
	int map[SIZE][SIZE];
	FISH fish[17];
	copyMap(map, origin_map);
	copyFish(fish, origin_fish);

	int eat = map[x][y]; // 먹는 상어의 num
	dir = fish[eat].dir;

	fish[eat].x = -1;
	fish[eat].y = -1;
	fish[eat].isdead = true;
	map[x][y] = 0;

	int ans = 0;

	for (int i = 1; i < 17; i++) {
		if (!fish[i].isdead) {
			int nx = fish[i].x;
			int ny = fish[i].y;
			for (int k = 0; k < 8; k++) {
				int fx = nx + dx[fish[i].dir];
				int fy = ny + dy[fish[i].dir];
				
				if (fx == x && fy == y) {
					fish[i].dir = (fish[i].dir + 1) % 8;
					continue;
				}
				if (fx < 0 || fx >= SIZE || fy < 0 || fy >= SIZE) {
					fish[i].dir = (fish[i].dir + 1) % 8;
					continue;
				}

				nx = fx;
				ny = fy;
				break;
			}

			if (map[nx][ny] == 0) {
				map[fish[i].x][fish[i].y] = 0;
				map[nx][ny] = i;
				fish[i].x = nx;
				fish[i].y = ny;
			}
			else {
				int tx, ty;
				tx = fish[i].x;
				ty = fish[i].y;
				fish[i].x = nx;
				fish[i].y = ny;
				fish[map[nx][ny]].x = tx;
				fish[map[nx][ny]].y = ty;
				map[tx][ty] = map[nx][ny];
				map[nx][ny] = i;
			}
		}
	}

	int sx = x + dx[dir];
	int sy = y + dy[dir];

	while (sx >= 0 && sx < SIZE && sy >= 0 && sy < SIZE) {
		if (map[sx][sy] != 0) {
			ans = max(ans, dfs(map, sx, sy, dir, fish));
		}
		sx += dx[dir];
		sy += dy[dir];
	}
	return ans + eat;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int map[SIZE][SIZE];
	FISH fish[17];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			int num, dir;
			cin >> num >> dir;
			fish[num].x = i;
			fish[num].y = j;
			fish[num].dir = dir-1;
			fish[num].isdead = false;
			map[i][j] = num;
		}
	}

	cout << dfs(map, 0, 0, 0, fish) << endl;

	return 0;
}
