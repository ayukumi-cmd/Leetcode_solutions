#include <unordered_map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dp;

    bool isok(const unordered_map<char, int>& mp) {
        int count = -1;
        for (const auto& p : mp) {
            if (count == -1) {
                count = p.second;
            } else if (count != p.second) {
                return false;
            }
        }
        return true;
    }

    int solve(const string& s, int i) {
        int n = s.length();
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        unordered_map<char, int> mp;
        int res = INT_MAX;

        for (int j = i; j < n; j++) {
            mp[s[j]]++;
            if (isok(mp)) {
                res = min(res, 1 + solve(s, j + 1));
            }
        }

        return dp[i] = res;
    }

    int minimumSubstringsInPartition(const string& s) {
        int n = s.length();
        dp.resize(n, -1);
        return solve(s, 0);
    }
};
