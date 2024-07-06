class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k , vector<int>(k , 0));
        int ans=0;
        for(int i=0;  i<nums.size(); i++){
            int rem= nums[i]%k;

            for(int prev= 0;prev<k; prev++){
                dp[rem][prev]=max(dp[rem][prev], 1+dp[prev][rem]);
                ans= max(ans, dp[rem][prev]);
            }
        }
        return ans;
    }
};