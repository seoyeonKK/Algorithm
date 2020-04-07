#include <string>
#include <vector>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int tf = 1;
    int check = 0;
    for(int i = 0; i < skill_trees.size(); i++){
        string vec_str = skill_trees[i];
        for(int j = 0; j < vec_str.size(); j++){
            // vec_str[j]와 find_num 비교하기
            int find_num = skill.find(vec_str[j]);
            // 범위에맞지않을 경우 
            if(find_num < 0 || find_num > 30){
                continue;
            }
            // 체크된 개수랑 find()한 개수가 틀릴경우 
            if(find_num != check){
                tf = 0;
                break;
            }
            //동일한 문자가 있을경우 통과하면
            else{
                check++;
            }
        }
        if(tf){
            answer++;
        }
        check = 0;
        tf = 1;
    }
    return answer;
}
