class Solution {
public:
    
     vector<vector<int>>dp;
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int n, int prev1, int prev2, bool swap)
    {
        if(i == n)
            return 0;

        
        if(dp[i][swap] != -1)
            return dp[i][swap];
        
        int ans = INT_MAX;
        
        // no swaps have been made
        
        if(nums1[i] > prev1 && nums2[i] > prev2)
        {
            ans = min(ans, solve(nums1, nums2, i + 1, n, nums1[i], nums2[i], false));
        }
        
        // swaps have been made
        
        if(nums1[i] > prev2 && nums2[i] > prev1)
        {
            ans = min(ans, 1 + solve(nums1, nums2, i + 1, n, nums2[i], nums1[i], true));
        }
        
        // store in dp
        
        return dp[i][swap] = ans;
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        
       dp.assign(n+1, vector<int>(2,-1));
        
        return solve(nums1, nums2, 0, n, -1, -1, false);
    }
};