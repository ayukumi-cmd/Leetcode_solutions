class Solution {
public:
    vector<int>kmp(string s){
        vector<int>lps(s.size(), 0);
        for(int i=1; i<lps.size(); i++){
            int prev_idx=lps[i-1];
            while(prev_idx>0 and s[i]!=s[prev_idx]){
                prev_idx= lps[prev_idx-1];
            }
            lps[i]=prev_idx+(s[i]==s[prev_idx]?1:0);
        }
       return lps;
    }
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        vector<int>lps= kmp(word);
        int maxlps=lps[n-1];
        while(maxlps>0 and (n-maxlps)%k!=0){
            maxlps= lps[maxlps-1];
        }   
        if((n-maxlps)%k==0){
            return (n-maxlps)/k;
        }
        else{
           return (n/k)+(n%k==0?0:1);
        }
     
    }
};