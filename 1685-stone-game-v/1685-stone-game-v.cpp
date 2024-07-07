class Solution {
public:
    vector<int>sum;
    vector<vector<int>>dp;
    int solve(int s, int e , vector<int>&stone){
        if(s>=e){
            return 0;
        }
        if(dp[s][e]!=-1){return dp[s][e];}
        int res= INT_MIN;
        for(int i=s; i<=e-1; i++){
            int sum_left=sum[i]-sum[s]+stone[s];
            int sum_right=sum[e]-sum[i];
            int ans=0;
            if(sum_left>sum_right){
                ans+=sum_right;
                ans+=solve(i+1, e, stone);
            }
            else if(sum_right>sum_left){
                ans+=sum_left;
                ans+=solve(s, i, stone);
            }
            else{
                ans+=sum_left;
                int maxi= max(solve(i+1, e , stone), solve(s, i, stone));
                ans+=maxi;
            }
            res= max(res, ans);
        }

        return dp[s][e]=res;
    }
    int stoneGameV(vector<int>& stone) {
        int n= stone.size();
        int add=0;
        for(auto it:stone){
            add+=it;
            sum.push_back(add);
        }
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, stone);
    }
};