#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;

        // 띄어쓰기 단위 split
	stringstream ss(s);
	string str;
    
	while(ss>>str) {
		v.push_back(stoi(str));
	}
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    
    return answer;
}
