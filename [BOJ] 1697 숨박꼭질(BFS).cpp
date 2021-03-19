#include <iostream>
#include <queue>
using namespace std;

bool inRange(int x) {
    return (x >= 0 && x <= 100000);
}

int main() {
    int start, finish;
    int time = 0;
    int visited[100001] = {0, };
    cin >> start >> finish;

    queue<pair<int, int>> q;

    q.push({ finish, time });

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        time = cur.second;
        visited[cur.first] = 1;

        if (cur.first == start) {
            cout << cur.second << endl;
            return 0;
        }

        if (cur.first%2 == 0) {
            if (inRange(cur.first/2) && !visited[cur.first/2]) {
                visited[cur.first/2] = 1;
                q.push({ cur.first/2, time+1 });
            };
        }

        if (inRange(cur.first-1) && !visited[cur.first-1]) {
            visited[cur.first-1] = 1;
            q.push({ cur.first-1, time+1 });
        };
        if (inRange(cur.first+1) && !visited[cur.first+1]) {
            visited[cur.first+1] = 1;
            q.push({ cur.first+1, time+1 });
        };
    }

    return 0;
}
