
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return true;
            if(nums[mid]==nums[l] and nums[l]==nums[r]){
                r--; 
                l++; continue;
            }
            if(nums[mid] <=nums[r]) {
                if(target > nums[mid] and target <= nums[r]) l = mid + 1;
                else r = mid - 1;   
            }
            else {
                if(target < nums[mid] and target >= nums[l]) r = mid - 1;
                else l = mid + 1;
            }
        } 
        return false;
    }
};