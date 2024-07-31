class Solution {
public:
    int n; 
    vector<int>dp;
    int solve(int x){
       if(x==n){return 1;}
       if(x>n){return 0;}
       if(dp[x]!=-1){
        return dp[x];
       }

       int take1=solve(x+1);
       int take2=solve(x+2);
       return dp[x]=take1+take2;
       

    }
    int climbStairs(int m) {
        n=m; 
        dp.resize(n+3, -1);
        return solve(0);
    }
};