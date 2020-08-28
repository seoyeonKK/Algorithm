#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> num;

int calc(vector<int> &num, vector<int> &oper) {
    int result = num[0];
    for (int i = 1; i < num.size(); i++) {
        if (oper[i-1] == 0) {
            result = result + num[i];
        }
        else if (oper[i-1] == 1) {
            result = result - num[i];
        }
        else if (oper[i-1] == 2) {
            result = result * num[i];
        }
        else if (oper[i-1] == 3) {
            result = result / num[i];
        }
    }

    return result;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        num.push_back(K);
    }

    vector<int> oper;
    for (int i = 0; i < 4; i++) {
        int cnt;
        cin >> cnt;

        for (int j = 0; j < cnt; j++)
            oper.push_back(i);
    }

    vector<int> result;

    do {
        int temp = calc(num, oper);
        result.push_back(temp);
    }
    while(next_permutation(oper.begin(), oper.end()));

    auto answer = minmax_element(result.begin(), result.end());

    cout << *answer.second << endl;
    cout << *answer.first << endl;

    return 0;
}
