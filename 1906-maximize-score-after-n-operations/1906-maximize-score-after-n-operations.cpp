class Solution {
public:
    int solve(int mask, int &n, int op, vector<int>& nums,  vector<vector<int>>&memo) {
        if (mask == (1 << n) - 1) {
            return 0;
        }
        if (memo[mask][op] != -1) {
            return memo[mask][op];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c1_mask = (1 << i);
                int c2_mask = (1 << j);
                if ((mask & c1_mask) == 0 && (mask & c2_mask) == 0) {
                    int new_mask = mask | c1_mask | c2_mask;
                    int current_score = op * (__gcd(nums[i], nums[j])) + solve(new_mask, n, op + 1, nums, memo);
                    ans = max(ans, current_score);
                }
            }
        }
        memo[mask][op]= ans;
        return ans;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(1 << n, vector<int>(n+1, -1));
        return solve(0, n, 1, nums, memo);
    }
};
