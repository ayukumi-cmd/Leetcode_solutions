class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
      int n= nums.size();
      int ans=0;

      for(int i=0; i<32; i++){
        int count0=0; int count1=0;
         for(int j=0; j<n; j++){
            if(1<<i & nums[j]){count1++;}
            else count0++;
         }
         ans+=count1*count0;
      }

      return ans;
    }
};