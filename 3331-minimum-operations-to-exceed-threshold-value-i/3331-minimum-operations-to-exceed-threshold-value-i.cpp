class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int steps=0;
        for(int i=0; i<nums.size() ; i++){
          if(nums[i]>=k){
            break;
          }
          else steps++;
        }
        return steps;
    }
};