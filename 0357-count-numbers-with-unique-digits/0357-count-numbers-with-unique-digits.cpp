class Solution {
public:
    int dp[11][2][1 << 10];
    int solve(int pos, bool bound,  int mask, string s) {
        if (pos == s.length()) return 1;
        if (dp[pos][bound][mask] != -1) return dp[pos][bound][mask];

        int ans = 0;
        int maxDigit = bound ? s[pos] - '0' : 9;
        for (int digit = 0; digit <= maxDigit; digit++) {
            if (mask == 0 && digit == 0) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), mask, s);
            else if (!(mask & (1 << digit))) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), mask | (1 << digit), s);
        }

        return dp[pos][bound][mask] = ans;

    }
    int countNumbersWithUniqueDigits(int n) {
        memset(dp, -1, sizeof(dp));
        if(n==0){return 1;}
     
        int num = 1;
        for (int i = 0; i < n; i++) num *= 10;

        num--;
        string s = to_string(num);
        return solve(0, true, 0, s);
    }
};