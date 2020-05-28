#include <iostream>
#include <vector>
using namespace std;

int N;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<string> v;
    int answer = 0;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        v.push_back(s);

        char before = v[i][0];
        vector<char> visited;
        bool flag = true;

        for (int j = 1; j < v[i].size(); j++) {
            if (before != v[i][j]) {
                bool isVisited = true;
                for (int k = 0; k < visited.size(); k++) {
                    if (visited[k] == v[i][j]) {
                        isVisited = false;
                        flag = false;
                        break;
                    }
                }
                if (!isVisited) break;

                visited.push_back(v[i][j]);
                before = v[i][j];
            }
        }
        if (flag) answer++;
    }
    cout << answer;

    return 0;
}
