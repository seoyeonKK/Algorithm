#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    int N, M;
    scanf("%d", &N);
    vector<int> card(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &card[i]);
    }
    sort(card.begin(), card.end());
    scanf("%d", &M);
    int find;
    for (int i = 0; i < M; i++) {
        scanf("%d", &find);
        int left = 0;
        int right = N-1;
        bool check = false;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (card[mid] == find) {
                printf("1");
                check = true;
                break;
            }
            else if (card[mid] > find) {
                right = mid - 1;
            }
            else if (card[mid] < find) {
                left = mid + 1;
            }
        }
        if (!check) printf("0");
        if (i != M-1) printf(" ");
    }

  return 0;
}
