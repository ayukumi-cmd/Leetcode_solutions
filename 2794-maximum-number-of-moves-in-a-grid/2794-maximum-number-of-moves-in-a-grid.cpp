class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (j >= m) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int el = grid[i][j];
        int ans = 0;

        // Check moves to the right diagonal, right, and right-down diagonal
        if (i - 1 >= 0 && j + 1 < m && el < grid[i - 1][j + 1]) {
            ans = max(ans, 1 + solve(i - 1, j + 1, grid));
        }
        if (j + 1 < m && el < grid[i][j + 1]) {
            ans = max(ans, 1 + solve(i, j + 1, grid));
        }
        if (i + 1 < n && j + 1 < m && el < grid[i + 1][j + 1]) {
            ans = max(ans, 1 + solve(i + 1, j + 1, grid));
        }

        return dp[i][j] = ans;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0; // Initialize answer to 0
        dp.resize(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) { // Loop over rows instead of columns
            ans = max(ans, solve(i, 0, grid));
        }

        return ans;
    }
};
