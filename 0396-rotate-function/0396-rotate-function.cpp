class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int n= nums.size();

        int sum=0; 
        int first_val=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            first_val+=(i*nums[i]);
        }

        int ans= first_val ; 

        for(int i=0; i<n; i++){
             first_val= first_val +sum-n*(nums[n-i-1]);
            ans= max(ans,first_val);
        }

        return ans;
    }
};