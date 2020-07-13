#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<int> t;
	int temp, s;
	for (int i = 1; i <= n; i++) {
		t.clear();
		temp = 0;
		s = answer.size();
		while (temp <= s) {
			if (temp % 2 == 0)
				t.push_back(0);
			else
				t.push_back(1);
			if ((answer.size() > 0) && (temp < s))
				t.push_back(answer[temp]);
			temp++;
		}
		answer = t;
	}
	return answer;
}
