#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
vector<int> v;

int binarySearch(int low, int high, int target) {
    if (low > high)
        return 0;
    else {
        int mid = (low + high) / 2;

        if (v[mid] == target) {
            return 1;
        }
        else if (v[mid] > target) {
            return binarySearch(low, mid-1, target);
        }
        else if (v[mid] < target) {
            return binarySearch(mid+1, high, target);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;

        cout << binarySearch(0, N-1, num) << "\n";
    }
    return 0;
}
