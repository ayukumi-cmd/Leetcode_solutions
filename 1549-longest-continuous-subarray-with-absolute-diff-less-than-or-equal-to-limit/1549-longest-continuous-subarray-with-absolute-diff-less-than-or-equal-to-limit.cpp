
class Solution {
public:
    long longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque, minDeque;
        int l = 0;
        long ans = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            while (!maxDeque.empty() && maxDeque.back() < nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[r]);

            while (!minDeque.empty() && minDeque.back() > nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[r]);

            // Shrink left pointer if it exceeds the limit
            while (maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[l]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[l]) {
                    minDeque.pop_front();
                }
                l++;
            }
            
            long currLength = r - l + 1;
            ans = max(ans, currLength);
        }
        
        return ans;
    }
};