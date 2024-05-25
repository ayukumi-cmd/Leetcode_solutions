class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size(), maxx = 0;
        string ans="";
        unordered_map<char, int> mp;
        
        for(auto &ch: s){
            mp[ch]++;
            maxx = max(maxx, mp[ch]);
        }
        
        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            
            if(mp[ch] == maxx){
                ans = ch + ans;
                mp[ch]--;
            }      
        }
        
        return ans;
    }
};