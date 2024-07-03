
class Solution {
public:
    long long int solve(vector<vector<int>> &x, vector<vector<long long int>> &dp, int r, int mask) {
        if (r >= x.size()) {
            return 0;
        }
        if (dp[r][mask] != -1) {
            return dp[r][mask];
        }
        long long int ans = LLONG_MAX;
        for (int i = 0; i < x.size(); i++) {
            if ((mask & (1 << i))==0) {  // Check if the i-th element is not used
                int new_mask = mask | (1 << i);  // Mark the i-th element as used
                ans = min(ans, x[r][i] + solve(x, dp, r + 1, new_mask));
            }
        }
        return dp[r][mask] = ans;
    }

    int minimumXORSum(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<int>> x(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[i][j] = a[i] ^ b[j];
            }
        }
        int c = 1 << n;  // 2^n
        vector<vector<long long int>> dp(n, vector<long long int>(c, -1));
        return solve(x, dp, 0, 0);
    }
};
