class Solution {
public:
    int end = 0;
    int k = 0;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int start, int steps) {
        if (steps == k) {
            return start == end ? 1 : 0;
        }

    


       
        if (dp[start + 1000][steps] != -1) {
            return dp[start + 1000][steps];
        }

        int left = solve(start - 1, steps + 1);
        int right = solve(start + 1, steps + 1);

        int ans = (left + right) % mod;
        dp[start + 1000][steps] = ans;

        return ans;
    }

    int numberOfWays(int startPos, int endPos, int ki) {
        end = endPos;
        k = ki;


        dp.resize(3001, vector<int>(k + 1, -1));

        return solve(startPos, 0);
    }
};

