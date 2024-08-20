class Solution {
public:
    vector<vector<int>> dp;
    vector<int> p;
    int n;

    int solve(vector<pair<int, int>> a[], int t, int q) {
        if (t < 0) return INT_MAX;
        if (q == n - 1) return p[q];
        if (dp[q][t] != -1) return dp[q][t];

        int ans = INT_MAX;
        for (auto& x : a[q]) {
            int res = solve(a, t - x.second, x.first);
            if (res != INT_MAX) {
                ans = min(ans, res + p[q]);
            }
        }

        return dp[q][t] = ans;
    }

    int minCost(int t, vector<vector<int>>& g, vector<int>& passing_fee) {
        n = passing_fee.size();
        p = passing_fee; 

        dp.assign(n, vector<int>(t + 1, -1)); 

        vector<pair<int, int>> a[n];
        for (auto& x : g) {
            a[x[0]].push_back({x[1], x[2]});
            a[x[1]].push_back({x[0], x[2]});
        }

        int ans = solve(a, t, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};
