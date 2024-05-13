class Solution {
public:
    
    long long rec(vector<int>& nums, vector<vector<vector<long long>>>& dp, int pos, int ended, int x) {
        if (dp[pos][ended][x] != LLONG_MAX) return dp[pos][ended][x];

        if (pos == nums.size() && x == 0) return 0;
        if (pos == nums.size()) return LLONG_MIN;

        if (ended) {
            long long a = rec(nums, dp, pos + 1, ended, x);
            if (x == 0) return dp[pos][ended][x] = a;
            long long b = rec(nums, dp, pos + 1, 1 - ended, x - 1);
            if (b == LLONG_MIN) return dp[pos][ended][x] = a;
            b += 1ll * (((x - 1) % 2) ? -1ll * nums[pos] : 1ll * nums[pos]) * x;
            return dp[pos][ended][x] = max(a, b);
        } else {
            long long a = rec(nums, dp, pos, 1 - ended, x);
            long long b = rec(nums, dp, pos + 1, ended, x);
            if (b == LLONG_MIN) return dp[pos][ended][x] = a;
            b += 1ll * (x % 2 ? -1ll * nums[pos] : 1ll * nums[pos]) * (x + 1);
            return dp[pos][ended][x] = max(a, b);
        }
    }
    
    long long maximumStrength(vector<int>& nums, int k) {
        vector<vector<vector<long long>>> dp(nums.size() + 1, 
        vector<vector<long long>>(3, vector<long long>(k + 1, LLONG_MAX)));
        long long res = rec(nums, dp, 0, 1, k);
        return res;
    }
};