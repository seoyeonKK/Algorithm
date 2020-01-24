#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;
void dfs(string begin, string target, vector<string> words, string history, int n) {
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        string tmp = word;
        
        //탐색 가능한 단어 구하기
        int same = 0;
        
        for (int j = 0; j < begin.size(); j++) {
            for (int k = 0; k < word.size(); k++) {
                if (begin[j] == tmp[k]) {
                    tmp[k] = '.'; //중복체크 방지
                    same++; 
                    break;
                }
            }
        }
                    
        //1개 알파벳만 다른경우
        if (same == begin.size()-1) {
            //탐색 가능한 단어가 일전에 탐색한 단어인지 체크(새로운 단어인 경우만 탐색)
            if (history.find(word) == string::npos) {
                if (target == word) {//타켓을 구하면, 탐색 횟수를 저장한다.
                    ans.push_back(n+1);
                    return;
                }
                //begin은 다음 탐색 단어!, 탐색시 탐색 횟수 증가(n+1)
                dfs(word, target, words, history + " " + word, n + 1);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, target, words, begin, 0);
    if (!ans.empty()) {
        sort(ans.begin(), ans.end());
        answer = ans.at(0);
    }
    return answer;
}
