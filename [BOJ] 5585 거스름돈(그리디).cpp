#include <iostream>
#define SIZE 6
using namespace std;

int coin[SIZE] = {500, 100, 50, 10, 5, 1};

int main() {
    int n;
    int change, count = 0;
    cin >> n;

    change = 1000 - n;
    for (int i = 0; i < SIZE; i++) {
        while(change-coin[i] >= 0) {
            change -= coin[i];
            count++;

            if (change == 0) // 모두 반환했을 시 탈출
                break;
        }
    }

    cout << count << endl;

    return 0;
}
