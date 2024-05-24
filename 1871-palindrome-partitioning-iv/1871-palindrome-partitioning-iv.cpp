
class Solution {
public:

    vector<vector<bool>> isPal;

    bool palindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    bool checkPartitioning(string s) {
        int n = s.length();
         isPal = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (palindrome(s, i, j)) {
                    isPal[i][j] = true;
                }
            }
        }

   for (auto i = 0; i < s.size()-2; ++i) {
       
            for (auto j = i+1; j < s.size()-1; ++j){
                if (isPal[0][i] && isPal[i+1][j] and isPal[j+1][n-1])
                    return true;
     }
    }
    return false;
    }
};
