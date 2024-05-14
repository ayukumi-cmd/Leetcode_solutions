class Solution {
    int solve(vector<int>& houses, int k, int currSt, int idx, vector<int>& prefixSum, vector<vector<vector<int>>>& dp) {
        if (idx >= houses.size()) {
            if (k == 0) return 0;
            return INT_MAX;
        }
        if (k <= 0) return INT_MAX;

        if (dp[currSt][idx][k] != -1) return dp[currSt][idx][k];

        int mid = (currSt + idx) / 2, lc = mid - currSt+1, rc = idx - mid;
        long leftSum = prefixSum[mid] - ((currSt>0)?prefixSum[currSt-1]:0);
        long rightSum = prefixSum[idx] - ((mid>=0)?prefixSum[mid]:0);
        long dist = houses[mid] * lc - leftSum + rightSum - houses[mid] * rc;

        long close = dist + solve(houses, k - 1, idx + 1, idx + 1, prefixSum, dp);
        long opn = solve(houses, k, currSt, idx + 1, prefixSum, dp);

        dp[currSt][idx][k] = min(opn, close);
        return dp[currSt][idx][k];
    }

public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        if (k >= n) return 0;

        sort(houses.begin(), houses.end());

        vector<int> prefixSum(n , 0);
        prefixSum[0]=houses[0];
        for (int i = 1; i <n; i++) {
            prefixSum[i] = houses[i ] + prefixSum[i - 1];
        }

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(k + 1, -1)));

        return solve(houses, k, 0, 0, prefixSum, dp);
    }
};
