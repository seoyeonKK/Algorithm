#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Node {
    string cmd;
    string uid;
    string name;
    Node(string a, string b, string c): cmd(a), uid(b), name(c){};
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    queue<Node> q;
    
    for (int i = 0; i < record.size(); i++) {
        int cnt = 0;
        string s, cmd, uid, name;
        
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] == ' ') {
                if (cnt == 0) {
                    cmd = s;
                }
                else if (cnt == 1) {
                    uid = s;
                }
                else if (cnt == 2) {
                    name = s;
                }
                s = "";
                cnt++;
                continue;
            }
            s += record[i][j];
        }
        
        if (cmd == "Leave") {
            uid = s;
            q.push( Node(cmd, uid, m[uid]));
        }
        else {
            name = s;
            m[uid] = name;
            q.push( Node(cmd, uid, name) );    
        }      
    }
    
    while(!q.empty()) {
        if (q.front().cmd == "Enter") {
            answer.push_back(m[q.front().uid] + "님이 들어왔습니다.");
            cout << m[q.front().uid] + "님이 들어왔습니다." << endl;
        }
        else if (q.front().cmd == "Leave") {
            answer.push_back(m[q.front().uid] + "님이 나갔습니다.");
            cout << q.front().uid + "님이 나갔습니다." << endl;
        }
        q.pop();
    }
    
    return answer;
}
