#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    vector<string> v;
    int answer = 0;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        v.push_back(s);

        vector<char> visited;
        bool flag = true;
        char before = v[i][0];
        visited.push_back(before);

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
