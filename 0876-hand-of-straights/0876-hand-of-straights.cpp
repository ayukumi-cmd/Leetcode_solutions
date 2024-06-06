class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        for (int num : nums) {
            if (mp[num] == 0) {
                continue;
            }

            for (int i = 0; i < k; i++) {
                if (mp[num + i] == 0) {
                    return false;
                }
                mp[num + i]--;
            }
        }
        
        return true;
    }
};
