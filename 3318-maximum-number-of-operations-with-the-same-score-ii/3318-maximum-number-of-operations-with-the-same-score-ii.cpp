
// class Solution {
// public:
//     vector<vector<unordered_map<int, int>>> dp;
//     int solve(vector<int>& nums, int i, int j,int prev) {
//         if (i >=j) {
//             return 0;
//         }
//         if (dp[i][j].find(prev)!= dp[i][j].end()) {
//             return dp[i][j][prev];
//         }
//         int x = 0, y = 0, z = 0;
//         if (prev ==-1 || (prev == nums[i] + nums[j])) {
//             x = 1 + solve(nums, i + 1, j - 1, nums[i] + nums[j]);
//         }
//         if (prev == -1 || (prev == nums[i] + nums[i + 1] && i + 1 < nums.size())) {
//             y = 1 + solve(nums, i + 2, j, nums[i] + nums[i + 1]);
//         }
//         if (prev ==-1 || (prev == nums[j] + nums[j - 1] && j - 1 >= 0)) {
//             z = 1 + solve(nums, i, j - 2, nums[j] + nums[j - 1]);
//         }
//         return dp[i][j][prev] = max({x, y, z});
//     }
    
//     int maxOperations(vector<int>& nums) {
//         int n = nums.size();
//         dp.clear();
//         dp.resize(n, vector<unordered_map<int, int>>(n));
//         return solve(nums, 0, n - 1, -1);
        
//     }
// };


class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int>& nums, int i, int j, int prevSum) {
        if (i >= j) {
            return 0;
        }
        
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int x = 0, y = 0, z = 0;
        if (prevSum == -1 || (prevSum == nums[i] + nums[j])) {
            x = 1 + solve(nums, i + 1, j - 1, nums[i] + nums[j]);
        }
        if (i + 1 < nums.size() && (prevSum == -1 || (prevSum == nums[i] + nums[i + 1]))) {
            y = 1 + solve(nums, i + 2, j, nums[i] + nums[i + 1]);
        }
        if (j - 1 >= 0 && (prevSum == -1 || (prevSum == nums[j] + nums[j - 1]))) {
            z = 1 + solve(nums, i, j - 2, nums[j] + nums[j - 1]);
        }
        
        return dp[i][j] = max({x, y, z});
    }
    
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return solve(nums, 0, n - 1, -1);
    }
};
