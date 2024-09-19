class Solution {
public:
int countPalindromicSubsequence(string s) {
    int n = s.size();
    unordered_set<string> uniquePalindromes;

    for (char first = 'a'; first <= 'z'; ++first) {
        for (char second = 'a'; second <= 'z'; ++second) {
            bool firstFound = false, secondFound = false;

            for (int i = 0; i < n; ++i) {
                if (!firstFound && s[i] == first) {
                    firstFound = true;
                } else if (firstFound && !secondFound && s[i] == second) {
                    secondFound = true;
                } else if (firstFound && secondFound && s[i] == first) {
                    uniquePalindromes.insert(string(1, first) + string(1, second) + string(1, first));
                    break;
                }
            }
        }

    }
            return uniquePalindromes.size();
}

};