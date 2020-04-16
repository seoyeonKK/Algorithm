#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    const int n = prices.size();
    vector<int> answer(n);
    stack<int> st;
    
    for (int i=0; i<n; i++) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            auto top = st.top();
            st.pop();
            answer[top] = i - top;
        }
        
        st.push(i);
    }
    
    while (!st.empty()) {
        auto top = st.top();
        st.pop();
        answer[top] = n - 1 - top;
    }
    
    return answer;
}
