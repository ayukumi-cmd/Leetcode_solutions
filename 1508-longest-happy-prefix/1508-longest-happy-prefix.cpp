class Solution {
public:
    vector<int> kmp(string s) {
        vector<int> lps(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            int prev_idx = lps[i - 1];
            while (prev_idx > 0 && s[i] != s[prev_idx]) {
                prev_idx = lps[prev_idx - 1];
            }
            if (s[i] == s[prev_idx]) {
                lps[i] = prev_idx + 1;
            }
        }
        return lps;
    }

    string longestPrefix(string s) {
        vector<int> lps = kmp(s);
        int len = lps[s.size() - 1]; 
        return s.substr(0, len);
    }
};
