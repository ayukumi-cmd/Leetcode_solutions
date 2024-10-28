class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& dp, int &x) {
        if (i >= n || j >= m) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        int right = solve(matrix, i, j + 1, n, m, dp,x);
        int bottom = solve(matrix, i + 1, j, n, m, dp,x);
        int diagonal = solve(matrix, i + 1, j + 1, n, m, dp,x);
        
        if (matrix[i][j] == 1) {
            int ans = 1 + min({bottom, right, diagonal});
            dp[i][j] = ans;
            x+=ans;
            return ans;
        } else {
            return dp[i][j] = 0;
        }
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int totalSquares = 0;

                int x=0;
                totalSquares += solve(matrix, 0, 0, n, m, dp, x);
           
        

        return x;
    }
};
