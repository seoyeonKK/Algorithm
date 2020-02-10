#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    long long num;
    vector<int> temp;
    
    for (int i = 0; i < operations.size(); i++) {
        num = stoi(operations[i].substr(2)); // idx 2부터 string to int
        
        if(operations[i][0] == 'I'){
            temp.push_back(num);
            sort(temp.begin(), temp.end()); // 삽입 후 오름차순 sort
        }
        
        else if (operations[i][0] == 'D') {
            if (num > -1 && !temp.empty()) {
                temp.pop_back(); // 최댓값 삭제
            }
            else if (num <= -1 && !temp.empty()){
                temp.erase(temp.begin()); // 최솟값 삭제
            }
        }
    }
    
    // 비어있을 경우
    if (temp.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(temp[temp.size()-1]); // 최댓값
        answer.push_back(temp[0]); // 최솟값
    }
    
    return answer;
}
