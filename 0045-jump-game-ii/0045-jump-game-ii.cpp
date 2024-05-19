class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int i, int steps) {
        int n = nums.size();
        if (i ==n - 1) return 0;
        if(i>=n){return INT_MAX;}

        if (dp[i] != -1) return dp[i];

        int step = INT_MAX;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n and solve(nums, i + j, steps + 1)!=INT_MAX) {
                step = min(step, 1 + solve(nums, i + j, steps + 1));
            }
        }
        return dp[i] = step;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, -1);
        return solve(nums, 0, 0);
    }
};
