

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        if (n != t.size()) {
            return false; 
        }

        unordered_map<int, int> mp; 

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int shift = (t[i] - s[i] + 26) % 26;

                int totalShift = shift + 26 * mp[shift]; 

                if (totalShift > k) {
                    return false;
                }

                mp[shift]++; 
            }
        }

        return true; 
    }
};
