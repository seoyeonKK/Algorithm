#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    string myStr = "";
    queue<string> q;
    
    for (int i = 0; i < s.length(); i++) {
        myStr += s[i];
        if ((s[i] == ' ') || (i == s.length() - 1)) {
            q.push(myStr);
            myStr = "";
        }
    }
    
    while(!q.empty()) {
        string word;
        word = q.front();
        q.pop();
        
        for (int i = 0; i < word.length(); i++) {
            if (isalpha(word[0])) {
               word[0] = toupper(word[0]);    
            }
            
            if (i > 0 && isalpha(word[i])) {    
                word[i] = tolower(word[i]);
            }
        }
        
        answer += word;
    }
    
    return answer;
}
