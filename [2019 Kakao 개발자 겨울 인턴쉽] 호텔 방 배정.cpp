#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    vector<long long> realRoom(k,0);

    for(int i=0; i<room_number.size(); i++){
        int want = room_number[i];

        if(realRoom[want] == 0) { //방이 비었으면
            realRoom[want] = 1;
            answer.push_back(want); // 넣어주기
        }
        else{ //방이 찼으면
            int j = want+1;
            while(realRoom[j]!= 0){
                j++;
            }
            realRoom[j] = 1;
            answer.push_back(j); // 넣어주기
        }
    }
    return answer;

}
