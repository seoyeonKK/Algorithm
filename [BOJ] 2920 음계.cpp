#include <iostream>
#include <vector>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string state;

    for (int i = 1; i <= 8; i++) {
        int num;
        cin >> num;

        if ((num == i) && (state != "descending")) {
            state = "ascending";
        }
        else if ((num == 8-i+1) && (state != "ascending")) {
            state = "descending";
        }
        else {
            state = "mixed";
            break;
        }
    }

    cout << state;

    return 0;
}
