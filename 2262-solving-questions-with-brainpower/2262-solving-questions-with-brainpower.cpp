class Solution {
public:
    long long dp[100000];
    long long solve(vector<vector<int>> & questions, int index){
        if(index >= questions.size()) return 0;
        if(index == questions.size()-1) return dp[index] = questions[index][0];
        if(dp[index] != -1) return dp[index];
        long long ans = 0;
        long long right = questions[index][0]+solve(questions,index+1+questions[index][1]);
        long long left = solve(questions,index+1);
        ans = max(left,right);
        return dp[index] = ans;
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp,-1,sizeof(dp));
        dp[n-1] = questions[n-1][0];
    return solve(questions,0);
    }
};