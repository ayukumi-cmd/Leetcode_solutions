class Solution {
public:
    int m,d;
    vector<vector<int>>dp;
    bool solve(int mask, int score, int k, vector<int>&nums){
    if(k==1){return true;}
    if(dp[k][mask]!=-1){return dp[k][mask];}
    bool ans=false;
    for(int i=0; i<nums.size(); i++){
        int cmask= 1<<i;
        if((cmask&mask)==0){
            if(score+nums[i]==d){
                return dp[k][mask]= solve(mask|cmask,0,k-1, nums);
            }
            else if(score+nums[i]<d){
               ans|=solve(mask|cmask, score+nums[i], k, nums);
            }
        }
    }
    return dp[k][mask]=ans;
    }
   bool canPartitionKSubsets(vector<int>& nums, int k) {
     int sum=0; 
     for(int i=0; i<nums.size(); i++){
        sum+=nums[i];
     }
     if(sum%k!=0){return false;}
     d= sum/k;

    // if((m*(m+1))/2 < d) return false;
    dp.assign(k+1, vector<int>(1<<(nums.size()), -1));
     return solve(0, 0, k, nums);
    }
}; 