#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
 
    if(s.length() == 1)
        return 1;
 
    for(int i = 1; i <= s.length() / 2; i++){ //비교 갯수 지정
        int count = 1;
        string f = s.substr(0, i);
        string cmp, cp;
 
        for(int j = i; j < s.length(); j += i){ //처음부터 쭉 비교하기
            cmp = s.substr(j, i);
 
            if(!(f.compare(cmp)))  //비교 문자가 같으면 count 증가
                count++;
            else{
                if(count == 1){
                    cp += f;
                    f = cmp;
                }else{
                    cp = cp + to_string(count) + f;
                    f = cmp;
                    count = 1;
                }
            }
            
            if(j + i >= s.length()){  //마지막에 substr기준을 초과한 경우
                if(count != 1){
                    cp = cp + to_string(count) + f;
                    break;
                }else{
                    cp = cp + s.substr(j);
                    break;
                }
            }
        }
        answer = (answer > cp.length()) ? cp.length() : answer;
    }
    
    return answer;
}
