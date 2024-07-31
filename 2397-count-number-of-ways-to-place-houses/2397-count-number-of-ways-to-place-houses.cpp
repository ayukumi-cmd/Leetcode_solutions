class Solution {
public:
    int n;
    const int mod = 1e9 + 7;
    vector<long long> dp;

    int solve(int i) {
        if (i > n) return 1;
        if (dp[i] != -1) return dp[i];
        dp[i] = (solve(i + 1)%mod + solve(i + 2)%mod) % mod;
        return dp[i];
    }

    int countHousePlacements(int m) {
        n = m;
        dp.resize(n + 1, -1);
        long long result = solve(1);
        result = (result * result) % mod;
        return result;
    }
};
