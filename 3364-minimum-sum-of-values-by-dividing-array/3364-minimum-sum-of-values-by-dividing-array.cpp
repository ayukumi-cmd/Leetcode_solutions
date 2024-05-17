class Solution {
public:
    vector<vector<unordered_map<int,int>>> dp;
    int helper(vector<int> &nums,vector<int> &and1,int use,int i,int j,int n,int m){
        if(i>=n && j>=m){
            return 0;
        }
        if(i>=n || j>=m){
            return 1e9;
        }
        if(dp[i][j].count(use)){
            return dp[i][j][use];
        }
        int c1=1e9;
        if((use&nums[i])==and1[j]){
            c1=nums[i]+helper(nums,and1,((1<<21)-1),i+1,j+1,n,m);
        }
        int c2=helper(nums,and1,use&nums[i],i+1,j,n,m);
        return dp[i][j][use]=min(c1,c2);
        
    }
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n=nums.size();
        int m=andValues.size();
        dp.resize(nums.size()+2,vector<unordered_map<int,int>>(11));
        int ans=helper(nums,andValues,((1<<21)-1),0,0,n,m);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};