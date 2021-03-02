class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(); // 팰린드롬 크기 초기화
        string ans = "";
        
        // 팰린드롬 가장 큰 길이부터 순회
        while(len >= 2) {
            for (int i = 0; i <= s.size() - len; i++) {
                int left = i; // 팰린드롬 체크 left 포인터 
                int right = len + i - 1; // 팰린드롬 체크 right 포인터
                bool flag = true;
                
                // left, right 포인터 안쪽으로 옮겨가며 비교
                while(left < right) {
                    if (s[left] != s[right]) {
                        flag = false;
                        break;
                    }
                    left++;
                    right--;
                }
                
                if (flag) {
                    ans = s.substr(i,len); // substr(idx, count)
                    return ans;
                }
            }   
            len--;
        }
        // 답이 없다면 가장 첫번째 idx 리턴
        ans = s[0];
        return ans;
    }
};
