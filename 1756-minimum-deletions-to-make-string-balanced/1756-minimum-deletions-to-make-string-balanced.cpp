class Solution {
public:
    vector<vector<int>>dp;
    string s="";
    int n;
    int solve(int i, int t)  
    {
        if(i==n) return 0;
        
        if(dp[i][t]!=-1) return dp[i][t];
        int ans=0;
        if(t)
        {
            if(s[i]=='b')
            {
             ans= solve(i+1,t);
            }
            
            else ans= solve(i+1,t)+1;
        }
        
        else
        {
            if(s[i]=='b')
            {
                ans= solve(i+1, 1);
                ans= min(ans, solve(i+1,0)+1);
            }
            else
            {
                ans= solve(i+1,t); 
            }
        }
        return dp[i][t]=ans;
    }
    
    int minimumDeletions(string s1) {
        s=s1;
        n=s.size();
        dp.resize(s1.size()+1, vector<int>(2, -1));
        return solve(0,0);
    }
};


