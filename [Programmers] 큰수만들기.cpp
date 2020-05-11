#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int length = number.length() - k;
	int max = 0;
	int count = 0;
	int j;
	vector<int> temp;
    
	for (int i = length; i > 0; i--) {
		max = 0;
		count = 0;
        
		for (j = 0; j < number.length()-i+1; j++) {
			if (max < number[j]) {
				max = number[j];
				count = j;
			}
		}
		number.replace(0, count+1, " ");
		temp.push_back(max);
	}
    
	for (int i = 0; i < temp.size(); i++)
		answer += temp[i];
    
	return answer;
}
