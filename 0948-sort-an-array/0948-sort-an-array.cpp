class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> count(100001, 0);
        for(auto& num : nums) {
            count[num+50000] += 1;
        }

        int i = 0;
        for(int j = -50000; j <= 50000; ++j) {
            int cnt = count[j+50000];
            for ( int w = 0; w < cnt; ++w ) {
                nums[i++] = j;
            }
        }

        return nums;
    }
};