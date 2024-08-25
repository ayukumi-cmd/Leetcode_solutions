
class Solution {
public:
    
    int kadanesMax(vector<int>&nums){
        int ans=0, sum=0;
         for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans, sum);
            if(sum<0){
                sum=0;
            }
         }
         if(ans==0){
            return *max_element(nums.begin(), nums.end());
         }
         else return ans;
    }
    int kadanesMin(vector<int>&nums){
        int ans=0, sum=0;
         for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            ans=min(ans, sum);
            if(sum>0){
                sum=0;
            }
         }
         if(ans==0){
            return *min_element(nums.begin(), nums.end());
         }
         else return ans;
    }
    
   
        

    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int SUM = accumulate(begin(nums), end(nums), 0);
        
        int minSum = kadanesMin(nums);
        
        int maxSum = kadanesMax(nums);
        
        int circSum = SUM - minSum;
        
        if(maxSum > 0) {
            return max(maxSum, circSum);
        }
        
        return maxSum;
    }
};

