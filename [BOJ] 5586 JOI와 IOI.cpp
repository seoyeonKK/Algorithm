#include <iostream>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 실행속도 향상

    string s;
    int countJ = 0, countI = 0;

    cin >> s;

    for (int i = 2; i < s.length(); i++) {
        string sub = s.substr(i-2, 3);

        if (sub == "JOI") {
            countJ++;
        }
        else if (sub == "IOI") {
            countI++;
        }
    }

    cout << countJ << endl;
    cout << countI << endl;

    return 0;
}
