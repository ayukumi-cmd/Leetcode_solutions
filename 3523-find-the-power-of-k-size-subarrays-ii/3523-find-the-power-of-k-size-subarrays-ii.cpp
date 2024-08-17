class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        queue<int> q;
        int prev = nums[0];
        for (int i = 1; i < k; ++i) {
            if (nums[i]==prev+1) {
                prev = nums[i];
            } else {
                prev = nums[i];
                q.push(i - 1);
            }
        }

        vector<int> ans;
        if (q.empty()) {
            ans.push_back(nums[k - 1]);
        } else {
            ans.push_back(-1);
        }

        for (int i = k; i < nums.size(); ++i) {
            if (nums[i]== prev+1) {
                prev = nums[i];
            } else {
                prev = nums[i];
                q.push(i - 1);
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop();
            }
            if (q.empty()) {
                ans.push_back(nums[i]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
