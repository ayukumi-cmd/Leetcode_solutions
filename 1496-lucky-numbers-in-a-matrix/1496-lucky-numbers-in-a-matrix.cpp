class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int el = nums[i][j];
                bool f = true;

                for (int k = 0; k < m; k++) {
                    if (el > nums[i][k]) {
                        f = false;
                        break;
                    }
                }

                for (int k = 0; k < n; k++) {
                    if (el < nums[k][j]) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    ans.push_back(el);
                }
            }
        }
        return ans;
    }
};
