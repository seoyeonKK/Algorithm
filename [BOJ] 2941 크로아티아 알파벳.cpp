#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;

    int answer = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S.substr(i, 2) == "c=" || S.substr(i, 2) == "c-" || S.substr(i, 2) == "d-" || S.substr(i, 2) == "s=" || S.substr(i, 2) == "z="  ) {
            answer += 1;
            i++;
        }
        else if (S.substr(i, 2) == "lj" || S.substr(i, 2) == "nj" ) {
            answer += 1;
            i++;
        }
        else if (S.substr(i, 3) == "dz=") {
            answer += 1;
            i += 2;
        }
        else {
            answer += 1;
        }
    }

    cout << answer;

    return 0;
}

