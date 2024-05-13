#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long> ans;
        long long n = nums.size();
        vector<pair<long long, long long>> vp(n);
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            vp[i].first = nums[i];
            vp[i].second = i;
            sum += nums[i];
        }
        sort(vp.begin(), vp.end());
        vector<long long> min_idx;
        for (long long i = 0; i < n; i++) {
            min_idx.push_back(vp[i].second);
        }
        vector<long long> vis(n, 0);
        long long s = 0;
        for (int i = 0; i < queries.size(); i++) {
            if (vis[queries[i][0]] == 0) {
                vis[queries[i][0]] = 1;
                sum -= nums[queries[i][0]];
            }
            long long j=s;
            long long x=0;
            while( j <  (long long)min_idx.size() and x<queries[i][1]) {
                if (vis[min_idx[j]] == 0) {
                    vis[min_idx[j]] = 1;
                    sum -= nums[min_idx[j]];
                    x++; j++;
                }
                else {
               j++;
                }
            }
            s = j;
            ans.push_back(sum);
        }
        return ans;
    }
};
