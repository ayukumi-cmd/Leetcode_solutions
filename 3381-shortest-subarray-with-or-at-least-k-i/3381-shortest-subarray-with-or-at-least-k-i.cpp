class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int op = 0;
            for(int j=i;j<nums.size();j++){
                op |= nums[j];
                if(op>=k){
                    ans = min(ans, j-i+1);
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};