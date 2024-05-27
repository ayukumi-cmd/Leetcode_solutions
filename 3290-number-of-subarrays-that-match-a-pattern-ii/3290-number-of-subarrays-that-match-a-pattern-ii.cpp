#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> kmp(vector<int>&s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1; i < n; i++) {
            int prev_idx = lps[i - 1];
            while (prev_idx > 0 && s[i] != s[prev_idx]) {
                prev_idx = lps[prev_idx - 1];
            }
            lps[i] = prev_idx + ((s[i] == s[prev_idx]) ? 1 : 0);
        }
        return lps;
    }

   int countMatchingSubarrays(const vector<int>& nums, const vector<int>& pattern) {
    vector<int> nums2(nums.size() - 1);
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] > nums[i]) {
            nums2[i] = 1;
        } else if (nums[i + 1] == nums[i]) {
            nums2[i] = 0;
        } else {
            nums2[i] = -1;
        }
    }

    vector<int> s;
    for (auto i : pattern) {
        s.push_back(i);
    }
    s.push_back(5); // delimiter

    s.insert(s.end(), nums2.begin(), nums2.end());

    vector<int> res = kmp(s);
    int ans = 0;
    int patternSize = pattern.size();
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == patternSize) {
            ans++;
        }
    }
    return ans;
}

};