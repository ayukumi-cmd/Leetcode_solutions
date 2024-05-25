class Solution {
public:
    int maxSelectedElements(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        vector<int>nums;
        for(auto it:mp)
        {
            if(it.second>=2)
            {
                nums.push_back(it.first);
                nums.push_back(it.first);
            }
            else{
                nums.push_back(it.first);
            }
        }
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>dp(n+1,vector<int>(2,1));
        int ans=1;
        for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]){
            dp[i][0]=max(dp[i][0], dp[i-1][0]);
            dp[i][1]=max(dp[i][1], 1+dp[i-1][0]);
        }
        else if(nums[i]==nums[i-1]+1){
            dp[i][0]=max(dp[i][0], 1+dp[i-1][0]);
            dp[i][1]=max(dp[i][1], 1+dp[i-1][1]);
        }
        else if(nums[i]==nums[i-1]+2){
            dp[i][0]=max(dp[i][0], dp[i-1][1]+1);
        }
        ans= max({ans, dp[i][0], dp[i][1]});

       }

       return ans;
    }
};