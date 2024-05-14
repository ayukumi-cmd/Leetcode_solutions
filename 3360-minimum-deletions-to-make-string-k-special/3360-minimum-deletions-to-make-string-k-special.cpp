class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int >t(26);
        for(int i=0; i<word.size(); i++){
            t[word[i]-'a']++;
        }
        sort(t.begin(), t.end());
        vector<vector<int>>dp(26 , vector<int>(26, -1));
        int ans=func(0, 25 , k, t, dp);
        return ans;
    }
    int func(int i, int j, int k, vector<int>t,  vector<vector<int>>&dp){
        if(i==j) return 0;
        if(t[j]-t[i]<=k) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
       dp[i][j]=  min(t[i]+func(i+1, j, k, t,dp), t[j]-t[i]-k+ func(i, j-1, k, t,dp));
       return dp[i][j];
    }
};