#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    // 오름차순으로 sorting
    sort(people.begin(), people.end());

    int cnt = 0, result = 0;
    for (int i = 0; i < n; i++) {
        // cnt가 써져있는 갯수랑 같다면 그룹으로 만든다.
        cnt += 1;
        if  (cnt >= people[i]) {
            result += 1;
            cnt = 0;
        }
    }

    cout << result << endl;
    
    return 0;
}
