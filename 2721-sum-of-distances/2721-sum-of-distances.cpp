class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long   n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<long long , vector<long long >> mp;
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& it : mp) {
            vector<long long >& indexes = it.second;
            long long left = 0;
            long long right = accumulate(indexes.begin(), indexes.end(), 0LL)-indexes[0];
            
            for (long long  i = 0; i < indexes.size(); i++) {
                long long  left_len = i;
                long long right_len = indexes.size() - 1 - i;
                
                ans[indexes[i]] = (left_len * indexes[i] - left) + (right - right_len * indexes[i]);

               
                if (i != indexes.size() - 1) {
                     left += indexes[i];
                    right -= indexes[i + 1];
                }
            }
        }

        return ans;
    }
};
