#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> st;
    vector<vector<char>> mp;
    
    void solve(string &digits, int i, string s) {
        if (i == digits.size()) {
            st.push_back(s);
            return;
        }
        for (auto c : mp[digits[i] - '0']) { // Convert character to digit
            s.push_back(c);
            solve(digits, i + 1, s);
            s.pop_back(); // Backtrack to previous state
        }
    }

    vector<string> letterCombinations(string digits) {
         mp = vector<vector<char>>(10); // Initialize the mp vector with 10 empty vectors
        char c = 'a';
        int j = 0;
        for (int i = 2; i <= 9; i++) {
            if (i == 7 || i == 9) { // Digits 7 and 9 have 4 letters
                for (int k = 0; k < 4; k++) {
                    mp[i].push_back(c + j);
                    j++;
                }
            } else {
                for (int k = 0; k < 3; k++) {
                    mp[i].push_back(c + j);
                    j++;
                }
            }
        }
        if (digits.empty()) return {};

        solve(digits, 0, "");
        return st;
    }
};
