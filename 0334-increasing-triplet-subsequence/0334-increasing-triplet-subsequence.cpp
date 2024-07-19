class Solution {
public:

    bool solve(vector<int>&nums){
        int min1= nums[0];
        int min2= INT_MAX;
        int n= nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<min1){
                min1= nums[i];
            }

            if(nums[i]>min1){
                min2= min(min2, nums[i]);
            }
            if(nums[i]>min2){
                return true;
            }
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        int n= nums.size();

        if(n<=2){return false;}
        return solve(nums);
    }
};