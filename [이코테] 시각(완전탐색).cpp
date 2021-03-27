#include <iostream>
using namespace std;

bool check(int h, int m, int s) {
    return (h/10 == 3|| h%10 == 3 || m/10 == 3|| m%10 == 3 || s/10 == 3|| s%10 == 3);
}

int main () {
    int hour;
    cin >> hour;

    int count = 0;
    for (int i = 0; i <= hour; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                if (check(i, j, k)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
