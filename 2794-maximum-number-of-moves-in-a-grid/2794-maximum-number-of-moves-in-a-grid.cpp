class Solution {
public:

    vector<vector<int>>dp;

    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=grid.size() ||  j>= grid[0].size()){
            return 0;
        }

        if(dp[i][j]!=-1){return dp[i][j];}
        int el=grid[i][j]; 
        int ans=0;
        int n=grid.size(); 
        int m=grid[0].size();

       if(i-1>=0 and j+1<m and el<grid[i-1][j+1]){ans= max(ans, 1+ solve(i-1, j+1,grid));}
       if(i>=0 and j+1<m and el<grid[i][j+1]){ans= max(ans, 1+ solve(i, j+1,grid));}
       if(i+1<n and j+1<m and el<grid[i+1][j+1]){ans= max(ans, 1+ solve(i+1, j+1,grid));}


        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n= grid.size(); 
        int m=grid[0].size(); 
        int ans= INT_MIN;
        dp.resize(n+1, vector<int>(m+1, -1));
        for(int i=0; i<n; i++){
            ans= max(ans,solve(i, 0,grid));
        }
        return ans;
    }
};