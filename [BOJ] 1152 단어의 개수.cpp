#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string S;
vector<string> v;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, S);

    stringstream ss(S);
    string str;

    while(ss >> str) {
        v.push_back(str);
    }

    cout << v.size();

    return 0;
}

