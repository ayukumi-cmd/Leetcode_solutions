class Solution {
public:
    bool isfine(string s, int i) {
        unordered_map<char, int> mp1;
        for (int j = 0; j < i; j++) {
            mp1[s[j]]++;
        }
        unordered_map<char, int> mp2;
        for (int j = 0; j < s.length(); j++) {
            mp2[s[j]]++;
            if ((j + 1) % i == 0) {
                if (mp1 != mp2) {
                    return false;
                }
                mp2.clear();
            }
        }
        
        return mp2.empty(); // To ensure the last segment is also checked
    }

    int minAnagramLength(string s) {
        int n = s.length();
        int ans = n;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (isfine(s, i)) {
                    ans = min(ans,  i);
                }
                if (isfine(s, n / i)) {
                    ans = min(ans, n/i);
                }
            }
        }
        return ans;
    }
};
