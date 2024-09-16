class Solution {
public:
    vector<int> kmp(string s) {
        vector<int> lps(s.size(), 0);
        for (int i = 1; i < lps.size(); i++) {
            int prev_idx = lps[i - 1];
            while (prev_idx > 0 && s[i] != s[prev_idx]) {
                prev_idx = lps[prev_idx - 1];
            }
            lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1 : 0);
        }
        return lps;
    }
    int repeatedStringMatch(string a, string b) {
        int n= a.length(); 
        int m= b.length(); 
        string neww;
        int repeat=m/n ; 
        if(m%n){repeat++;}; 
        for(int i=0; i<repeat; i++){neww+=a;}

        vector<int>match= kmp(b+'#'+neww);

        for(int i=m+1; i<match.size(); i++){
            if(match[i]==m){return repeat;}
        }
        neww+=a;
        vector<int>match2= kmp(b+'#'+neww);
        for(int i=m+1; i<match2.size(); i++){
            if(match2[i]==m){return repeat+1;}
        }
        return -1;
    }
};