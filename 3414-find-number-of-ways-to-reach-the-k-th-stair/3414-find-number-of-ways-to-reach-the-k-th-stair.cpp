

class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int k, int idx, int forw, int back, int jump, int neg) {

        if (idx > k + 1) {
            return 0;
        }

        if (dp[forw][back][neg] != -1) {
            return dp[forw][back][neg];
        }

        int ans = 0;
        if (idx == k) {
            ans+=1;
        }
        if (neg == 1 && idx > 0) { 
            ans += solve(k, idx - 1, forw,back+1,jump, 0);
        }
        ans += solve(k, idx + (1 << jump), forw+1,back, jump + 1, 1); 

        dp[forw][back][neg]= ans;
        return ans;
    }

    int waysToReachStair(int k) {
        dp.assign(33, vector<vector<int>>(33, vector<int>(2, -1))); 
        return solve(k, 1, 0,0, 0, 1);
    }
};
