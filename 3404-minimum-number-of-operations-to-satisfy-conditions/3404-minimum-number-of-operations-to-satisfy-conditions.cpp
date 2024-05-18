#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution {
public:
    int helper(vector<vector<int>>& g, map<pair<int, int>, int>& c, int i, int p, vector<vector<int>>& d) {
        if (i >= g[0].size()) return 0;

        if (d[i][p] != -1) return d[i][p];

        int ans = INT_MAX;

        for (int j = 0; j <= 9; j++) {
            if (j != p) {
                int ops = (int)(g.size() - c[{i, j}]) + helper(g, c, i + 1, j, d);
                ans = min(ans, ops);
            }
        }
        return d[i][p] = ans;
    }

    int minimumOperations(vector<vector<int>>& g) {
        map<pair<int, int>, int> c;

        for (int i = 0; i < g[0].size(); i++) {
            for (int j = 0; j < g.size(); j++) {
                c[{i, g[j][i]}]++;
            }
        }

        vector<vector<int>> dp(g[0].size(), vector<int>(12, -1));

        return helper(g, c, 0, 11, dp);
    }
};
