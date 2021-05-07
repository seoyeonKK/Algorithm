#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<pair<int, int>> number(10);
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int lx = 3;
    int ly = 0;
    int rx = 3;
    int ry = 2;
    
    for (int i = 1; i < 10; i++) {
        number[i].first = (i-1)/3;
        number[i].second = (i-1)%3;
    }
    number[0].first = 3;
    number[0].second = 1;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer.push_back('L');
            lx = number[numbers[i]].first;
            ly = number[numbers[i]].second;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer.push_back('R');
            rx = number[numbers[i]].first;
            ry = number[numbers[i]].second;
        }
        else {
            int llen = abs(number[numbers[i]].first - lx) + abs(number[numbers[i]].second - ly);
            int rlen = abs(number[numbers[i]].first - rx) + abs(number[numbers[i]].second - ry);
            if (llen < rlen) {
                answer.push_back('L');
                lx = number[numbers[i]].first;
                ly = number[numbers[i]].second;
            }
            else if (rlen < llen){
                answer.push_back('R');
                rx = number[numbers[i]].first;
                ry = number[numbers[i]].second;
            }
            else {
                if (hand == "left") {    
                    answer.push_back('L');
                    lx = number[numbers[i]].first;
                    ly = number[numbers[i]].second;
                }
                else {
                    answer.push_back('R');
                    rx = number[numbers[i]].first;
                    ry = number[numbers[i]].second;
                }
            }
        }
        
    }
        
    return answer;
}
