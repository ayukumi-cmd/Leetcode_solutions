
class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        if (s1.length() > s2.length()) return {};

        vector<int> s1Count(26, 0), s2Count(26, 0);
 
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        vector<int>ans;
        int i=0;
        for ( i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1Count == s2Count) ans.push_back(i);
         
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }
        if(s1Count==s2Count){ans.push_back(i);}

        return ans;
    }
};