#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land) {
    int answer = 0;
    int N = board.size();
    
    for (int i=0; i<N-1; i++) {
        board[i+1][0] += get_max( {board[i][1], board[i][2], board[i][3]} );
        board[i+1][1] += get_max( {board[i][0], board[i][2], board[i][3]} );
        board[i+1][2] += get_max( {board[i][0], board[i][1], board[i][3]} );
        board[i+1][3] += get_max( {board[i][0], board[i][1], board[i][2]} );
    }
    
    answer = get_max ( board[N-1] );
    
    return answer;
}
