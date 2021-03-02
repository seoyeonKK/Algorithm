#include <algorithm>

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};
