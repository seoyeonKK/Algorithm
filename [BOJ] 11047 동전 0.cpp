#include <iostream>
#include <stack>
using namespace std;

int N, M;
int answer = 0;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    stack<int> coin;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        coin.push(num);
    }

    while(1) {
        if (M == 0) break;

        if (coin.top() > M) {
            coin.pop();
        }
        else {
            M -= coin.top();
            answer++;
        }
    }

    cout << answer;

    return 0;
}
