#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n = 0;
    int k = 0;
    queue <int> q;
    cin >> n >> k;

    // 사람들 queue에 넣기
    for (int i = 1; i < n + 1; i++) {
        q.push(i);
    }

    cout << "<";

    while(q.size()) {

        // 마지막 사람일 경우 출력 후 break
        if (q.size() == 1) {
            cout << q.front() << ">";
            q.pop();
            break;
        }

        // 중간 과정에 있는 사람 맨 뒤에 넣기
        for (int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }

        // (죽은 사람 + K -1) 번째 사람 pop
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    return 0;
}
