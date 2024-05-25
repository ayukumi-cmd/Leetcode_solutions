class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0]+nums[1];
        int ct = 0;
        for(int i=0;i<n-1;i+=2){
            if(sum == (nums[i]+nums[i+1])) ct++;
            else break;
        }
        return ct;
    }
};