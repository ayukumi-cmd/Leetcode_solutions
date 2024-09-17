class Solution {
public:
int dp[1001][1001];
int solve(vector<int>&nums,int i,int j,vector<int>&pre){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i+1==j) return dp[i][j] = max(nums[i],nums[j]);
    int c1 = (pre[j]-pre[i])-solve(nums,i+1,j,pre);
    int c2 = (pre[j-1]-(i==0?0:pre[i-1]))-solve(nums,i,j-1,pre);
    return dp[i][j] = max(c1,c2);
}
int stoneGameVII(vector<int>& nums) {
    int n = nums.size();
    memset(dp,-1,sizeof(dp));
    vector<int>pre(n);
    pre[0] = nums[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+nums[i];
    }
    return solve(nums,0,n-1,pre);
}
};