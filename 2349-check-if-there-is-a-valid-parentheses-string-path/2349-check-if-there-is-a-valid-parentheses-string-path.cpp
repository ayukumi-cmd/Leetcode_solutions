class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(2 * max(n, m)+1, -1)));
        return solve(0, 0, 0, grid, dp);
    }

private:
    bool solve(int i, int j, int stackSize, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m || stackSize < 0) {
            return false;
        }

        if (i == n - 1 && j == m - 1) {
            return stackSize == 1 && grid[i][j] == ')';
        }

        if (dp[i][j][stackSize] != -1) {
            return dp[i][j][stackSize];
        }

        bool result = false;
        if (grid[i][j] == ')') {
            result = solve(i + 1, j, stackSize - 1, grid, dp) || solve(i, j + 1, stackSize - 1, grid, dp);
        } else {
            result = solve(i + 1, j, stackSize + 1, grid, dp) || solve(i, j + 1, stackSize + 1, grid, dp);
        }

        dp[i][j][stackSize] = result;
        return result;
    }
};
