class Solution {
public:
    vector<int>dp;
    bool solve(string s , set<string>&word, int idx){
        if(idx==s.length()){return 1;}
        if(dp[idx]!=-1){return dp[idx];}
         string temp;
        for(int i=idx; i<s.length(); i++){
            temp+=(s[i]);
            if((word.find(temp)!=word.end()) and solve(s, word, i+1)){return dp[idx]=1;}
        }
        return dp[idx]=0;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        dp.assign(s.length()+1, -1);
        for(int i=0; i<wordDict.size(); i++){st.insert(wordDict[i]);}
        return solve(s,st, 0);
    }
};