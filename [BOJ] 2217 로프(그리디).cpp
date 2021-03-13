#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n;
    int answer = 0;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end(), greater<int>()); // DESC sorting

    for (int i = 0; i < num.size(); i++) {
        // i번째 중량만큼 i+1 갯수씩 나눠가진다. 
        // i번쨰 중량 * (i + 1)
        answer = max(answer, num[i] * (i+1)); // 각 계산한 수 중에서 max 값을 고른다.
    }

    cout << answer << endl;

    return 0;
}
