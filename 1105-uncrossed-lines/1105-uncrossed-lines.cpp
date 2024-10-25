class Solution {
public:

    int solve(vector<int>&nums1, vector<int>&nums2, int i, int j,vector<vector<int>>& dp){
        if(i==0 ||j==0){
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j]; 

 
        int ans= 0;
        if(nums1[i-1] == nums2[j-1]){
           ans=max(ans, 1+solve(nums1, nums2, i-1, j-1,dp));
        }
        else {
        ans=max(ans,  solve(nums1, nums2, i-1,j, dp));
        ans=max(ans, solve(nums1, nums2, i, j-1, dp));
        }


          return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size(); 
        int m=nums2.size(); 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 

        return solve(nums1, nums2,n, m,dp);
    }
};