#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<string,int>> a;
vector<char> ans;

bool comp(const pair<string,int> &u, const pair<string,int> &v) {
    return u.first.length() < v.first.length();
}

bool check(string s, string prefix, string suffix) {
    int len = prefix.length();
    for (int i=0; i<len; i++) {
        if (s[i] != prefix[i]) {
            return false;
        }
    }
    for (int i=0; i<len; i++) {
        if (s[n-i-1] != suffix[len-i-1]) {
            return false;
        }
    }
    return true;
}
bool go(string prefix, string suffix) {
    string s = prefix + suffix[suffix.length()-1];
    for (int i=0; i<n-1; i++) {
        if (check(s, a[i*2].first, a[i*2+1].first)) {
            ans[a[i*2].second] = 'P';
            ans[a[i*2+1].second] = 'S';
        } else if (check(s, a[i*2+1].first, a[i*2].first)) {
            ans[a[i*2+1].second] = 'P';
            ans[a[i*2].second] = 'S';
        } else {
            return false;
        }
    }
    cout << s << endl;
    for (int i=0; i<2*n-2; i++) {
        cout << ans[i];
    }
    cout << endl;
    return true;
}
int main() {
    cin >> n;

    a.resize(2*n-2);
    ans.resize(2*n-2);
    for (int i=0; i<2*n-2; i++) {
        string temp;
        cin >> temp;
        a[i] = make_pair(temp, i);
    }
    sort(a.begin(), a.end(), comp);
    if (go(a[2*n-4].first, a[2*n-3].first) == false) { // 가장 긴 접두사, 접미사 자리 check
        go(a[2*n-3].first, a[2*n-4].first); // 아니라면, 순서 바꾸기
    }
    return 0;
}
