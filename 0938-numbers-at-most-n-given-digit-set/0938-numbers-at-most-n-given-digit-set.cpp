class Solution {
public:
    int dp[30][2];
    
    int solve(vector<string>& digits, const string &b, bool tight, int idx) {
        if (idx == b.length()) {
            return 1;
        }
        if (dp[idx][tight] != -1) {
            return dp[idx][tight];
        }

        int high = (tight ? (b[idx] - '0') : 9);
        int totalCount = 0;

        for (int i = 0; i < digits.size(); i++) {
            int currentDigit = digits[i][0] - '0';
            if (currentDigit <= high) {
                totalCount += solve(digits, b, tight && (currentDigit == high), idx + 1);
            } else {
                break;
            }
        }

        return dp[idx][tight] = totalCount;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string b = to_string(n);
        memset(dp, -1, sizeof(dp));
        
        int totalCount = 0;

        // Count all numbers of lengths less than the length of n
        for (int i = 1; i < b.length(); i++) {
            totalCount += pow(digits.size(), i);
        }

        // Count numbers of the same length as n
        totalCount += solve(digits, b, true, 0);

        return totalCount;
    }
};
