#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int cnt;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 1; i < phone_book.size(); i++) {
        cnt = 0;
        
        for (int j = 0; j < phone_book[i-1].length(); j++) {
            if (phone_book[i-1][j] != phone_book[i][j]) break;
            else cnt++;
        }
        
        if (cnt == phone_book[i-1].length()) return false;  
    }
    
    return answer;
}
