class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& vis, int b, int i, int j, int n, int m) {
        vis[i][j] = 1;
        b += grid[i][j];
        int x = 0, y = 0, z = 0, k = 0;

        if (i > 0 && vis[i-1][j] == 0) {
            x = solve(grid, vis, b, i-1, j, n, m);
        }
        if (i < n-1 && vis[i+1][j] == 0) {
            y = solve(grid, vis, b, i+1, j, n, m);
        }
        if (j > 0 && vis[i][j-1] == 0) {
            z = solve(grid, vis, b, i, j-1, n, m);
        }
        if (j < m-1 && vis[i][j+1] == 0) {
            k = solve(grid, vis, b, i, j+1, n, m);
        }

        vis[i][j] = 0;
        return max({x, y, z, k, b});
    }

    vector<vector<int>> vis_zero(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    vis[i][j] = 1;
                }
            }
        }
        return vis;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    vector<vector<int>> vis = vis_zero(grid);
                    int res = solve(grid, vis, 0, i, j, n, m);
                    ans = max(ans, res);
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};
