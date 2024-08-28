class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int target = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates for the second element
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    // Skip duplicates for the third element
                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return ans;
    }
};
