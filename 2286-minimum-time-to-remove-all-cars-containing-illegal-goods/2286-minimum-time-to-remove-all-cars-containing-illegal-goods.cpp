class Solution {
public:
    string s;
    int n;
    vector<vector<int>>dp;
    int rec(int level,int stage){
        if(level == n){
            return 0;
        }
        if(dp[level][stage] != -1) return dp[level][stage];
        
        int ans = INT_MAX;
        if(stage == 0){
            // stay in stage 0
            ans = 1+rec(level+1,0);
            
            // choose stage 1 
            if(s[level] == '0'){
                ans = min(ans,rec(level+1,1));
            }
            else{
                ans = min(ans,2+rec(level+1,1));
            }
            
            // choose stage 2
            ans = min(ans,1+rec(level+1,2));
        }
        if(stage == 1){
            // stay in stage 1
            if(s[level] == '0'){
                ans = min(ans,rec(level+1,1));
            }
            else{
                ans = min(ans,2+rec(level+1,1));
            }
            // choose stage 2
            ans = min(ans,1+rec(level+1,2));
        }
        if(stage == 2){
            // should stay in stage 2
            ans = min(ans,1+rec(level+1,2));
        }
        return dp[level][stage] = ans;
    }
    
    int minimumTime(string _s) {
         s = _s;
        n = s.size();
         dp.assign(n+1, vector<int>(3, -1));
        return rec(0,0);
    }
};