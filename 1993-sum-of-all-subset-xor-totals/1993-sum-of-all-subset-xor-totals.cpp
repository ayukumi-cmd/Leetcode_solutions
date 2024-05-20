class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       int n = nums.size();
       int powsize = pow(2, n);
       int ans = 0;
       for(int counter = 0; counter < powsize; counter++) {
           int res = 0;
           for(int j = 0; j < n; j++) {
               if((counter & (1 << j)) != 0) { 
                   res ^= nums[j];
               }
           }
           ans += res;
       } 
       return ans;
    }
};
