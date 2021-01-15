#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        auto it = lower_bound(a.begin(), a.end(), num);
        if (it == a.end()) {
            a.push_back(num);
        } else {
            *it = num;
        }
    }
    cout << a.size() << '\n';
    return 0;
}
