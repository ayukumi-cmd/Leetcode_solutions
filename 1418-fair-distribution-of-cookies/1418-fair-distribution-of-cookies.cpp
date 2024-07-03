
class Solution {
public:
    vector<int> subsetSum;
    vector<vector<int>> memo;
    
    int solve(int child, int mask, int k, int n) {
        if (child == k) return (mask == (1 << n) - 1) ? 0 : INT_MAX;
        if (memo[child][mask] != -1) return memo[child][mask];

        int res = INT_MAX;
        for (int submask = mask; submask < (1 << n); submask = (submask + 1) | mask) {
            res = min(res, max(subsetSum[submask ^ mask], solve(child + 1, submask, k, n)));
        }
        return memo[child][mask] = res;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        subsetSum.resize(1 << n, 0);
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    subsetSum[mask] += cookies[i];
                }
            }
        }

        memo = vector<vector<int>>(k, vector<int>(1 << n, -1));
        return solve(0, 0, k, n);
    }
};
