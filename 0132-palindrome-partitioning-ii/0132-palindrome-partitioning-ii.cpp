class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> isPalindrome;

    bool ispalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    int palcut(string &s, int i, int j) {
        if (i >= j || isPalindrome[i][j]) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int res = INT_MAX;
        for (int k = i; k < j; ++k) {
            if (isPalindrome[i][k]) {
                res = min(res, 1 + palcut(s, i, k)+palcut(s, k + 1, j));
            }
        }
        return dp[i][j] = res;
    }

    int minCut(string s) {
        int n = s.length();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        isPalindrome = vector<vector<bool>>(n, vector<bool>(n, false));

        // Precompute whether substrings are palindromes
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (ispalindrome(s, i, j)) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        return palcut(s, 0, n - 1);
    }
};
