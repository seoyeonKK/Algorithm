#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int sum = 0;
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day[] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    for (int i = 0; i < a-1; i++) {
        sum += month[i];
    }
    sum += b;
    
    return day[sum % 7];
}
