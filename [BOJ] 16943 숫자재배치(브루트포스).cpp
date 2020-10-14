#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string A;
int B;
int main() {
    cin >> A >> B;

    sort(A.begin(), A.end());

    int ans = -1;
    do {
        int C = stoi(A);
        if (A[0] != '0' && C < B) {
            if (ans == -1 || ans < C) {
                ans = C;
            }
        }
    } while(next_permutation(A.begin(), A.end()));

    cout << ans << endl;
    
    return 0;
}
