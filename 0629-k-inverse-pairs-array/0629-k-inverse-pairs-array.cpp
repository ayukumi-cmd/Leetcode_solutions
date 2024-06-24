class Solution {
public:
    int mod =1e9 + 7;
    int solve(int n, int k , vector<vector<int>>&dp){
        if(k==0) return 1;
        if(n==0) return 0;
        if(dp[n][k]!=-1) return dp[n][k];
        int count=0;
        for(int i=0; i<= min(k, n-1); i++){
          count = (count%mod+ solve(n-1, k-i, dp)%mod)%mod;
        }
        dp[n][k]=count;
        return dp[n][k];
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
       return  solve(n, k, dp);
    }
};

// bhut hi ganda code hai time complexity o(n*k*max(n, k))
// optimize kiya ja skta hai but bhut mushkil hai mere liye to atleast 