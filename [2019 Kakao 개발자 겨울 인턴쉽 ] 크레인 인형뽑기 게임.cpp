#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    int sero = 0;
    vector<int> baguni;
    int answer = 0;
    //전체 묶어주기 시작 루틴 하나
    for(int i = 0; i< moves.size(); i++){
        sero = moves[i]-1; // 명령 하나씩
        for(int garo = 0; garo < board.size(); garo++){//한칸씩 밑으로
            if(board[garo][sero] != 0){//인형이 있으면
                int doll = board[garo][sero];
                board[garo][sero] = 0;
                if(!baguni.empty() && baguni.back() == doll){//이전이랑 같은 인형이면
                    baguni.pop_back();
                    answer = answer + 2;
                    break;
                }
                else
                    baguni.push_back(doll); //다른 인형이면 바구니 추가
                    break;
            }
        }
    }
    return answer;

}
