#include <iostream>
#include <queue>
#include <tuple>
#include <set>
#include <string>
using namespace std;

const long long limit = 1000000000LL;

int main() {
    long long s, t;
    cin >> s >> t;
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push({s, ""});
    check.insert(s);

    while(!q.empty()) {
        long long x;
        string str = "";
        tie(x, str) = q.front();
        q.pop();
        
        if (x == t) {
            // x==t이고, 연산자 길이가 0이면, s == t이므로 0 출력
            if (str.length() == 0) {
                str = "0";
            }
            // x==t이고, 연산자 길이가 다르면 정답 출력
            cout << str << endl;
            
            return 0;
        }
        if (0 <= x*x && x*x <= limit && check.count(x*x) == 0) {
            q.push({x*x, str+"*"});
            check.insert(x*x);
        }
        if (0 <= x+x && x+x <= limit && check.count(x+x) == 0) {
            q.push({x+x, str+"+"});
            check.insert(x+x);
        }
        if (0 <= x-x && x-x <= limit && check.count(x-x) == 0) {
            q.push({x-x, str+"-"});
            check.insert(x-x);
        }
        if (x != 0 && 0 <= x/x && x/x <= limit && check.count(x/x) == 0) {
            q.push({x/x, str+"/"});
            check.insert(x/x);
        }
    }

    cout << -1 << endl;

    return 0;
}
