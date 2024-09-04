class Solution {
public:
    vector<vector<int>> memo;
    int dp(string &s1, string &s2,int i,int j)
    { 

        if(i<0  || j<0) return 0;

        if(memo[i][j]!=-1) return memo[i][j];
        int ans=INT_MAX;
        if(s1[i]==s2[j]){
            ans=1+dp(s1,s2,i-1,j-1);
        }
        else {
            
            return memo[i][j]= max(dp(s1,s2,i-1,j),dp(s1, s2,i,j-1));
        }
        return memo[i][j]=ans;
    }
    int minInsertions(string s) 
    {   
        memo.resize(s.length()+2,vector<int>(s.length()+2,-1));
        string t =s; int n= s.length();
        reverse(t.begin(),t.end());
        return n-dp(s,t,n-1,n-1);
    }
};