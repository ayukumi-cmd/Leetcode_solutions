// class Solution {
// public:
//    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo, int ans) {
//         if (i == grid.size()-1 && j == grid[0].size()-1) {
//             return 0;
//         }
//         int n= grid.size();
//         int m= grid[0].size();
//         if (memo[i][j] != INT_MIN) {
//             return memo[i][j];
//         }

        
//         for(int p=i+1; p<n; p++){
//             ans = max(ans, solve(grid, p, j, memo, ans + grid[p][j] - grid[i][j]));
//         }

//         for(int p=j+1; p<m; p++){
//             ans = max(ans, solve(grid, i, p, memo, ans + grid[i][p] - grid[i][j]));
//         }

//         memo[i][j] = ans;
//         return memo[i][j];
//     }

//     int maxScore(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int ans = INT_MIN;

//         vector<vector<int>> memo(n, vector<int>(m, INT_MIN));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 ans = max(ans, solve(grid, i, j, memo, INT_MIN));
//             }
//         }
//         return ans;
        
//     }
// };



#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, vector<vector<int>>& memo) {
        if (i >= n || j >= m) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int downScore = INT_MIN;
        int rightScore = INT_MIN;
        
        if (i + 1 < n) {
            downScore = grid[i + 1][j]-grid[i][j] + solve(grid, i + 1, j, n, m, memo);
        }

        if (j + 1 < m) {
            rightScore = grid[i][j + 1]-grid[i][j] + solve(grid, i, j + 1, n, m, memo);
        }

        memo[i][j] = max({0,downScore, rightScore});
        return memo[i][j];
    }

    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;

        vector<vector<int>> memo(n, vector<int>(m, -1));
        int max1= INT_MIN;
        int max2= INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans,  solve(grid, i, j, n, m, memo));
              if(i+1<n) max1= max(max1,grid[i+1][j]-grid[i][j]);
              if(j+1<m) max2= max(max2,grid[i][j+1]-grid[i][j]);
            }
        }
        if(ans==0) return max(max1, max2);
        return ans;
    }
};
