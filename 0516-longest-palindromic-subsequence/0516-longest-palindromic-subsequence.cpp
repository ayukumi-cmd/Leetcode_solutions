


class Solution {
public:
      int lcs(string& s1,string& s2,int m,int n,vector<vector<int>>&dp){
       if(m==0|| n==0) dp[m][n]=0;
       if(dp[m][n]!=-1) return dp[m][n];
    
       if(s1[m-1]==s2[n-1]){
           dp[m][n]=1+lcs(s1,s2,m-1,n-1,dp);
       }
       else {
           dp[m][n]=max(lcs(s1,s2,m-1,n,dp),lcs(s1,s2,m,n-1,dp));
       }
       return dp[m][n];
      }
     
    int longestPalindromeSubseq(string s1) {
        int n=s1.size();
        string text1=s1;
        reverse(s1.begin(), s1.end());
        string text2=s1;

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return lcs(text1,text2,n,n,dp);
    }
};