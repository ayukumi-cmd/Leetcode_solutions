class Solution {
public:
    vector<vector<int>>dp;
    long long solve(int i, int j , vector<int>&cuts){
        if(i>j){return 0;}
        if(dp[i][j]!=-1){return dp[i][j];}
        long long ans= INT_MAX;
        for(int k=i; k<=j ; k++){
           long long res= cuts[j+1]-cuts[i-1]+solve(i, k-1, cuts)+solve(k+1, j, cuts);
           ans= min(ans, res);
        }

        return dp[i][j]=ans;

    }
    int minCost(int n, vector<int>& cuts) {
        int m= cuts.size();
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        dp.resize(m+2, vector<int>(m+2, -1));
        return solve(1, m, cuts);
    }
};