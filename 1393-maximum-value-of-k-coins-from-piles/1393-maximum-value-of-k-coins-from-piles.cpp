class Solution {
public:
    int solve(int r, vector<vector<int>> &piles, int k, vector<vector<int>> &dp)
{
    if (r == piles.size())
    {
        if(k == 0)
        {
            return 0;
        }
        return -1e9;
    }
    
    if(dp[r][k] != -1)
    {
        return dp[r][k];
    }
       
    int ans = solve(r + 1, piles, k, dp);
    int temp = 0;

    for (int i = 0; i < min((int)piles[r].size(), k); i++)
    {
        temp += piles[r][i];
        ans = max(ans, temp + solve(r + 1, piles, k - i - 1, dp));
    }

    return dp[r][k] = ans;
}

int maxValueOfCoins(vector<vector<int>> &piles, int k)
{
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(0, piles, k, dp);
}
};