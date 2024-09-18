class Solution {
public:
    string convert(int n) {
        string s; 
        for (int i = 31; i >=0; i--) {
            int bit = (n >> i) & 1;
            s += to_string(bit);
        }
        
        return s;
    }

    int solve(string &r, bool tight, int pos, int prevBit, vector<vector<vector<int>>>&dp) {
        
        if (pos == 32) {
            return 1;
        }
        if(dp[tight][pos][prevBit]!=-1){return dp[tight][pos][prevBit]; }

        int ub = tight ? (r[pos] - '0') : 1;
        int ans = 0;

        for (int i = 0; i <= ub; i++) {
            if (prevBit == 1 && i == 1) {
                continue; 
            }
            ans += solve(r, tight && (i == ub), pos + 1, i, dp);
        }

        return dp[tight][pos][prevBit]=ans;
    }

    int findIntegers(int n) {
        string r = convert(n); 
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(33, vector<int>(2, -1)));
        return solve(r, 1, 0, 0,dp); 
    }
};
