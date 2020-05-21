#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

int N;

void insertString(string s, vector<char> &v) {
    bool checkDoubleSpace = false;
    for (int j = 0; j < s.length(); j++) {
        if (s[j] == ' ') {
            if ((!isspace(s[j-1]) && !isdigit(s[j-1]) && !isalpha(s[j-1])) || (!isspace(s[j+1]) && !isdigit(s[j+1]) && !isalpha(s[j+1])) || checkDoubleSpace || j == 0 || j == s.length()-1) {
                checkDoubleSpace = true;
                continue;
            }
            v.push_back(s[j]);
            checkDoubleSpace = true;
        }
        else if (s[j] == '{' || s[j] == '[') {
            v.push_back('(');
            checkDoubleSpace = false;
        }
        else if (s[j] == '}' || s[j] == ']') {
            v.push_back(')');
            checkDoubleSpace = false;
        }
        else if (s[j] == ';') {
            v.push_back(',');
            checkDoubleSpace = false;
        }
        else {
            v.push_back(toupper(s[j]));
            checkDoubleSpace = false;
        }
    }
}

string checkEqual(vector<char> &v1, vector<char> &v2) {

    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return "not equal";
        }
    }
    return "equal";
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        vector<char> v1;
        vector<char> v2;

        string s1, s2;

        getline(cin,s1);
        getline(cin,s2);

        insertString(s1, v1);
        insertString(s2, v2);

        cout << "Data Set " + to_string(i+1) + ": " + checkEqual(v1, v2) << endl;
    }

    return 0;
}
