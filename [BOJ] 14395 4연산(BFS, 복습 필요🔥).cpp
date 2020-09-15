#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

const long long limit = 1000000000LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long s, t;
    cin >> s >> t;

    set<long long> check; // 10억 크기의 배열을 만들 수 없어 set을 사용
    queue<pair<long long, string>> q;
    q.push({s, ""});
    check.insert(s);
    
    while(!q.empty()) {
        long long x;
        string s;
        x = q.front().first;
        s = q.front().second;
        q.pop();

        if (x == t) {
            if (s.length() == 0) {
                s = "0";
            }
            cout << s << endl;
            return 0;
        }
        if (0 <= x*x && x*x <= limit && check.count(x*x) == 0) {
            q.push(make_pair(x*x, s+"*"));
            check.insert(x*x);
        }
        if (0 <= x+x && x+x <= limit && check.count(x+x) == 0) {
            q.push(make_pair(x+x, s+"+"));
            check.insert(x+x);
        }
        if (0 <= x-x && x-x <= limit && check.count(x-x) == 0) {
            q.push(make_pair(x-x, s+"-"));
            check.insert(x-x);
        }
        if (x != 0 && 0 <= x/x && x/x <= limit && check.count(x/x) == 0) {
            q.push(make_pair(x/x, s+"/"));
            check.insert(x/x);
        }
    }

    cout << "-1" << endl;
    return 0;
}
