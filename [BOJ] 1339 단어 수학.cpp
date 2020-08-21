#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long N, ans;
long long arr[27] = {0,};
vector<long long> V;
string S;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S;
        int cnt = 1;
        for (int j = S.length() - 1; j >= 0; j--) {
            arr[S[j] - 'A'] += cnt;
            cnt *= 10;
        }
    }

    // 각 글자수를 sort
    for (int i = 0; i < 27; ++i)
        if(arr[i]!=0) V.push_back(arr[i]);

    sort(V.begin(),V.end());

    // 글자수 많은게 높은 값을 갖게 함.
    int value = 9;
    for (int i = V.size()-1; i >= 0; i--){
        ans += V[i]*value;
        value--;
    }

    cout << ans << endl;

    return 0;
}
