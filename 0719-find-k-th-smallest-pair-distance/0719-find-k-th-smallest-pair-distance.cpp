class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int ans=0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 0;
            int i = 0, j = 0;

            while (i < n) {
                while (j < n && nums[j] <= nums[i] + m) {
                    ++j;
                }
                cnt += j - i - 1;
                ++i;
            }

            if (cnt < k) { 
                l = m + 1;
            } else {
                ans=m;
                r = m - 1;
            }
        }
        

        return ans;
    }
};
