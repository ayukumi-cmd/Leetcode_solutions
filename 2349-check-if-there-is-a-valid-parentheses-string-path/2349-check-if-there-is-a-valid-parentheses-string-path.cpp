// class Solution {
// public:
   
//    bool solve(int i , int j, stack<char>&st , bool f, vector<vector<char>>& grid){
//     int n=grid.size(); 
//     int m=grid[0].size();
//     if(i>=n || j>=m){return false;}
//     if(i==n-1 and j==m-1){
//         if(st.size()==1 and grid[i][j]==')'){return true;}
//         else return false;
//     }
//      bool x=false;
//     if(grid[i][j]==')'){
//         if(st.empty()){return false;}
//         else {
//             st.pop();
//             x= (solve(i+1, j , st, !f, grid)||solve(i, j+1, st, !f, grid));
        
//         }
//     }

//     else{
//         st.push('(');
//        x= (solve(i+1, j , st, !f, grid)||solve(i, j+1, st, !f, grid));
      
//     }

//     return x;
//    }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         int n= grid.size();
//         int m= grid[0].size();
//         stack<char>st;
//         return solve(0, 0, st,0, grid);
//     }
// };


class Solution {
public:
    bool solve(int i, int j, int openCount, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        // If out of bounds
        if (i >= n || j >= m) return false;
        
        // Update open parentheses count
        if (grid[i][j] == '(') {
            openCount++;
        } else {
            openCount--;
        }
        
        // If more closing parentheses than opening ones at any point
        if (openCount < 0) return false;
        
        // If reached bottom-right corner
        if (i == n - 1 && j == m - 1) {
            return openCount == 0;
        }
        
        // Check memoization table
        if (dp[i][j][openCount] != -1) {
            return dp[i][j][openCount];
        }
        
        // Move to the next cell in the grid
        bool result = solve(i + 1, j, openCount, grid, dp) || solve(i, j + 1, openCount, grid, dp);
        
        // Store the result in memoization table
        dp[i][j][openCount] = result;
        
        return result;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxOpenCount = n + m; // Maximum possible open parentheses count
        
        // Initialize memoization table with -1 (indicating uncomputed states)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxOpenCount, -1)));
        
        return solve(0, 0, 0, grid, dp);
    }
};
