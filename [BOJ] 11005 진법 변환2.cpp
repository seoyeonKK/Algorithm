#include <iostream>
#include <stack>
using namespace std;

int N, B;
stack<int> s;
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;

    while(1) {
        s.push(N%B);
        N = N/B;
        if (N <= 0) break;
    }

    while(!s.empty()) {
        int num = s.top();
        if (num >= 10) {
            char c = num - 10 + 'A';
            cout << c;
        }
        else {
            cout << num;
        }
        s.pop();
    }

    return 0;
}

