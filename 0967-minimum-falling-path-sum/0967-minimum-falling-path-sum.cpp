#include <vector>
#include <climits>
#include <unordered_map>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1e9));

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, minPathSum(matrix, n - 1, j, memo));
        }

        return ans;
    }

    int minPathSum(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo) {
        int m=matrix[0].size();
        if (i == 0) {
            return matrix[i][j];
        }

        if (memo[i][j] != -1e9) {
            return memo[i][j];
        }

      int minValue = INT_MAX;
      if(i-1>=0){  minValue = min(minValue, minPathSum(matrix, i - 1, j, memo));}
      if(i-1>=0 and j-1>=0){   minValue = min(minValue, minPathSum(matrix, i - 1, j - 1, memo));}
      if(i-1>=0 and j+1<m){  minValue = min(minValue, minPathSum(matrix, i - 1, j + 1, memo));}

        return memo[i][j] = minValue + matrix[i][j];
    }
};