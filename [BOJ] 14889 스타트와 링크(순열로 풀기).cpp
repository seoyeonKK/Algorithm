#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    vector<int> team(N);
    for (int i = 0; i < N/2; i++) {
        team[i] = 1;
    }

    sort(team.begin(), team.end()); // 0000~1111 순서로 정렬

    int answer = 2147483647;
    do {
        vector<int> start, link;
        for (int i = 0; i < N; i++) {
            if (team[i] == 0) start.push_back(i);
            else link.push_back(i);
        }

        int start_score = 0;
        int link_score = 0;
        for (int i = 0; i < N/2; i++) {
            for (int j = 0; j < N/2; j++) {
                if (i == j) continue;
                start_score += arr[start[i]][start[j]];
                link_score += arr[link[i]][link[j]];
            }
        }
        int diff = start_score - link_score;
        if (diff < 0) diff *= -1;
        if (answer > diff) answer = diff;
    }
    while(next_permutation(team.begin(), team.end()));

    cout << answer << endl;

    return 0;
}
