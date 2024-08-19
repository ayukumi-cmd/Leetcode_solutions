class Solution {
public:
    int m;
    vector<vector<int>>dp;
    int solve(int x, int y) {
        if (x > m) {
            return INT_MAX;
        }
        if (x == m) {
            return 0;
        }
        if(dp[x][y]!=-1){return dp[x][y];}
        int res = INT_MAX;
        if (y>0) {
          
            int a = solve(x + y, y);
            if (a != INT_MAX) res = min(res, 1 + a);
            
            
            int b = solve(x + y, x + y);
            if (b != INT_MAX) res = min(res, 2 + b);
        } else {

            int c = solve(x, x);
            if (c != INT_MAX) res = min(res, 1 + c);
        }
        return dp[x][y]=res;
    }
    
    int minSteps(int n) {
        m = n;
        dp.resize(2000, vector<int>(2000, -1));
        return solve(1, 0);
    }
};
