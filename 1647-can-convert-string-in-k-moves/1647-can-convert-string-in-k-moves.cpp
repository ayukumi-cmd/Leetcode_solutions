class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n=s.size();
        if(s.size()!=t.size()){return false;}
        int ans=0;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            if((s[i]-'a')>(t[i]-'a')){
                int x=(26-(s[i]-'a')+(t[i]-'a'));
                int y= (x+26*mp[x]);
                if(y>k){return false;}
                mp[x]++;
              
            }
            else if((s[i]-'a')<(t[i]-'a')){
                int x=(t[i]-'a')-(s[i]-'a');
                int y= (x+26*mp[x]);
                if(y>k){return false;}
                mp[x]++;
            }
        }

        return true;
    }
};