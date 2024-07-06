class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> dp;
        int maxLen = 1;
        
        for (int num : arr) {
            if (dp.count(num - difference)) {
                dp[num] = max(dp[num], dp[num - difference] + 1);
            } else {
                dp[num] = 1;
            }
            maxLen = max(maxLen, dp[num]);
        }
        
        return maxLen;
    }
};