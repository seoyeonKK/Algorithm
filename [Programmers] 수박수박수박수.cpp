#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    
    for (int i = 1; i <= n; i++) {
        if (i%2) 
            answer += "수";
        else 
            answer += "박";
    }
    
    return answer;
}
