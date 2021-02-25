#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
bool check[8];
set<string> s;
 
void solve(int index, string res, vector<string> &user_id, vector<string> &banned_id) {
    if (index == banned_id.size()) {
        // 모두 매핑이 되었다면
        sort(res.begin(), res.end()); // 소팅한 문자열로 만든 후
        s.insert(res); // 중복제거
        return;
    }
 
    string b_id = banned_id[index];
 
    // 각 응모자 아이디와 index번째 불량 사용자 아이디를 비교
    for (int i = 0; i < user_id.size(); i++) {
        string u_id = user_id[i];
 
        // 각 아이디 길이가 다르다면
        if (u_id.size() != b_id.size()) continue;
        
        // i번째 응모아이디가 이미 불량 사용자의 아이디와 매핑된 경우
        if (check[i]) continue;
 
        bool flag = true;
        // *을 제외한 문자들이 같은지 검사
        for (int j = 0; j < b_id.size(); j++) {
            if (b_id[j] == '*') continue;
 
            // 문자가 하나라도 다르면 매핑X
            if (u_id[j] != b_id[j]) {
                flag = false;
                break;
            }
        }
 
        // 불량 사용자의 아이디와 별을 제외한 부분이 같은 경우
        if (flag) {
            // i번째 사용자 아이디는 index번째 불량아이디에 매핑된 것으로 체크하고 다음 불량아이디를 경우를 탐색
            check[i] = true;
            solve(index + 1, res + to_string(i), user_id, banned_id);
 
            // index번째 불량 아이디에 매핑 될 수 있는 다른 사용자 아이디를 위해 현재 i번은 다시 false로 체크
            // 경우의 수를 체크하는 것이기 때문
            check[i] = false;
        }
    }
}
 
 
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
 
    solve(0, "", user_id, banned_id);
    answer = s.size();
 
    return answer;
}
