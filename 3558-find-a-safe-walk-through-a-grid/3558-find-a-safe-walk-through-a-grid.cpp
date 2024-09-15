class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    int dp[51][51][102];
    bool cal(int i, int j, int h,vector<vector<int>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n-1 && j == m-1){
            if(h >= 1) return true;
            return false;
        }
        if(dp[i][j][h] != -1) return dp[i][j][h];
        bool ans = false;
        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >=0 && y >=0 && x < n && y < m && vis[x][y] == 0){
                if(grid[x][y] == 1){
                    if(h >= 1){
                        vis[x][y] = 1;
                    ans |= cal(x,y,h-1,grid,vis);
                    vis[x][y] = 0;
                    }
                }else{
                    vis[x][y] = 1;
                    ans |= cal(x,y,h,grid,vis);
                    vis[x][y] = 0;
                }  
            }
        }
        return dp[i][j][h] = ans;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> vis(n, vector<int>(m,0));
        vis[0][0] = 1;
        if(grid[0][0] == 1){
            health -= 1;
        }
        return cal(0,0, health, grid, vis);
    }
};