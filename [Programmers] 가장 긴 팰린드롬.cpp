#include <iostream>
#include <string>
using namespace std;

int solution(string s) {   
    int len = s.size();
    
    while(len >= 2){
        for(int i = 0; i <= s.size() - len; i++){
                 int left = i;
                 int right = len+i-1;
                 bool flag = true;
            while(left < right){ // 팰린드롬 체크
                if(s[left] != s[right]){
                    flag = false;
                    break;
                }
                left++;
                right--;
            }
            if(flag){
                return len;
            }
        }
        len--;
    }
    return 1;
}
 
