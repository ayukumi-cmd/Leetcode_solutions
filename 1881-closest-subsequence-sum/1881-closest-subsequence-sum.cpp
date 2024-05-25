#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> get_subset_sums(const vector<int>& a, int l, int r) {
        int len = r - l + 1;
        vector<int> res;
        for (int i = 0; i < (1 << len); i++) {
            int sum = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    sum += a[l + j];
                }
            }
            res.push_back(sum);
        }
        return res;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> left = get_subset_sums(nums, 0, n / 2 - 1);
        vector<int> right = get_subset_sums(nums, n / 2, n - 1);
        
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        int ans = INT_MAX;
        
        for (int i : left) {
            auto low_iterator = lower_bound(right.begin(), right.end(), goal - i);
            if (low_iterator != right.end()) {
                ans = min(ans, abs(goal - (i + *low_iterator)));
            }
            if (low_iterator != right.begin()) {
                low_iterator--;
                ans = min(ans, abs(goal - (i + *low_iterator)));
            }
        }
        
        return ans;
    }
};
