#include <string>
#include <iostream>
#include <vector>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool flag = 1;
    int nextIdx = 0;
    
    for(int i = 0; i < skill_trees.size(); i++){
        string tree = skill_trees[i];
        
        for(int j = 0; j < tree.length(); j++){
            int idx = skill.find(tree[j]);
             
            // skill에 없는 문자일 경우 넘어가기
            if(idx < 0) continue;
            
            // idx가 nextIdx와 다를 경우 
            if(idx != nextIdx){
                flag = 0;
                break;
            }
            // idx가 nextIdx와 같다면 nextIdx+1
            else{
                nextIdx++;
            }
        }
        
        // 스킬이 순서대로 잘 있다면
        if(flag){
            answer++;
        }
        
        nextIdx = 0;
        flag = 1;
    }
    return answer;
}
