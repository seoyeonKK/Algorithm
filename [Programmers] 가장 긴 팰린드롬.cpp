#include <iostream>
#include <string>
using namespace std;

int solution(string s) {   
    int len = s.size();
    
    while(len >= 2) {
        for(int i = 0; i <= s.size() - len; i++) { // 팰린드롬 체크 한 쿼터
            int left = i;
            int right = len+i-1;
            bool flag = true;
            
            while(left < right) { // left가 Right보다 작을 때까지 이동하며 팰린드롬 체크하기
                if(s[left] != s[right]) { 
                    flag = false;
                    break;
                }
                left++; // Left 한 칸씩 이동
                right--; // Right 한 칸씩 이동
            }
            if(flag) return len; // 팰린드롬일 때 len을 리턴
        }
        len--; // 한 쿼터 돌 때마다 len 줄이기
    }
    return 1;
}
 
