#define ll long long 
class Solution {
public:
    vector<vector<ll>>dp;
    ll solve(vector<int>&nums, ll i, ll sign ){
        ll n= nums.size();
        if(i==n){return 0;}
        if(dp[i][sign]!=-1){return dp[i][sign]; }
        ll ans=LLONG_MIN;

        

      
     
            if(sign==0){
              ans= max({ans , nums[i]+solve( nums, i+1, !sign ), nums[i]+solve(nums, i+1, 0 )});  
            }
            if(sign==1){
             ans= max({ans, -nums[i]+ solve(nums, i+1, !sign ), -nums[i]+solve(nums, i+1, 0 )});
            }
        

        return dp[i][sign]=ans;

    }
    long long maximumTotalCost(vector<int>& nums) {
         dp.clear();
         dp.resize(nums.size()+1, vector<ll>(3,-1));
        
         return solve(nums, 0, 0);
    }
};



