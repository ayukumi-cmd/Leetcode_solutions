class Solution {
public:
    string getSmallestString(string s, int k) {
        int  n= s.size();
        string ans;
        for(int i=0; i<n; i++){
            if(k>=min(((26-(s[i]-'a'))%26), s[i]-'a')){
                ans+='a';
                k-=min((26-(s[i]-'a')),s[i]-'a')%26;
            }
            else {
                ans+=((s[i]-'a')-k+'a');
                k=0;
                break;
            }
        }
        for(int i=ans.size(); i<s.size(); i++){
            ans+=s[i];
        }
        return ans;
    }
};