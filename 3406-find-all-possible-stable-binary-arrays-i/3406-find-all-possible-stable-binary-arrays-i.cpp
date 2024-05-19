class Solution {
public:
    const int MOD = 1000000007;

    int solve(int zero, int one, int state, int limit, vector<vector<vector<int>>>& dp) {
        if (zero == 0 && one == 0) {
            return 1;
        }
        if (dp[zero][one][state] != -1) {
            return dp[zero][one][state];
        }

        int ans = 0;
        int consecutive = state / (limit + 1);
        int cnt = state % (limit + 1);

        if (zero > 0) {
            if (cnt < limit && consecutive == 0) {
                ans = (ans + solve(zero - 1, one, 0 * (limit + 1) + (cnt + 1), limit, dp)) % MOD;
            } else if (consecutive == 1 || consecutive == 2) {
                ans = (ans + solve(zero - 1, one, 0 * (limit + 1) + 1, limit, dp)) % MOD;
            }
        }

        if (one > 0) {
            if (cnt < limit && consecutive == 1) {
                ans = (ans + solve(zero, one - 1, 1 * (limit + 1) + (cnt + 1), limit, dp)) % MOD;
            } else if (consecutive == 0 || consecutive == 2) {
                ans = (ans + solve(zero, one - 1, 1 * (limit + 1) + 1, limit, dp)) % MOD;
            }
        }

        dp[zero][one][state] = ans;
        return ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        int state_size = 3 * (limit + 1); // 3 for consecutive (0, 1, 2) and limit + 1 for cnt
        vector<vector<vector<int>>> dp(zero + 1, vector<vector<int>>(one + 1, vector<int>(state_size, -1)));
        return solve(zero, one, 2 * (limit + 1) + 0, limit, dp); // Initial state with consecutive=2 and cnt=0
    }
};
// chatgpt ka solution hai mujhe bhi nhi smajah aaya 
// jisme tle hai vo dekho vo mera hia 