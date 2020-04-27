#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> wordsList;
    int people[10] = {0,};
    int i = 1;
    wordsList.push_back(words[0]);
    char prev = words[0][words[0].length()-1];
    
    while(1) {
        if (wordsList.size() == words.size()) {
            answer.push_back(0);
            answer.push_back(0);
            return answer;
        }
        for (int j = 0; j < wordsList.size(); j++) {
            if (words[i] == wordsList[j]) {
                answer.push_back(i % (n+1)+1);
                answer.push_back(people[i % (n+1)]);
                return answer;
            }
        }
        
        if (words[i].length() > 1 && words[i][0] != prev) {
            people[i % (n+1)]++;
            wordsList.push_back(words[i]);
            i++;
        }
        else {
            answer.push_back(i % (n+1) +1);
            answer.push_back(people[i % (n+1)]);
            return answer;
        }
        
    }

    return answer;
}
