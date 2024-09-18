class Solution {
public:
    string r; 
    int dp[1024][2][2][11]; 

    int solve(int mask, int tight, int leading, int n) {
        if (n == 0) {
            return 1;
        }

        if (dp[mask][tight][leading][n] != -1) {
            return dp[mask][tight][leading][n];
        }

        int x = (r[r.length() - n] - '0');
        int ub = tight ? x : 9;
        int ans = 0;

        if (leading) {
            ans += solve(mask, 0, 1, n - 1); 
            for (int i = 1; i <= ub; i++) {
                if (!(mask & (1 << i))) {
                    ans += solve(mask | (1 << i), tight & (i == ub), 0, n - 1);
                }
            }
        } else {
            for (int i = 0; i <= ub; i++) {
                if (!(mask & (1 << i))) {
                    ans += solve(mask | (1 << i), tight & (i == ub), 0, n - 1);
                }
            }
        }

        return dp[mask][tight][leading][n] = ans;
    }

    int countSpecialNumbers(int n) {
        r = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 1, r.length()) - 1;
    }
};
