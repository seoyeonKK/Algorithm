#include <iostream>
#include <vector>
using namespace std;

pair<int, int> calc(vector<int> &v, int idx, int value, int plus, int minus, int mul, int div) {
    if (idx == v.size()) {
        return {value, value};
    }

    vector<pair<int, int>> result;

    if (plus > 0) {
        result.push_back(calc(v, idx+1, value+v[idx], plus-1, minus, mul, div));
    }
    if (minus > 0) {
        result.push_back(calc(v, idx+1, value-v[idx], plus, minus-1, mul, div));
    }
    if (mul > 0) {
        result.push_back(calc(v, idx+1, value*v[idx], plus, minus, mul-1, div));
    }
    if (div > 0) {
        result.push_back(calc(v, idx+1, value/v[idx], plus, minus, mul, div-1));
    }

    auto res = result[0];

    for (int i = 1; i < result.size(); i++) {
        if (res.first < result[i].first) {
            res.first = result[i].first;
        }
        if (res.second > result[i].second) {
            res.second = result[i].second;
        }
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    vector<int> num;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        num.push_back(n);
    }

    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    auto ans = calc(num, 1, num[0], plus, minus, mul, div);

    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;
}
