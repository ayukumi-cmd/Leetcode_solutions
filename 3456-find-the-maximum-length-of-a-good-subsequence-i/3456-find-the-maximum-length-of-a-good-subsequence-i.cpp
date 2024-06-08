// class Solution {
// public:
//     vector<vector<long long>> memo; // Memoization table

//     long long solve(vector<int>& nums, long long k, long long len, long long idx) {
//         long long n = nums.size();
//         if (idx == n) {
//             return len; // Base case: end of array
//         }

//         // If already computed, return memoized value
//         if (memo[idx][k] != -1) {
//             return memo[idx][k];
//         }

//         // Case 1: Include the current element
//         long long include = solve(nums, k, len + (k > 0), idx + 1);

//         // Case 2: Exclude the current element
//         long long exclude = solve(nums, k - (nums[idx] != nums[idx + 1]), len, idx + 1);

//         // Update memoization table
//         memo[idx][k] = max(include, exclude);

//         return memo[idx][k];
//     }

//     int maximumLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         memo.assign(n + 1, vector<long long>(n + 1, -1)); // Initialize memoization table with -1
//         return solve(nums, k, 0, 0);
//     }
// };

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, k, i, dp));
        }
        
        return ans;
    }
    
private:
    int solve(vector<int>& nums, int k, int idx, vector<vector<int>>& dp) {
        int n = nums.size();
        if (idx == n) {
            return 0;  // Base case: reached end of array
        }
        
        if (dp[idx][k] != -1) {
            return dp[idx][k];  // Return memoized result if available
        }
        
        int ans = 1;  // Current element alone forms a valid subsequence
        
        for (int i = idx + 1; i < n; i++) {
            int length = 0;
            if (nums[idx] != nums[i] && k > 0) {
                // Different elements, use a replacement
                length = 1 + solve(nums, k - 1, i, dp);
            } else if (nums[idx] == nums[i]) {
                // Same elements, no replacement needed
                length = 1 + solve(nums, k, i, dp);
            }
            ans = max(ans, length);
        }
        
        dp[idx][k] = ans;  // Memoize the result
        return ans;
    }
};