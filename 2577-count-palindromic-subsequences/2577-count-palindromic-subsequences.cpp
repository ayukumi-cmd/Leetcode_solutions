#define ll long long
ll dp[10001][11][11][6];
class Solution {
public:
    ll mod;
    ll dfs(int ind, int first, int second, int i, string &s) {
        if(i == 5){
           if(ind<=s.length()){return 1;}
           else {return 0;}
        } 
        if(ind == s.length()) return 0;
        if(dp[ind][first][second][i] != -1) return dp[ind][first][second][i];
        
        
        ll res = dfs(ind + 1, first, second, i, s);

        if(i == 0) {
            
            res += dfs(ind + 1, s[ind] - '0', second, i + 1, s);
            res %= mod;
        } else if(i == 1) {

            res += dfs(ind + 1, first, s[ind] - '0', i + 1, s);
            res %= mod;
        } else if(i == 2) {

            res += dfs(ind + 1, first, second, i + 1, s);
            res %= mod;
        } else if(i == 3) {
  
            if(s[ind] - '0' == second) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        } else if(i == 4) {
           
            if(s[ind] - '0' == first) {
                res += dfs(ind + 1, first, second, i + 1, s);
                res %= mod;
            }
        }
        return dp[ind][first][second][i] = res;
    }
    int countPalindromes(string s) {
        memset(dp, -1, sizeof dp); 
        mod = 1e9 + 7;
        return dfs(0, 10, 10, 0, s);
    }
};