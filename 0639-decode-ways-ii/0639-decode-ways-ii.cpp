


class Solution {
public:
    vector<int> dp;
    
    int solve(int i, string &s) {
        int n = s.size();
        if (i >= n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }

        long long  ans = 0;

        if (s[i] == '*') {
            for (int j = 0; j < 9; j++) {
                ans += solve(i + 1, s);
                ans=ans % 1000000007;
            }
        } else {
            ans += solve(i + 1, s);
            ans=ans % 1000000007;
        }

        if (i + 1 < n) {
            if (s[i] == '*' && s[i + 1] == '*') {
                for (int j = 1; j <= 2; j++) {
                    for (int k = 1; k <= 9; k++) {
                        if (10 * j + k <= 26) {
                            ans += solve(i + 2, s);
                        }
                    }
                }
                ans=ans % 1000000007;
            }
            else if (s[i] == '*') {
                for (int j = 1; j <= 2; j++) {
                    if (10 * j + ( s[i + 1] - '0') <= 26) {
                        ans += solve(i + 2, s);
                    }
                }
                ans=ans % 1000000007;
            } else if (s[i + 1] == '*') {
                for (int j = 1; j <= 9; j++) {
                    if (10 * (s[i] - '0') + j <= 26) {
                        ans += solve(i + 2, s);
                    }
                }
                ans=ans % 1000000007;
            } else {
                int num = 10 * (s[i] - '0') + (s[i + 1] - '0');
                if (num <= 26) {
                    ans += solve(i + 2, s);
                }
                ans= ans % 1000000007;
            }
        }

        return dp[i] = ans % 1000000007;
    }

    int numDecodings(string s) {
        dp.resize(s.size() + 1, -1);
        return solve(0, s);
    }
};