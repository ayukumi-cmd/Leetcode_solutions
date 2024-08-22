class Solution {
public:
    int n; 
    vector<vector<int>>dp;
    int solve(int mask, int index){
        if(index==n+1){return 1;}
        if(dp[index][mask]!=-1){return dp[index][mask];}
        int ans=0;
        for(int i=1; i<=n; i++){
            int cmask=(1<<i)&(mask);
            if(cmask==0 and (i%index==0||index%i==0)){
            int new_mask= mask|(1<<i);
             ans+=solve(new_mask, index+1);
            }
        }
        return  dp[index][mask]=ans;
    }
    int countArrangement(int m) {
        n=m; 
        dp.resize(n+1, vector<int>(1<<(n+1), -1));
        return solve(0, 1);
    }
};