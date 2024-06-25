class Solution {
public:
    string largestMerge(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        string ans = "";
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (s1.substr(i, n-i) > s2.substr(j, m-j)) {
                ans += s1[i];
                i++;
            } else {
                ans += s2[j];
                j++;
            }
        }

        while (i < n) {
            ans += s1[i];
            i++;
        }

        while (j < m) {
            ans += s2[j];
            j++;
        }

        return ans;
    }
};
