class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int result = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = max(result, findLengthHelper(nums1, nums2, i, j, memo));
            }
        }

        return result;
    }

private:
    int findLengthHelper(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& memo) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int length = 0;
        if (nums1[i] == nums2[j]) {
            length = 1 + findLengthHelper(nums1, nums2, i + 1, j + 1, memo);
        }

        memo[i][j] = length;
        return length;
    }
};

