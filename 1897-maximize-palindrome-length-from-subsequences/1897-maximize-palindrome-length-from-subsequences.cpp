

class Solution {
public:
    vector<vector<int>> memo;
    int res = INT_MIN;

    int dp(string &s1, int i, int j, int size1, int n) { 
        if(i>j){return 0;}
        if (i==j) return 1;

        if (memo[i][j] != -1) return memo[i][j];
        
        if (s1[i] == s1[j]) {
            int ans = 2+ dp(s1, i + 1, j - 1, size1, n);
            memo[i][j] = ans;
            if (i < size1 && j >= size1) {  // Ensure palindrome crosses between word1 and word2
                res = max(res, ans);
            }
        } else {
            memo[i][j] = max(dp(s1, i + 1, j, size1, n), dp(s1, i, j - 1, size1, n));
        }

        return memo[i][j];
    }
    
    int solve(string s, string x) {   
        string total = s + x;
        int size1 = s.length(); 
        int n = total.length();
        
        memo.resize(n, vector<int>(n, -1));
        dp(total, 0, n - 1, size1, n);
        
        return res == INT_MIN ? 0 : res ;  // Multiply by 2 to account for both halves of the palindrome
    }

    int longestPalindrome(string word1, string word2) {
        return solve(word1, word2);
    }
};

