
class Solution {
public:
int getMaximumConsecutive(vector<int>& nums) {
    int cnt=0,i=0;
    long long maxNum=0;
    sort(nums.begin(), nums.end());
    while (true){
       if (i<nums.size() && nums[i]<=maxNum+1)
            maxNum+=nums[i++];
       else{
            break;
       }
   }
   return maxNum+1 ;
}
};