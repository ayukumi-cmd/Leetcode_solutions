class Solution {
public:
    int k;
    int n;
    vector<int>a;
    long long dp[100001][5];
    long long solve(int idx, int t)
    {
        if(idx==n) return 0;
        if(dp[idx][t]!=-1) return dp[idx][t];
        long long ans=0;
        if(a[idx]>=k)ans=solve(idx+1,1);
        else
        {
            if(t>2)// if overpassed  the prev maxima  then build a new one
            {
                ans= solve(idx+1,1) + abs(k-a[idx]);
            }else
            {
                //relay on previous maxima
                ans= solve(idx+1,t+1);

                // build a current  maxima
                ans= min(ans, solve(idx+1,1) +abs(k-a[idx]));
             }
        }
        return dp[idx][t]=ans;
    }
    long long minIncrementOperations(vector<int>& nums, int k1) {
        k=k1;
        a=nums;
        n=a.size();
        memset(dp,-1,sizeof(dp));
        return min({solve(0,3), solve(1,3), solve(2,3)});
    }
};