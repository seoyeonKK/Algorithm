#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool p[10000000];
bool c[10000000];

int solution(string s) {
    memset(p,1,sizeof(p));
    p[0] = false;
    p[1] = false;
    
    // 소수 true, false 표시
    for(int i=2; i*i<10000000; i++){
        if(p[i] == false) continue;
        p[i] = true;
        for(int j=i*2; j<10000000; j+=i)
            p[j] = false;
    }
    
    int ans=0;
    int size = (int)s.size();
    sort(s.begin(),s.end());
    do{
        for(int i=1; i<=size; i++){
            int n;
            n = stoi(s.substr(0,i));
            if(!c[n] && p[n]){
                
                c[n] = true; // n값 사용
                ans++;
            }
        }
    } while(next_permutation(s.begin(),s.end()));
    return ans;
}
