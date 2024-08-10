class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> g(n * 3, vector<int>(m * 3, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int r2=3*i; int c2= 3*j;
                if (grid[i][j] == '/') {
                    g[r2][c2 + 2] = 1;
                    g[r2 + 1][c2 + 1] = 1;
                    g[r2 + 2][c2] = 1;
                } else if (grid[i][j] == '\\') {
                    g[r2][c2] = 1;
                    g[r2 + 1][c2 + 1] = 1;
                    g[r2 + 2][c2 + 2] = 1;
                }
            }
        }

        for (int i = 0; i < g.size(); ++i) {
            for (int j = 0; j < g[0].size(); ++j) {
                if (g[i][j] == 0) {
                    dfs(g, i, j);
                    ++cnt;
                }
            }
        }

        return cnt;
    }

private:
    void dfs(vector<vector<int>>& g, int i, int j) {
        int n = g.size();
        int m = g[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 1) return;
        g[i][j] = 1;
        int d[] = {0, -1, 0, 1, 0}; 
        for (int k = 0; k < 4; ++k) {
            dfs(g, i + d[k], j + d[k + 1]);
        }
    }
};
