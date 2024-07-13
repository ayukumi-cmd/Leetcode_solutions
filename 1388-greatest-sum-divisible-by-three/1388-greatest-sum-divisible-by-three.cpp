class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(3, -1));
        return helper(nums, 0, 0, memo);
    }

    int helper(vector<int>& nums, int i, int remainder, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            return remainder == 0 ? 0 : -1000000000;
        }

        if (memo[i][remainder] != -1) {
            return memo[i][remainder];
        }

        // Include nums[i]
        int exclude = helper(nums, i + 1, remainder, memo);
        int include = helper(nums, i + 1, (remainder + nums[i]) % 3, memo) + nums[i];
        // Exclude nums[i]
      

        memo[i][remainder] = max(include, exclude);
        return memo[i][remainder];
    }
};