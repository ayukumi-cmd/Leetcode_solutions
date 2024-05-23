class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int>mp1(26, 0);
        vector<int>mp2(26,0);
        for(int i=0; i<s.length(); i++){
        mp1[s[i]-'a']=i;
        mp2[t[i]-'a']=i;
        }

        int ans=0;
        for(int i=0; i<mp1.size(); i++){
            ans+=abs(mp1[i]-mp2[i]);
        }
        return ans;
    }
};