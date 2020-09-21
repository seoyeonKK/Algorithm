#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> banking(n);
    for (int i = 0; i < n; i++) {
        cin >> banking[i];
    }

    sort(banking.begin(), banking.end()); // 오름차순 

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += (banking[i]*(n-i));
    }
    
    cout << answer << endl;

    return 0;
}
