#include <iostream>
#include <vector>
#define MAX 50
#define INF 987654321
using namespace std;

int N, M;
int map[MAX][MAX];
bool visited[13];
int result = INF;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int getDistance(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}


void DFS(int idx, int count) {

    if (count == M) {
        int sumDist = 0;

        for (int i = 0; i < house.size(); i++) {
            int dist = INF;

            for (int j = 0; j < chicken.size(); j++) {
                if (visited[j]) {
                    dist = min(dist, getDistance(house[i], chicken[j]));
                }
            }

            sumDist += dist;
        }

        result = min(result, sumDist);

        return;
    }

    if (idx == chicken.size()) return;

    // 프랜차이즈 선정
    visited[idx] = true;
    DFS(idx+1, count+1);

    // 프랜차이즈 선정 X
    visited[idx] = false;
    DFS(idx + 1, count);

}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 1) {
                house.push_back({ i, j });
            }
            else if (map[i][j] == 2) {
                chicken.push_back({ i, j });
            }

        }
    }

    DFS(0, 0);

    cout << result << endl;

    return 0;
}
