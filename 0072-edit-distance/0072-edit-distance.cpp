
class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>>& dp){
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j]; 

        int ans = INT_MAX;
        if (a[i - 1] == b[j - 1]) {
            ans = solve(a, b, i - 1, j - 1, dp); 
        } else {
       
            ans = min(ans, 1 + solve(a, b, i - 1, j - 1, dp)); // Replace
            ans = min(ans, 1 + solve(a, b, i - 1, j, dp)); // Delete from `a`
            ans = min(ans, 1 + solve(a, b, i, j - 1, dp)); // Insert into `a`
        }

        return dp[i][j] = ans; 
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
        return solve(word1, word2, n, m, dp);
    }
};
