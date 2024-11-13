class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
           
            auto it1 = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto it2 = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);

         
            cnt += (it2 - it1);
        }

        return cnt;
    }
};
