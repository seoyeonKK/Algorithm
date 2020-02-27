#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000000001
using namespace std;

int N;
vector<int> num;
int oper[4] = {0,};
int maxResult = -MAX, minResult = MAX;

void DFS(int plus, int minus, int multiply, int divide, int cnt, int sum) {

    // 연산자를 모두 사용하였을 경우
    if (cnt == N) {
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
    }

    // 모든 경우를 고려
    if (plus > 0)
        DFS(plus - 1, minus, multiply, divide, cnt + 1, sum + num[cnt]);

    if (minus > 0)
        DFS(plus, minus - 1, multiply, divide, cnt + 1, sum - num[cnt]);

    if (multiply > 0)
        DFS(plus, minus, multiply - 1, divide, cnt + 1, sum * num[cnt]);

    if (divide > 0)
        DFS(plus, minus, multiply, divide - 1, cnt + 1, sum / num[cnt]);

}



int main() {
    int M;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M;
        num.push_back(M);
    }

    for (int i = 0; i < 4; i++)
        cin >> oper[i];

    DFS(oper[0], oper[1], oper[2], oper[3], 1, num[0]);

    cout << maxResult << endl;
    cout << minResult << endl;

    return 0;
}