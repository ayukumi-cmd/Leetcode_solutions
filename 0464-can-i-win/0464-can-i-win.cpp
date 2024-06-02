class Solution {
public:
    int m,d;
    vector<vector<int>>dp;
    bool solve(int mask, int score, int player ){
    if(dp[player][mask]!=-1) return dp[player][mask];
    for(int i=0; i<m; i++){
        int cmask= 1<<i;
        if((cmask&mask)==0){
            if(score+i+1>=d ||solve(mask|cmask, score+i+1, player^1)==false){
                return dp[player][mask]=true;

            }
        }
    }
    return dp[player][mask]=false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m=maxChoosableInteger;
        d=desiredTotal;
        if((m*(m+1))/2 < d) return false;
        dp.assign(2, vector<int>(1<<m, -1));
        return solve(0, 0, 0);
    }
}; 