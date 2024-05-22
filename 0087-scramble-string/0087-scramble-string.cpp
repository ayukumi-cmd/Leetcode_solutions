

class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool solve(const string &s1, const string &s2, int i1, int i2, int length) {
        if (dp[i1][i2][length] != -1) {
            return dp[i1][i2][length];
        }

        if (s1.substr(i1, length) == s2.substr(i2, length)) {
            return dp[i1][i2][length] = true;
        }

        string substr1 = s1.substr(i1, length);
        string substr2 = s2.substr(i2, length);
        sort(substr1.begin(), substr1.end());
        sort(substr2.begin(), substr2.end());
        if (substr1 != substr2) {
            return dp[i1][i2][length] = false;
        }

        // Recursive case: split the substring and check the two possibilities
        for (int k = 1; k < length; k++) {
            if ((solve(s1, s2, i1, i2, k) && solve(s1, s2, i1 + k, i2 + k, length - k)) ||
                (solve(s1, s2, i1, i2 + length - k, k) && solve(s1, s2, i1 + k, i2, length - k))) {
                return dp[i1][i2][length] = true;
            }
        }

        return dp[i1][i2][length] = false;
    }

    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) {
            return false;
        }
        dp.resize(n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(s1, s2, 0, 0, n);
    }
};
