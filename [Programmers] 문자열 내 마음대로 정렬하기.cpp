#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<string> answer2;
    
    for(int i = 0; i < strings.size(); i++) {
       for(int j = 0; j < strings.size(); j++) {
           if(strings[i][n] < strings[j][n]){
               string temp = strings[i];
               strings[i] = strings[j];
               strings[j] = temp;
           }
           if(strings[i][n] == strings[j][n]) {
               if(strings[i] < strings[j]) {
                   string temp = strings[i];
                   strings[i] = strings[j];
                   strings[j] = temp;
               }
           }
       }
    }
    
    return strings;
}
