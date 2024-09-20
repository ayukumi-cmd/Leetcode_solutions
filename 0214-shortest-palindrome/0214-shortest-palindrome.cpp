#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

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

    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<int> lps = kmp(s + "#" + s2);
        for(auto it:lps){cout<<it<<" "<<endl;}
        string ans;
        ans+=s2.substr(0, s.size()-lps[lps.size()-1]);
        ans+=s;
        return ans;
    }
};
