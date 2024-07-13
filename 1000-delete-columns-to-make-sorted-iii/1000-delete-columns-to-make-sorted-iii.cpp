class Solution {
public:
    bool check(string a, string b ){
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i]<=b[i]) continue;
            else return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        vector<string> v;
        int n = strs.size();
        int m=strs[0].size();
        for(int i=0;i<m;i++){
            string s;
            for(int j=0;j<n;j++){
                s+=strs[j][i];
            }
            v.push_back(s);
        }
        vector<int> dp(m+1,1);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++){
                if(check(v[j], v[i]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        return m-(*max_element(dp.begin(), dp.end()));
    }
};