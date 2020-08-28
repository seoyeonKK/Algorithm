#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;

bool check(vector<char> &inequality, vector<int> &perm) {
    for (int i = 0; i < inequality.size(); i++) {
        if (inequality[i] == '<' && perm[i] > perm[i+1]) {
            return false;
        }
        if (inequality[i] == '>' && perm[i] < perm[i+1]) {
            return false;
        }
    }
    return true;
}

 int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> K;

    vector<char> inequality;
    vector<int> big(K+1);
    vector<int> small(K+1 );

    for (int i = 0; i < K; i++) {
        char c;
        cin >> c;

        inequality.push_back(c);
    }

    for (int i = 0; i < K+1; i++) {
        small[i] = i;
        big[i] = 9 - i;
    }

    while(1) {
        if (check(inequality, small)) {
            break;
        }

        next_permutation(small.begin(), small.end());
    }

    while(1) {
        if (check(inequality, big)) {
            break;
        }

        prev_permutation(big.begin(), big.end());
    }

    for (int i = 0; i < big.size(); i++) {
        cout << big[i];
    }
    cout << endl;
    for (int i = 0; i < small.size(); i++) {
        cout << small[i];
    }

    return 0;
}
