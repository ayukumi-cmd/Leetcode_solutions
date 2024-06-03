class Solution {

public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(), res, l = -1, r, b, and_val, new_and_val;
        and_val = res = INT_MAX;

        vector<vector<int>> bits_count(n + 1, vector<int>(31, 0));

        for (r = 0; r < n; r++) {
            for (b = 0; b < 31; b++) {
                if (nums[r] & (1 << b)) {
                    bits_count[r + 1][b] = bits_count[r][b] + 1;
                }
            }
            if (nums[r] <= k) {
                res = min(res, k - nums[r]);
                l = r;
                and_val = INT_MAX;
                continue;
            }
            and_val = and_val & nums[r];
            while (and_val < k && l < r - 1) {
                l++;
                
                new_and_val = 0;
                for (b = 0; b < 31; b++) {
                    if (bits_count[r + 1][b] - bits_count[l + 1][b] == r - l) {
                        new_and_val = new_and_val ^ (1 << b);
                    }
                }
                res = min(res, abs(and_val - k));
                and_val = new_and_val;
            }
            res = min(res, abs(and_val - k));
        }

        return res;
    }
};
