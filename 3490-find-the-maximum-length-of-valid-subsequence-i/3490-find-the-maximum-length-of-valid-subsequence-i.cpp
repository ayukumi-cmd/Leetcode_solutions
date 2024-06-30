class Solution {
public:
    
    int sameParity(vector<int>& nums){
        int n = nums.size();
        
          int even=0;
        if(nums[0] %2 == 0) even=1;
        
        for(int i=1;i<n;i++){
            int val = nums[i];
            
            if(val%2 == 1){
                even= even;
            }else{
                even = even+1;
            }
        }
        
        int odd =0;
        if(nums[0] %2 == 1) odd = 1;
        
        for(int i=1;i<n;i++){
            int val = nums[i];
            if(val%2 == 0){
                odd = odd;
            }else{
                odd= odd+1;
            }
        }
        
        return max(even, odd);
    }
    
    int alternatingParity(vector<int>& nums){
        int n = nums.size();
        
          int even=0; 
		  int odd=0; 
        
        if(nums[0] %2 == 0)even = 1;
        if(nums[0] %2 == 1)odd= 1;
        
        for(int i=1;i<n;i++){
            int val = nums[i];
            
            if(val%2 == 0){
                even = 1 + odd;
                odd = odd;
            }else{
                odd= 1 + even;
                even = even;
            }
        }
        
        return max(even, odd);
    }
    
    int maximumLength(vector<int>& nums) {
        return max(sameParity(nums), alternatingParity(nums));
    }
};