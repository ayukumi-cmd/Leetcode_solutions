class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xori=0;
        int n= nums.size();
        for(int i=0; i<n; i++){
          xori^=nums[i];
        }
        vector<int>ans;
        int k=pow(2, maximumBit); k--; 
        for(int i=0; i<n; i++){
           int res=xori|k;
           int res2=res^xori;
           ans.push_back(res2);
           xori^=nums[n-i-1];
        }
        return ans;
    }
};